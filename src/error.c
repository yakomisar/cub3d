//
// Created by matsony on 09.03.2022.
//

#include "../inc/cub3d.h"

int		ft_exit(t_raycast *rc)
{
    if (rc->error == 0)
        ft_error(rc, "Error = 0\n");
    if (rc->data.img)
        mlx_destroy_image(rc->data.mlx_ptr, rc->data.img);
    if (rc->texture[0].img)
        mlx_destroy_image(rc->data.mlx_ptr, rc->texture[0].img);
    if (rc->texture[1].img)
        mlx_destroy_image(rc->data.mlx_ptr, rc->texture[1].img);
    if (rc->texture[2].img)
        mlx_destroy_image(rc->data.mlx_ptr, rc->texture[2].img);
    if (rc->texture[3].img)
        mlx_destroy_image(rc->data.mlx_ptr, rc->texture[3].img);
    if (rc->data.mlx_win)
        mlx_destroy_window(rc->data.mlx_ptr, rc->data.mlx_win);
    exit(0);
}

void	ft_error(t_raycast *rc, char *str)
{
    // int i;

    // i = -1;
    rc->error = 1;
    write(1, "Error\n", 6);
    write(1, str, ft_strlen(str));
    if (rc->config->no)
        free(rc->config->no);
    if (rc->config->so)
        free(rc->config->so);
    if (rc->config->we)
        free(rc->config->we);
    if (rc->config->ea)
        free(rc->config->ea);
//    if (rc->config.map)
//    {
//        while (++i < rc->nblines)
//            free(rc->config.map[i]);
//    }
    if (rc->config->map)
        free(rc->config->map);
    ft_exit(rc);
}