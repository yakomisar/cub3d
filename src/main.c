#include "../inc/cub3d.h"

void	free_and_exit(t_data *data, int flag)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	free(data);
	if (flag == 1)
		write(1, "Error\n", 6);
	exit(0);
}

void	init_data(t_data *data)
{
	data->ceiling = -10;
	data->floor = -10;
	data->file = NULL;
	data->map = NULL;
	data->ea = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
}

void	read_file(t_data *data, char *map)
{
	char	*save;
	char	*addition;
	int		fd;

	save = NULL;
	addition = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		free_and_exit(data, 1);
	while (get_next_line(fd, &save))
	{
		addition = data->file;
		data->file = ft_strjoin(addition, save);
		free(addition);
		free(save);
		addition = data->file;
		data->file = ft_strjoin(addition, "\n");
		free(addition);
	}
	addition = data->file;
	data->file = ft_strjoin(addition, save);
	free(addition);
	free(save);
	close(fd);
}

int	complete(t_data *data)
{
	if (data->ea && data->no && data->so && data->we)
	{
		return (1);
	}
	// if (data->ceiling != -10 && data->floor != -10 && \
	// 	data->ea && data->no && data->so && data->we)
	// {
	// 	return (1);
	// }
	return (0);
}

int	check_string(char c)
{
	if (c != ' ' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

int	check_value(char *param, int i, t_data *data)
{
	if ((data->file[i] == param[0]) && (data->file[i + 1] == param[1]))
	{
		if (data->file[i + 2] == ' ' || data->file[i + 2] == '\t')
			return (1);
		else
		{
			write(1, "Error: bad pathway\n", 19);
			exit(1);
		}
	}
	return (0);
}

void	parse_values(int *i, t_data *data, char **param)
{
	int	pos;

	pos = 0;
	if (*param)
	{
		write(1, "Error: parameter already exists\n", 32);
		exit(1);
	}
	while (data->file[*i] && (data->file[*i] == ' ' || data->file[*i] == '\t'))
		(*i)++;
	pos = *i;
	while (data->file[*i] && data->file[*i] != ' ' && data->file[*i] != '\n' && data->file[*i] != '\t')
		(*i)++;
	if (pos == (*i))
	{
		write(1, "Error: parameter is blank\n", 26);
		exit(1);
	}
	*param = ft_substr(data->file, pos, (*i) - pos);
}

int	to_hex(int r, int g, int b)
{
	write(1, "parse\n", 6);
	return (r << 16 | g << 8 | b);
}

bool	no_number(char a)
{
	return !(a >= '0' && a <= '9');
}

void	parse_color(int *i, t_data *data, char color)
{
	int			pos;
	long long	r;
	long long	g;
	long long	b;

	pos = *i;
	while (data->file[*i] && data->file[*i] != '\n' && (data->file[*i] == ' ' || data->file[*i] == '\t'))
		(*i)++;
	if (data->file[*i] == ',' || data->file[*i] == '\n')
	{
		write(1, "Error: comma or eof has been identified\n", 40);
		exit(1);
	}
	while (data->file[*i] && data->file[*i] != ',' && data->file[*i] != '\n')
	{
		if (no_number(data->file[*i]))
		{
			write(1, "Error: not a number\n", 20);
			exit(1);
		}
		(*i)++;
	}
	if (*i != pos)
		r = ft_atoi(ft_substr(data->file, pos, *i - pos));
	else
	{
		write(1, "Error: no arguments\n", 20);
		exit(1);
	}
	(*i)++;
	pos = *i;
	while (data->file[*i] && data->file[*i] != ',' && data->file[*i] != '\n')
	{
		if (no_number(data->file[*i]))
		{
			write(1, "Error: not a number\n", 20);
			exit(1);
		}
		(*i)++;
	}
	if (*i != pos)
		g = ft_atoi(ft_substr(data->file, pos, *i - pos));
	else
	{
		write(1, "Error: no arguments\n", 20);
		exit(1);
	}
	(*i)++;
	pos = *i;
	while (data->file[*i] && data->file[*i] != ',' && data->file[*i] != '\n')
	{
		if (no_number(data->file[*i]))
		{
			write(1, "Error: not a number\n", 20);
			exit(1);
		}
		(*i)++;
	}
	if (*i != pos)
		b = ft_atoi(ft_substr(data->file, pos, *i - pos));
	else
	{
		write(1, "Error: no arguments\n", 20);
		exit(1);
	}
	if (r > 255 || g > 255 || b > 255)
	{
		write(1, "Error: not an RGB\n", 18);
		exit(1);
	}
	if (color == 'F')
		data->floor = to_hex(r, g, b);
	else if (color == 'C')
		data->ceiling = to_hex(r, g, b);
}

int	check_color(char color, int i, t_data *data)
{
	write(1, "parsing\n", 8);
	if (data->file[i] == color)
	{
		
		if (data->file[i + 1] == ' ' || data->file[i + 1] == '\t')
			return (1);
		else
		{
			write(1, "Error: bad pathway for color\n", 19);
			exit(1);
		}
	}
	return (0);
}

void	get_features(int *i, t_data *data)
{
	while (data->file[*i] && (data->file[*i] == ' ' || data->file[*i] == '\t' || data->file[*i] == '\n'))
		(*i)++;
	if (check_value("NO", *i, data))
	{
		(*i) += 2;
		parse_values(i, data, &(data->no));
	}
	else if (check_value("SO", *i, data))
	{
		(*i) += 2;
		parse_values(i, data, &(data->so));
	}
	else if (check_value("WE", *i, data))
	{
		(*i) += 2;
		parse_values(i, data, &(data->we));
	}
	else if (check_value("EA", *i, data))
	{
		(*i) += 2;
		parse_values(i, data, &(data->ea));
	}
	else if (check_color('C', *i, data))
	{
		write(1, "parse C\n", 8);
		(*i) += 1;
		parse_color(i, data, 'C');
	}
	else if (check_color('F', *i, data))
	{
		write(1, "parse F\n", 8);
		(*i) += 1;
		parse_color(i, data, 'F');
	}
}

int	check_extension(t_data *data)
{
	if (ft_strncmp(&data->ea[ft_strlen(data->ea) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&data->no[ft_strlen(data->no) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&data->so[ft_strlen(data->so) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&data->we[ft_strlen(data->we) - 4], ".xpm", 4))
		return (1);
	return (0);
}

void	check_data(t_data *data)
{
	if (data->ea == NULL || data->no == NULL || data->so == NULL || data->we == NULL)
	{
		write(1, "Error: blank parameter\n", 23);
		exit(1);
	}
	if (access(data->ea, R_OK) != 0 || access(data->no, R_OK) != 0 || access(data->so, R_OK) != 0 || access(data->we, R_OK) != 0)
	{
		write(1, "Error: unable to get access to the textures\n", 44);
		exit(1);
	}
	if (check_extension(data))
	{
		write(1, "Error: incorrect extension in textures\n", 39);
		exit(1);
	}
}

int	get_size(char *str)
{
	int	i;
	int	size;
	int	symbol;

	i = 0;
	size = 0;
	symbol = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || (i == ft_strlen(str) - 1))
		{
			size++;
			symbol = 0;
		}
		// if ((i == ft_strlen(str) - 1) && !str[i + 1])
		// {
		// 	write(1, "Error: blanked lines should be removed\n", 39);
		// 	exit(1);
		// }
		// symbol++;
		i++;
	}
	return (size);
}

void	init_map(int i, t_data *data, int height)
{
	int	j;

	j = 0;
	data->map = (char **)malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{

		// data->map[i][j] = data->file[i];
		// if (data->file[i] == '\n')
		// 	j++;
		i++;
	}
}

int	check_n(int i, t_data *data, char **map_elem)
{
	int	start;

	start = i;
	while (data->file[i] && data->file[i] != '\n')
		++i;
	*map_elem = ft_substr(data->file, start, i - start);
	if (data->file[i] == '\n')
		++i;
	return (i);
}

int	check_size_map(int i, t_data *data)
{
	int	size;
	int	save;

	size = 0;
	save = 1;
	while (i < ft_strlen(data->file))
	{
		if (data->file[i] == '\n' || i == ft_strlen(data->file) - 1)
			++size;
		++i;
	}
	--i;
	while (i >= 0 && (data->file[i] == ' ' || data->file[i] == '\n'
			|| data->file[i] == '\t'))
	{
		--i;
		if (data->file[i] == '\n')
			++save;
	}
	return (size - save);
}

bool	check_s_t(char a, int check)
{
	if (check)
		return (a != ' ' && a != '\t');
	return (a == ' ' || a == '\t');
}

void	make_array_map(int i, t_data *data)
{
	int	save_i;
	int	size;
	int	j;

	j = 0;
	save_i = i;
	size = check_size_map(i, data);
	i = save_i;
	data->map = (char **)malloc(sizeof(char *) * (size + 2));
	while (i > 0 && data->file[i - 1] != '\n')
		--i;
	while (j < size + 1)
	{
		i = check_n(i, data, &data->map[j]);
		++j;
	}
	data->map[j] = NULL;
}

void	check_first_last_string(int j, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1' && check_s_t(data->map[j][i], 1))
		{
			write(1, "Error: parameters problem\n", 26);
			exit(1);
		}
		i++;
	}
}

bool	check_plr(char a)
{
	return (a == 'N' || a == 'S' || a == 'W' || a == 'E');
}

void	check_error(t_data *data, int j, int i)
{
	while (data->map[j][i])
	{
		if (data->map[j][i] && data->map[j][i] != '0'
			&& data->map[j][i] != '1' && check_s_t(data->map[j][i], 1)
			&& !check_plr(data->map[j][i]))
		{
			write(1, "Error: map error\n", 17);
			exit(1);
		}
		if (data->map[j][i] == '0')
		{
			if ((data->map[j - 1] && ft_strlen(data->map[j - 1]) < i)
				|| (data->map[j - 1][i] && check_s_t(data->map[j - 1][i], 0)))
			{
				write(1, "Error: map error\n", 17);
				exit(1);
			}
			if ((data->map[j + 1] && ft_strlen(data->map[j + 1]) < i)
				|| (data->map[j + 1][i] && check_s_t(data->map[j + 1][i], 0)))
			{
				write(1, "Error: map error\n", 17);
				exit(1);
			}
		}
		if (data->map[j][i] && check_plr(data->map[j][i]) && !data->plr_ch)
			data->plr_ch = data->map[j][i];
		else if (data->map[j][i] && check_plr(data->map[j][i]) && data->plr_ch)
		{
			write(1, "Error: map error\n", 17);
			exit(1);
		}
		i++;
		if ((check_s_t(data->map[j][i], 0) || data->map[j][i] == '\n'
			|| data->map[j][i] == '\0') && (data->map[j][i - 1] != '1'
			&& check_s_t(data->map[j][i - 1], 1)))
		{
			write(1, "Error: map error\n", 17);
			exit(1);
		}
	}
}

void	map_error(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	check_first_last_string(0, data);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && check_s_t(data->map[j][i], 0))
			i++;
		if (i == 0 && data->map[j][i] == '\0')
		{
			write(1, "Error: parameters problem\n", 26);
			exit(1);
		}
		if (data->map[j][i] && data->map[j][i] != '1')
		{
			write(1, "Error: map is open\n", 19);
			exit(1);
		}
		check_error(data, j, i);
		j++;
		if (!data->map[j + 1])
		{
			check_first_last_string(j, data);
			break ;
		}
	}
	if (!data->plr_ch)
	{
		write(1, "Error: map error\n", 17);
		exit(1);
	}
}

