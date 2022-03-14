//
// Created by matsony on 05.03.2022.
//

#include "../inc/cub3d.h"

int		ft_color_column(t_raycast *rc)
{
    int j;
    int i;

    j = -1;
    rc->ray.drawend = rc->ry - rc->ray.drawstart;
    i = rc->ray.drawend;
    while (++j < rc->ray.drawstart)
        rc->data.addr[j * rc->data.line_length / 4 +
                      rc->ray.x] = rc->config.ceiling;
    if (j <= rc->ray.drawend)
        ft_draw_texture(rc, rc->ray.x, j);
    j = i;
    while (++j < rc->ry)
        rc->data.addr[j * rc->data.line_length / 4 +
                      rc->ray.x] = rc->config.floor;
    return (0);
}

void	ft_calc_start_end(t_raycast *rc)
{
    if (rc->ray.side == 0)
        rc->ray.perpwalldist = ((double)rc->ray.mapx - \
				rc->ray.posx + (1 - (double)rc->ray.
                stepx) / 2) / rc->ray.raydirx;
    else
        rc->ray.perpwalldist = ((double)rc->ray.mapy - \
				rc->ray.posy + (1 - (double)rc->ray.
                stepy) / 2) / rc->ray.raydiry;
    rc->ray.lineheight = (int)(rc->ry / rc->ray.perpwalldist);
    rc->ray.drawstart = -rc->ray.lineheight / 2 + rc->ry / 2;
    if (rc->ray.drawstart < 0)
        rc->ray.drawstart = 0;
    rc->ray.drawend = rc->ray.lineheight / 2 + rc->ry / 2;
    if (rc->ray.drawend >= rc->ry || rc->ray.drawend < 0)
        rc->ray.drawend = rc->ry - 1;
}

void	ft_increment_ray(t_raycast *rc)
{
    while (rc->ray.hit == 0)
    {
        if (rc->ray.sidedistx < rc->ray.sidedisty)
        {
            rc->ray.sidedistx += rc->ray.deltadistx;
            rc->ray.mapx += rc->ray.stepx;
            rc->ray.side = 0;
        }
        else
        {
            rc->ray.sidedisty += rc->ray.deltadisty;
            rc->ray.mapy += rc->ray.stepy;
            rc->ray.side = 1;
        }
        if (rc->config.map[rc->ray.mapx][rc->ray.mapy] == '1')
            rc->ray.hit = 1;
    }
    ft_calc_start_end(rc);
}

void	ft_calc_step(t_raycast *rc)
{
    if (rc->ray.raydirx < 0)
    {
        rc->ray.stepx = -1;
        rc->ray.sidedistx = (rc->ray.posx - rc->ray.mapx) \
							* rc->ray.deltadistx;
    }
    else
    {
        rc->ray.stepx = 1;
        rc->ray.sidedistx = (rc->ray.mapx + 1.0 - rc->ray.posx) \
							* rc->ray.deltadistx;
    }
    if (rc->ray.raydiry < 0)
    {
        rc->ray.stepy = -1;
        rc->ray.sidedisty = (rc->ray.posy - rc->ray.mapy) \
							* rc->ray.deltadisty;
    }
    else
    {
        rc->ray.stepy = 1;
        rc->ray.sidedisty = (rc->ray.mapy + 1.0 - rc->ray.posy) \
							* rc->ray.deltadisty;
    }
    ft_increment_ray(rc);
}
