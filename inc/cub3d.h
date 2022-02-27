#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	char	**map;
}	t_data;



#endif