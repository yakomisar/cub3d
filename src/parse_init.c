#include "../inc/cub3d.h"

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
