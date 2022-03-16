#include "../inc/cub3d.h"

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

bool	check_plr(char a)
{
	return (a == 'N' || a == 'S' || a == 'W' || a == 'E');
}