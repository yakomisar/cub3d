#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
//# include "../minilibx_macos/mlx.h"
# include "../minilibx-linux/mlx.h"

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
    t_data          config;
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

int		ft_key_press(int keycode, t_raycast *rc);
int		ft_key_release(int keycode, t_raycast *rc);
void	ft_rotate_right_left(t_raycast *rc);
void	ft_forward_back(t_raycast *rc);
void	ft_left_right(t_raycast *rc);
void    ft_count_lines(t_raycast *rc);

#endif