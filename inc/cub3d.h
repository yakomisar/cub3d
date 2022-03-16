#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
// # include "../minilibx-linux/mlx.h"


/* TO DELETE */

# include <stdio.h>

/* TO DELETE */


# define LEFT_KEY   65361
# define RIGHT_KEY   65363
# define W_KEY      119
# define S_KEY      115
# define D_KEY      100
# define A_KEY      97
# define ESC_KEY    65307

typedef struct s_data
{
    char    plr_ch;
    int     plr_x;
    int     plr_y;
    char	*no;
    char	*so;
    char	*we;
    char	*ea;
    char    *file;
    int		floor;
    int		ceiling;
    char	**map;
}	t_data;

typedef struct		s_texture
{
    int				texdir;
    double			wallx;
    int				texx;
    int				texy;
    double			step;
    double			texpos;
}					t_texture;

typedef struct		s_ray
{
    double			posx;
    double			posy;
    double			dirx;
    double			diry;
    double			planx;
    double			plany;
    double			raydirx;
    double			raydiry;
    double			camerax;
    int				mapx;
    int				mapy;
    double			sidedistx;
    double			sidedisty;
    double			deltadistx;
    double			deltadisty;
    int				stepx;
    int				stepy;
    int				hit;
    int				side;
    double			perpwalldist;
    int				lineheight;
    int				drawstart;
    int				drawend;
    double			movespeed;
    double			rotspeed;
    int				x;
    int				texture;
}					t_ray;

typedef struct		s_info
{
    void			*mlx_ptr;
    void			*mlx_win;
    void			*img;
    int				*addr;
    int				bits_per_pixel;
    int				line_length;
    int				endian;
    int				forward;
    int				back;
    int				left;
    int				right;
    int				rotate_left;
    int				rotate_right;
    int				width;
    int				height;
}					t_info;

typedef struct		s_raycast
{
    int				nblines;
    int				error;
    int				screenx;
    int				screeny;
    int				count;
    t_info			texture[4];
    t_info			data;
    t_ray			ray;
    t_texture		t;
    t_data          *config;
}					t_raycast;

void	ft_init(t_raycast *rc);
int		ft_mlx(t_raycast *rc);
void	ft_init_ray(t_raycast *rc);
void	ft_error(t_raycast *rc, char *str);
void	ft_calc_ray(t_raycast *rc);
void	ft_calc_step(t_raycast *rc);
int		ft_color_column(t_raycast *rc);
void	ft_draw_texture(t_raycast *rc, int x, int y);
int		ft_exit(t_raycast *rc);

/* Functions for parsing*/
int     get_next_line(int fd, char **line);
void	parse_values(int *i, t_data *data, char **param);
int     check_string(char c);
int     check_value(char *param, int i, t_data *data);
void    check_error(t_data *data, int j, int i);
int     check_extension(t_data *data);
int     check_n(int i, t_data *data, char **map_elem);
bool    check_plr(char a);
void	check_numbers(char **str);
void	get_values(char *str, char color, t_data *data);
void	parse_color(int *i, t_data *data, char color);
int     check_color(char color, int i, t_data *data);
int     check_size_map(int i, t_data *data);
bool	check_s_t(char a, int check);
void	check_first_last_string(int j, t_data *data);
void	make_array_map(int i, t_data *data);
void	map_error(t_data *data);
void	read_map(int i, t_data *data);
void	check_data(t_data *data);
void	get_features(int *i, t_data *data);
int     complete(t_data *data);
void	parse_data(t_data *data);
void	init_player(t_data *data);
void	init_data(t_data *data);
void	free_and_exit(t_data *data, int flag);
void	read_file(t_data *data, char *map);
/* End of functions for parsing*/

int		ft_key_press(int keycode, t_raycast *rc);
int		ft_key_release(int keycode, t_raycast *rc);
void	ft_rotate_right_left(t_raycast *rc);
void	ft_forward_back(t_raycast *rc);
void	ft_left_right(t_raycast *rc);
void    ft_count_lines(t_raycast *rc);

#endif