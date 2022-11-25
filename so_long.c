/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:04:37 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 19:09:28 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_struc struc

    if (ar <= 1)
    {
        perror("No map");
        exit(1);
    }
    map_name_check(av[1]);
    struc = (t_struc *)malloc(sizeof(t_struc));
    struc->mvcount = 0;
    struc->collect_img.count = 0;
    if (!ft_map_prep(struc, av))
        exit(0);
    ft_game_start(struc);
    mlx_hook(struc->window, X_WINBUTTON, 1L << 3, ft_xbutton, struc);
    mlx_hook(struc->window, KEY_PRESS, 1, ft_start_walk, struc);
    mlx_hook(struc->window, KEY_RELEASE, 1, ft_stop_wall, struc);
    mlx_loop_hook(struc->mlx, ft_work, struc);
    mlx_loop(struc->mlx);
    ft_end(struc);
}