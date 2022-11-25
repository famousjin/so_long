/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:57:01 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 19:08:40 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include <stdio.h>//perror
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>//exit
#include <string.h>
#include <stdarg.h>

# define KEY_PRESS      2
# define KEY_RELEASE    3
# define X_WINBUTTON    17

# define KEY_ESC    53
# define KEY_W      13
# define KEY_A      0
# define KEY_S      1
# define KEY_D      2

typedef struct s_keys
{
    int esc;
    int a;
    int w;
    int s;
    int d;
}               t_keys;

typedef struct s_images
{
    void    *img;
    int     width;
    int     height;
    int     count;
    int     n;
    int     x;
    int     y;
    int     speed;
}               t_images;


typedef struct s_struc
{
    char **map;
    void    *mlx;
    void    *window;
    int count;
    int mvcount;
    int x_window_param;
    int y_window_param;

    t_images    collect_img;
    t_images    wall_img;
    t_images    floor_img;
    t_images    exit_img;
    t_images    player_img;

    t_keys       keys;
}               t_struc;

//map_name_check.c
static  int check_match(char *str, char *find);
void    map_check(char *mapaddr);
//end.c
void    ft_end(t_struc *struc);
//map.c
char **ft_mapstr(char **map, int fd, int counter);
int ft_map_prep(t_struc *struc, char **av);
int ft_check_map(t_struc *struc, char **map);
int ft_check_map_close(char **map);
int ft_check_map_every(t_struc *struc, char *map);
//game_start.c
void    ft_game_start(t_struc *struc);
void    ft_keys_init(t_struc *struc);
void    ft_map_init(t_struc *struc);
void    ft_player_init(t_struc *struc, char **map);
void    ft_init_collect(t_struc *struc, char **map)
//walk.c
int ft_xbutton(t_struc *struc);
int ft_start_walk(int key, t_struc *struc);
int ft_stop_walk(int key, t_struc *struc);
int ft_work(t_struc *struc);
int ft_move(t_struc *struc);
//side.c
void    ft_which_side(t_struc *struc);
void    ft_update_up(t_struc *struc);
void    ft_update_down(t_struc *struc);
void    ft_update_left(t_struc *struc);
void    ft_update_right(t_struc *struc);
//ft_prinf.c
int	ft_found_format(const char *format, int i, va_list *args);
int	ft_printf(const char *format, ...);
//ft_printf_utils.c
int	ft_putchar(char c);
int	ft_putstr(char *str);
//ft_printf_utils2.c
int	ft_putnumber(int n);
int	ft_putui(unsigned int n, char *base, int base_size);
int	ft_putul(unsigned long n);
int	ft_conv_base(unsigned long long n, char *base, unsigned long long base_size);
//move.c
void    ft_print_map(t_struc *struc, char **map);
void    ft_del_collect(t_struc *struc, int y, int x);
void    ft_init_exit(t_struc *struc, char **map);
void    ft_trap_init(t_struc *struc, char **map)
int ft_check_char(t_struc *struc, char **map);

# endif