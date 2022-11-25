/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:36:59 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 18:41:57 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_game_start(t_struc *struc)
{
    struc->mlx = mlx_init();
    struc->window = mlx_new_window(struc->mlx, struc->hori_window_param, \
    struc->verti_window_param, "so_long: finally I can play");
    ft_keys_init(struc);
    ft_map_init(struc);
    ft_player_init(struc, struc->map);
}

void    ft_keys_init(t_struc *struc)
{
    struc->keys.esc = 0;
    struc->keys.a = 0;
    struc->keys.w = 0;
    struc->keys.s = 0;
    struc->keys.d = 0;
}

void    ft_map_init(t_struc *struc)
{
    struc->wall_img.img = mlx_xpm_file_to_image \
    (struc->mlx, "./asset/wall.xpm", &struc->wall_img.width, \
    &struc->wall_img.height);
    struc->floor_img.img = mlx_xpm_file_to_image \
    (struc->mlx, "./asset/floor.xpm", &struc->floor_img.width, \
    &struc->wall_img.height);
    struc->collect_img.img = mlx_xpm_file_to_image \
    (struc->mlx, "./asset/collect.xpm", &struc->collect_img.width, \
    &struc->wall_img.height);
    struc->exit_img.img = mlx_xpm_file_to_image \
    (struc->mlx, "./asset/exit.xpm", &struc->exit_img.width, \
    &struc->wall_img.height);
}

void    ft_player_init(t_struc *struc, char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (mpa[i][j] == 'P')
            {
                struc->player_img.x = j * 64;
                struc->player_img.y = i * 64;
            }
        }
    }
    struc->player_img.speed = 64;
    struc->player_img.img = mlx_xpm_file_to_image(struc->mlx, \
    "./asset/player.xpm", &struc->player_img.width, \ 
    &struc->player_img.height);
    mlx_put_image_to_window(struc->mlx, struc->window, \
    struc->player_img.img, struc->player_img.x, struc->player_img.y);
}

void    ft_init_collect(t_struc *struc, char **map)
{
    static int  i;
    static int  j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'C')
            {
                struc->collect_img.x = j * 64;
                struc->collect_img.y = i * 64;
                ft_del_collect(struc, y, x);
            }
        }
    }
}