void	read_map(int i, t_data *data)
{
	while (data->file[i] && (data->file[i] == ' '
			|| data->file[i] == '\t' || data->file[i] == '\n'))
		++i;
	if (data->file[i] != '1' && data->file[i] != '0')
	{
		write(1, "Error: not an 1 an 0\n", 21);
		exit(1);
	}
	else
	{
		if (data->file[i] == '0')
		{
			write(1, "Error: map is open\n", 19);
			exit(1);
		}
		else
			make_array_map(i, data);
	}
	map_error(data);
}

void	parse_data(t_data *data)
{
	int	i;
	int	iter;

	i = 0;
	iter = 0;
	while (data->file[i])
	{
		if (complete(data))
			break ;
		get_features(&i, data);
		// if (check_string(data->file[i]))
		// {
		// 	write(1, "Error: bad symbols\n", 19);
		// 	exit(1);
		// }
		i++;
	}
	check_data(data);
	read_map(i, data);
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->plr_ch)
			{
				data->plr_x = j;
				data->plr_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	
	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
	{
		write(2, "Error: try ./cub3d <map_file.cub>\n", 34);
		return (1);
	}
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
		{
			write(1, "Error: unable to allocate memory\n", 33);
			exit(1);
		}
		init_data(data);
		read_file(data, argv[1]);
		parse_data(data);
		init_player(data);
		printf("%s\n", data->no);
		printf("%s\n", data->ea);
		printf("%s\n", data->so);
		printf("%s\n", data->we);
		printf("%d\n", data->floor);
		printf("%d\n", data->ceiling);
		printf("Player position. (%d,%d)", data->plr_x, data->plr_y);

	}
	return (0);
}