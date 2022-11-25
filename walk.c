/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:40:40 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 19:05:30 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_xbutton(t_struc *struc)
{
    mlx_destroy_window(struc->mlx, struc->window);
    exit(0);
}

int ft_start_walk(int key, t_struc *struc)
{
    if (key == KEY_ESC)
        ft_end(struc);
    if (key == KEY_A)
        struc->keys.a = 1;
    if (key == KEY_W)
        struc->keys.w = 1;
    if (key == KEY_S)
        struc->keys.s = 1;
    if (key == KEY_D)
        struc->keys.d = 1;
    return (1);
}

int ft_stop_walk(int key, t_struc *struc)
{
    if (key == KEY_ESC)
        ft_end(struc);
    if (key == KEY_A)
        struc->keys.a = 0;
    if (key == KEY_W)
        struc->keys.w = 0;
    if (key == KEY_S)
        struc->keys.s = 0;
    if (key == KEY_D)
        struc->keys.d = 0;
    return (1);
}

int ft_move(t_struc *struc)
{
    ft_print_map(struc, struc->map);
    ft_init_collect(struc, struc->map);
    ft_init_exit(struc, struc->map);
    ft_trap_init(struc, struc->map);
    mlx_put_image_to_window(struc->mlx, struc->window, \
    struc->player_img.img, struc->player_img.x, struc->player_img.y)
    return (1);
}

int ft_work(t_struc *struc)
{
    ft_which_side(struc);
    ft_move(struc);
    return(1);
}