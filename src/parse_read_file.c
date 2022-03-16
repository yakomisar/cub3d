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
		write(1, "Error: problem with file\n", 25);
	exit(0);
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
