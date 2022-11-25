/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:24:41 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 19:09:25 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_print_map(t_struc *struc, char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        x = -1;
        while (map[i][++j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(struc->mlx, \
                struc->window, struc->wall_img.img, j * 64, i * 64);
            else 
                mlx_put_image_to_window(struc->mlx, \
                struc->window, struc->floor_img.img, j * 64, i * 64);
        }
    }
}

void    ft_del_collect(t_struc *struc, int i, int j)
{
    if (struc->player_img.x == j * 64 && struc->player_img.y == i * 64)
    {
        struc->map[i][j] = '0';
        struc->collect_img.count++;
    }
    else
    {
        mlx_put_image_to_window(struc->mlx, struc->window, \
        struc->collect_img.img, struc->collect_img.x, struc->collect_img.y);
    }
}

void    ft_init_exit(t_struc *struc, char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'E')
            {
                struc->exit_img.x = j * 64;
                struc->exit_img.y = i * 64;
                mlx_put_image_to_window(struc->mlx, struc->window, \
                struc->floor_img.img, struc->exit_img.x, struc->exit_img.y);
                if (struc->player_img.x == j * 64 \
                && struc->player_img.y == i * 64)
                    if (struc->collect_img.count == struc->collect_img.n)
                        ft_end(struc);
                if (struc->collect_img.count == struc->collect_img.n)
                   mlx_put_image_to_window(struc->mlx, struc->window, \
                struc->exit_img.img, struc->exit_img.x, struc->exit_img.y);
            }
        }
    }
}

void    ft_trap_init(t_struc *struc, char **map)
{
    int i;
    int j;
    
    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if(map[i][j] == 'T')
            {
                struc->exit_img.x = j * 64;
                struc->exit_img.y = i * 64;
                mlx_put_image_to_window(struc->mlx, struc->window, \
                struc->exit_img.img, struc->exit_img.x, struc->exit_img.y);
                if(struc->player_img.x == j * 64 \
                && struc->player_img.y == i * 64)
                    ft_end(struc);
            }
        }
    }
}

int ft_check_char(t_struc *struc, char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        if (map[i][j] != 'P' && \
        map[i][j] != 'E' && map[i][j] != 'C' && \
        map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
        {
            perror("Character not valid");
            return (0);
        }
    }
    struc->x_window_param = i * 64;//세로길이
    struc->y_window_param = (j * 64) - 64;//가로길이?
    return (1);
}