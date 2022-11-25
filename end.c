/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:36:29 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 13:45:41 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_end(t_struc *struc)
{
    int i;

    i = -1;
    if (struc->map)
    {
        while (struc->map[++i])
            free(struc->map[i]);
        free(struc->map);
    }
    if(struc->floor_img.img)
        mlx_destroy_image(struc->mlx, struc->floor_img.img);
    if(struc->wall_img.img)
        mlx_destroy_image(struc->mlx, struc->wall_img.img);
    if(struc->collect_img.img)
        mlx_destroy_image(struc->mlx, struc->collect_img.img);
    if(struc->exit_img.img)
        mlx_destroy_image(struc->mlx, struc->exit_img.img);
    if(struc->player_img.img)
        mlx_destroy_image(struc->mlx, struc->player_left_img.img);
    mlx_destroy_window(window->mlx, window->win);
    free(struc);
    exit(0);
}