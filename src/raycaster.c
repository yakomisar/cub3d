//
// Created by matsony on 01.03.2022.
//

#include "../inc/cub3d.h"

void	ft_get_texture_adress(t_raycast *rc)
{
    rc->texture[0].addr = (int *)mlx_get_data_addr(rc->texture[0].img,
                                                   &rc->texture[0].bits_per_pixel,
                                                   &rc->texture[0].line_length, &rc->texture[0].endian);
    rc->texture[1].addr = (int *)mlx_get_data_addr(rc->texture[1].img,
                                                   &rc->texture[1].bits_per_pixel,
                                                   &rc->texture[1].line_length, &rc->texture[1].endian);
    rc->texture[2].addr = (int *)mlx_get_data_addr(rc->texture[2].img,
                                                   &rc->texture[2].bits_per_pixel,
                                                   &rc->texture[2].line_length, &rc->texture[2].endian);
    rc->texture[3].addr = (int *)mlx_get_data_addr(rc->texture[3].img,
                                                   &rc->texture[3].bits_per_pixel,
                                                   &rc->texture[3].line_length, &rc->texture[3].endian);
}

void	ft_get_texture(t_raycast *rc)
{
    if (!(rc->texture[0].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->no, &(rc->texture[0].width),
                                                     &(rc->texture[0].height))))
        ft_error(rc, "Texture SO\n");
    if (!(rc->texture[1].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->so, &(rc->texture[1].width),
                                                     &(rc->texture[1].height))))
        ft_error(rc, "Texture NO\n");
    if (!(rc->texture[2].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->we, &(rc->texture[2].width),
                                                     &(rc->texture[2].height))))
        ft_error(rc, "Texture EA\n");
    if (!(rc->texture[3].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->ea, &(rc->texture[3].width),
                                                     &(rc->texture[3].height))))
        ft_error(rc, "Texture WE\n");
    ft_get_texture_adress(rc);
}

int		ft_raycasting(t_raycast *rc)
{
    rc->ray.x = 0;
    while (rc->ray.x < rc->screenx)
    {
        ft_calc_ray(rc);
        ft_calc_step(rc);
        ft_color_column(rc);
        rc->ray.x++;
    }
    mlx_put_image_to_window(rc->data.mlx_ptr, rc->data.mlx_win,
                            rc->data.img, 0, 0);
    ft_forward_back(rc);
    ft_left_right(rc);
    ft_rotate_right_left(rc);
    return (0);
}

int		ft_mlx(t_raycast *rc)
{
    ft_init_ray(rc); //here
    write(1, "Try 3\n", 6);
    if (!(rc->data.mlx_ptr = mlx_init()))
        ft_error(rc, "Mlx init impossible\n"); //here
//    mlx_get_screen_size(rc->data.mlx_ptr, &rc->screenx, &rc->screeny);
//    rc->rx = (rc->rx > rc->screenx) ? rc->screenx : rc->rx;
//    rc->ry = (rc->ry > rc->screeny) ? rc->screeny : rc->ry;
//    printf("%i %i\n", rc->rx, rc->ry);
    write(1, "Try 4\n", 6);
    printf("Ray pos x: %f\n", rc->ray.posx);
    printf("Ray pos y: %f\n", rc->ray.posy);
    printf("Ray dir x: %f\n", rc->ray.dirx);
    printf("Ray dir y: %f\n", rc->ray.diry);
    printf("Ray plan x: %f\n", rc->ray.planx);
    printf("Ray plan y: %f\n", rc->ray.plany);

    ft_get_texture(rc);

    write(1, "Try 5\n", 6);

    rc->data.img = mlx_new_image(rc->data.mlx_ptr, rc->screenx, rc->screeny);
    write(1, "Try 6\n", 6);
    rc->data.addr = (int *)mlx_get_data_addr(rc->data.img, &rc->data.
            bits_per_pixel, &rc->data.line_length, &rc->data.endian);
    write(1, "Try 7\n", 6);
    rc->data.mlx_win = mlx_new_window(rc->data.mlx_ptr, rc->screenx,
                                      rc->screeny, "Hello world!");

    write(1, "Try 8\n", 6);
    mlx_hook(rc->data.mlx_win, 33, 1L << 17, ft_exit, rc);
    write(1, "Try 9\n", 6);
    mlx_hook(rc->data.mlx_win, 2, 1L << 0, ft_key_press, rc);
    write(1, "Try 10\n", 7);
    mlx_loop_hook(rc->data.mlx_ptr, ft_raycasting, rc);
    write(1, "Try 11\n", 7);
    mlx_hook(rc->data.mlx_win, 3, 1L << 1, ft_key_release, rc);
    write(1, "Try 12\n", 7);
    mlx_loop(rc->data.mlx_ptr);
    write(1, "Try 13\n", 7);
    return (0);
}

