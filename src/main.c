#include "../inc/cub3d.h"

int	check_string(char c)
{
	if (c != ' ' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

// bool	no_number(char a)
// {
// 	return !(a >= '0' && a <= '9');
// }

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
		printf("Player position. (%d,%d)\n", data->plr_x, data->plr_y);
		printf("Player: %c\n", data->plr_ch);
	}
	return (0);
}