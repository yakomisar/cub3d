/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:33:32 by sstyr             #+#    #+#             */
/*   Updated: 2022/03/14 13:33:34 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_key_press(int keycode, t_raycast *rc)
{
	if (keycode == W_KEY)
		rc->data.forward = 1;
	else if (keycode == S_KEY)
		rc->data.back = 1;
	else if (keycode == A_KEY)
		rc->data.left = 1;
	else if (keycode == D_KEY)
		rc->data.right = 1;
	else if (keycode == LEFT_KEY)
		rc->data.rotate_left = 1;
	else if (keycode == RIGHT_KEY)
		rc->data.rotate_right = 1;
	else if (keycode == ESC_KEY)
		ft_error(rc, "Esc button\n");
	return (1);
}

int	ft_key_release(int keycode, t_raycast *rc)
{
	if (keycode == W_KEY)
		rc->data.forward = 0;
	else if (keycode == S_KEY)
		rc->data.back = 0;
	else if (keycode == A_KEY)
		rc->data.left = 0;
	else if (keycode == D_KEY)
		rc->data.right = 0;
	else if (keycode == LEFT_KEY)
		rc->data.rotate_left = 0;
	else if (keycode == RIGHT_KEY)
		rc->data.rotate_right = 0;
	return (1);
}
