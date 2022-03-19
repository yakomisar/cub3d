/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:33:32 by sstyr             #+#    #+#             */
/*   Updated: 2022/03/07 13:33:34 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_calc_ray_sub(t_raycast *rc)
{
	if (rc->ray.raydiry == 0)
		rc->ray.deltadistx = 0;
	else if (rc->ray.raydirx == 0)
		rc->ray.deltadistx = 1;
	else
		rc->ray.deltadistx = sqrt(1 + (rc->ray.raydiry \
			* rc->ray.raydiry) / (rc->ray.raydirx * rc->ray.raydirx));
	if (rc->ray.raydirx == 0)
		rc->ray.deltadisty = 0;
	else if (rc->ray.raydiry == 0)
		rc->ray.deltadisty = 1;
	else
		rc->ray.deltadisty = sqrt(1 + (rc->ray.raydirx \
			* rc->ray.raydirx) / (rc->ray.raydiry * rc->ray.raydiry));
}

void	ft_calc_ray(t_raycast *rc)
{
	rc->ray.hit = 0;
	rc->ray.perpwalldist = 0;
	rc->ray.camerax = 2 * rc->ray.x / (double)rc->screenx - 1;
	rc->ray.raydirx = rc->ray.dirx + rc->ray.planx * rc->ray.camerax;
	rc->ray.raydiry = rc->ray.diry + rc->ray.plany * rc->ray.camerax;
	rc->ray.mapx = (int)rc->ray.posx;
	rc->ray.mapy = (int)rc->ray.posy;
	rc->ray.movespeed = 0.1;
	rc->ray.rotspeed = 0.033 * 1.8;
	ft_calc_ray_sub(rc);
}

void	ft_init_texture(t_raycast *rc)
{
	if (rc->ray.side == 0 && rc->ray.raydirx < 0)
		rc->t.texdir = 0;
	if (rc->ray.side == 0 && rc->ray.raydirx >= 0)
		rc->t.texdir = 1;
	if (rc->ray.side == 1 && rc->ray.raydiry < 0)
		rc->t.texdir = 2;
	if (rc->ray.side == 1 && rc->ray.raydiry >= 0)
		rc->t.texdir = 3;
	if (rc->ray.side == 0)
		rc->t.wallx = rc->ray.posy + rc->ray.perpwalldist \
						* rc->ray.raydiry;
	else
		rc->t.wallx = rc->ray.posx + rc->ray.perpwalldist \
						* rc->ray.raydirx;
	rc->t.wallx -= floor((rc->t.wallx));
}

void	ft_draw_texture(t_raycast *rc, int x, int y)
{
	y = rc->ray.drawstart - 1;
	ft_init_texture(rc);
	rc->t.step = 1.0 * rc->texture[0].height / rc->ray.lineheight;
	rc->t.texx = (int)(rc->t.wallx * (double)rc->texture \
		[rc->t.texdir].width);
	if (rc->ray.side == 0 && rc->ray.raydirx > 0)
		rc->t.texx = rc->texture[rc->t.texdir].width - \
			rc->t.texx - 1;
	if (rc->ray.side == 1 && rc->ray.raydiry < 0)
		rc->t.texx = rc->texture[rc->t.texdir].width - \
			rc->t.texx - 1;
	rc->t.texpos = (rc->ray.drawstart - rc->screeny / 2 + \
		rc->ray.lineheight / 2) * rc->t.step;
	while (++y <= rc->ray.drawend)
	{
		rc->t.texy = (int)rc->t.texpos & \
			(rc->texture[rc->t.texdir].height - 1);
		rc->t.texpos += rc->t.step;
		if (y < rc->screeny && x < rc->screenx)
			rc->data.addr[y * rc->data.line_length / 4 + x] = \
				rc->texture[rc->t.texdir].addr[rc->t.texy * \
				rc->texture[rc->t.texdir].line_length / 4 + rc->t.texx];
	}
}
