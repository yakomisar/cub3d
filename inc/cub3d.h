#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	char	*file;
	char	**map;
	char	plr_ch;
	int		plr_x;
	int		plr_y;
}	t_data;

char	*ft_strcpy(char *dest, char *src);
int		get_next_line(int fd, char **line);
int		save_line(char **line, char **box);
char	*ft_strdup(const char *str);
char	*ft_strchr_cub(char *s, int c);

#endif