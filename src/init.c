//
// Created by matsony on 09.03.2022.
//

#include "../inc/cub3d.h"

void	ft_init_ray_sub(t_raycast *rc)
{
    if (rc->config->plr_ch == 'N')
        rc->ray.dirx = -1;
    if (rc->config->plr_ch == 'S')
        rc->ray.dirx = 1;
    if (rc->config->plr_ch == 'E')
        rc->ray.diry = 1;
    if (rc->config->plr_ch == 'W')
        rc->ray.diry = -1;
    if (rc->config->plr_ch == 'N')
        rc->ray.plany = 0.66;
    if (rc->config->plr_ch == 'S')
        rc->ray.plany = -0.66;
    if (rc->config->plr_ch == 'E')
        rc->ray.planx = 0.66;
    if (rc->config->plr_ch == 'W')
        rc->ray.planx = -0.66;
}

void	ft_init_ray(t_raycast *rc)
{
    rc->data.forward = 0;
    rc->data.back = 0;
    rc->data.left = 0;
    rc->data.right = 0;
    rc->data.rotate_right = 0;
    rc->data.rotate_left = 0;
    rc->ray.posx = (double)rc->config->plr_x + 0.5;
    rc->ray.posy = (double)rc->config->plr_y + 0.5;
    rc->ray.dirx = 0;
    rc->ray.diry = 0;
    rc->ray.planx = 0;
    rc->ray.plany = 0;
    ft_init_ray_sub(rc);
}

void	ft_calc_ray_sub(t_raycast *rc)
{
    if (rc->ray.raydiry == 0)
        rc->ray.deltadistx = 0;
    else if (rc->ray.raydirx == 0)
        rc->ray.deltadistx = 1;
    else
        rc->ray.deltadistx = sqrt(1 + (rc->ray.raydiry
                                       * rc->ray.raydiry) / (rc->ray.raydirx *
                                                             rc->ray.raydirx));
    if (rc->ray.raydirx == 0)
        rc->ray.deltadisty = 0;
    else if (rc->ray.raydiry == 0)
        rc->ray.deltadisty = 1;
    else
        rc->ray.deltadisty = sqrt(1 + (rc->ray.raydirx *
                                       rc->ray.raydirx) / (rc->ray.raydiry *
                                                           rc->ray.raydiry));
}

void	ft_calc_ray(t_raycast *rc)
{
    rc->ray.hit = 0;
    rc->ray.perpwalldist = 0;
    rc->ray.camerax = 2 * rc->ray.x / (double)rc->screenx - 1;
    rc->ray.raydirx = rc->ray.dirx + rc->ray.planx * \
						rc->ray.camerax;
    rc->ray.raydiry = rc->ray.diry + rc->ray.plany * \
						rc->ray.camerax;
    rc->ray.mapx = (int)rc->ray.posx;
    rc->ray.mapy = (int)rc->ray.posy;
    rc->ray.movespeed = 0.1;
    rc->ray.rotspeed = 0.033 * 1.8;
    ft_calc_ray_sub(rc);
}

void	ft_init_sub(t_raycast *rc)
{
    write(1, "Try 3\n", 6);
    
    //rc->config->plr_ch = 'x';
    rc->error = 0;
    rc->data.img = NULL;
    rc->texture[0].img = NULL;
    rc->texture[1].img = NULL;
    rc->texture[2].img = NULL;
    rc->texture[3].img = NULL;
    rc->data.mlx_win = NULL;
    //rc->config->map = NULL;
}

void	ft_init(t_raycast *rc)
{
//    ft_count_lines(rc);
    // rc->config->map = NULL;
    // rc->config->no = NULL;
    // rc->config->so = NULL;
    // rc->config->we = NULL;
    // rc->config->ea = NULL;
    // rc->config->floor = -1;
    // rc->config->ceiling = -1;
    rc->nblines = 0;
    // rc->config->plr_x = 0;
    // rc->config->plr_y = 0;
    rc->count = 0;
    rc->screenx = 1024;
    rc->screeny = 540;
    write(1, "Try 2\n", 6);
    ft_init_sub(rc);
}
