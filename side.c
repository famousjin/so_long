/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:33:01 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 18:31:27 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_update_up(t_struc *struc)
{
    if (struc->keys.w && !struc->keys.d && !struc->keys.a && !struc->keys.s)
    {
        struc->player_img.y -= struc->player_img.speed;
        if (struc->map[(struc->player_img.y / 64)] \
        [(struc->player_img.x / 64)] == '1')
        {
            struc->player_img.y += struc->player_img.speed;
            struc->mvcount -= 1;
        }
        struc->mvcount += 1;
        ft_printf("%i\n", struc->mvcount);
    }
}

void    ft_update_down(t_struc *struc)
{
    if (!struc->keys.w && !struc->keys.d && !struc->keys.a && struc->keys.s)
    {
        struc->player_img.y += struc->player_img.speed;
        if (struc->map[(struc->player_img.y / 64)] \
        [(struc->player_img.x / 64)] == '1')
        {
            struc->player_img.y -= struc->player_img.speed;
            struc->mvcount -= 1;
        }
        struc->mvcount += 1;
        ft_printf("%i\n", struc->mvcount);
    }
}

void    ft_update_left(t_struc *struc)
{
    if (!struc->keys.w && !struc->keys.d && struc->keys.a && !struc->keys.s)
    {
        struc->player_img.y -= struc->player_img.speed;
        if (struc->map[(struc->player_img.y / 64)] \
        [(struc->player_img.x / 64)] == '1')
        {
            struc->player_img.y += struc->player_img.speed;
            struc->mvcount -= 1;
        }
        struc->mvcount += 1;
        ft_printf("%i\n", struc->mvcount);
    }
}

void    ft_update_right(t_struc *struc)
{
    if (!struc->keys.w && struc->keys.d && !struc->keys.a && !struc->keys.s)
    {
        struc->player_img.y += struc->player_img.speed;
        if (struc->map[(struc->player_img.y / 64)] \
        [(struc->player_img.x / 64)] == '1')
        {
            struc->player_img.y -= struc->player_img.speed;
            struc->mvcount -= 1;
        }
        struc->mvcount += 1;
        ft_printf("%i\n", struc->mvcount);
    }
}

void    ft_which_side(t_struc *struc)
{
    static int  speed;

    if(speed++ < 8)
        return ;
    speed = 0;
    ft_update_up(struc);
    ft_update_down(struc);
    ft_update_left(struc);
    ft_update_right(struc);
}