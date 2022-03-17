//
// Created by matsony on 14.03.2022.
//

#include "../inc/cub3d.h"

void	ft_forward_back(t_raycast *rc)
{
	if (rc->data.forward == 1)
	{
		if (rc->config.map[(int)(rc->ray.posx + \
		(rc->ray.dirx * rc->ray.movespeed * 2))][(int)rc->ray.posy] == '0')
			rc->ray.posx += rc->ray.dirx * rc->ray.movespeed;
		if (rc->config.map[(int)(rc->ray.posx)][(int)(rc->ray.posy + \
		(rc->ray.diry * rc->ray.movespeed * 2))] == '0')
			rc->ray.posy += rc->ray.diry * rc->ray.movespeed;
	}
	if (rc->data.back == 1)
	{
		if (rc->config.map[(int)(rc->ray.posx - (rc->ray.dirx \
		* rc->ray.movespeed * 2))][(int)(rc->ray.posy)] == '0')
			rc->ray.posx -= rc->ray.dirx * rc->ray.movespeed;
		if (rc->config.map[(int)(rc->ray.posx)][(int)(rc->ray.posy \
		- (rc->ray.diry * rc->ray.movespeed * 2))] == '0')
			rc->ray.posy -= rc->ray.diry * rc->ray.movespeed;
	}
}

void	ft_left_right(t_raycast *rc)
{
	if (rc->data.right == 1)
	{
		if (rc->config.map[(int)(rc->ray.posx + rc->ray.diry * \
			(rc->ray.movespeed * 2))][(int)rc->ray.posy] == '0')
			rc->ray.posx += rc->ray.diry * rc->ray.movespeed;
		if (rc->config.map[(int)rc->ray.posx][(int)(rc->ray.posy \
		- rc->ray.dirx * (rc->ray.movespeed * 2))] == '0')
			rc->ray.posy -= rc->ray.dirx * rc->ray.movespeed;
	}
	if (rc->data.left == 1)
	{
		if (rc->config.map[(int)(rc->ray.posx - rc->ray.diry * \
		(rc->ray.movespeed * 2))][(int)rc->ray.posy] == '0')
			rc->ray.posx -= rc->ray.diry * rc->ray.movespeed;
		if (rc->config.map[(int)rc->ray.posx][(int)(rc->ray.posy + \
		rc->ray.dirx * (rc->ray.movespeed * 2))] == '0')
			rc->ray.posy += rc->ray.dirx * rc->ray.movespeed;
	}
}

void	ft_rotate_left(t_raycast *rc, double olddirx)
{
	double	oldplanex;

	if (rc->data.rotate_left == 1)
	{
		olddirx = rc->ray.dirx;
		oldplanex = rc->ray.planx;
		rc->ray.dirx = rc->ray.dirx * cos(rc->ray.rotspeed / 2) - \
			rc->ray.diry * sin(rc->ray.rotspeed / 2);
		rc->ray.diry = olddirx * sin(rc->ray.rotspeed / 2) + \
			rc->ray.diry * cos(rc->ray.rotspeed / 2);
		rc->ray.planx = rc->ray.planx * cos(rc->ray.rotspeed / 2) - \
			rc->ray.plany * sin(rc->ray.rotspeed / 2);
		rc->ray.plany = oldplanex * sin(rc->ray.rotspeed / 2) + \
			rc->ray.plany * cos(rc->ray.rotspeed / 2);
	}
}

void	ft_rotate_right_left(t_raycast *rc)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = rc->ray.planx;
	olddirx = rc->ray.dirx;
	if (rc->data.rotate_right == 1)
	{
		rc->ray.dirx = rc->ray.dirx * cos(-rc->ray.rotspeed / 2) - \
		rc->ray.diry * sin(-rc->ray.rotspeed / 2);
		rc->ray.diry = olddirx * sin(-rc->ray.rotspeed / 2) + \
		rc->ray.diry * cos(-rc->ray.rotspeed / 2);
		rc->ray.planx = rc->ray.planx * cos(-rc->ray.rotspeed / 2) - \
		rc->ray.plany * sin(-rc->ray.rotspeed / 2);
		rc->ray.plany = oldplanx * sin(-rc->ray.rotspeed / 2) + \
		rc->ray.plany * cos(-rc->ray.rotspeed / 2);
	}
	ft_rotate_left(rc, olddirx);
}
