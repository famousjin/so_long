/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:30:34 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 18:57:01 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_map_prep(t_struc *struc, char **av)
{
    int fd;

    fd = open(av[1], O_RDONLY);
    if (fd <= 0)
    {
        perror("File open faile");
        return (0);
    }
    struc->map = ft_mapstr(NULL, fd, 0);
    close(fd);
    if (!ft_check_map(struc, struc->map))
        return (0);
    if (!ft_check_map_close(struc->map))
    {
        perror("Map is not closed");
        return (0);
    }
    if (!ft_check_map_every(struc, struc->map))
    {
        perror("Not require to start");
        return (0);
    }
    if (!ft_check_char(struc, struc->map))
        return (0);
    return (1);
}

char **ft_mapstr(char **map, int fd, int counter)
{
    char    *str;
    str = get_next_line(fd);
    if (str)
        map = ft_mapstr(map, fd, 1 + counter);
    if (!map && counter != 0)
        map = malloc((counter + 1) * (sizeof(char *)));
    if (!map)
        ft_end(NULL);
    map[counter] = str;
    return (map);
}

int ft_check_map(t_struc *struc, char **map)
{
    int i;
    int j;

    i = -1;
    j = 0;
    while (map[++i] && map[i][j] != '\n')
    {
        if (strlen(map[0]) != strlen(i))
        {
            perror("Map is not rectangle");
            return(0);
        }
    }
    return (1);
}

int ft_check_map_close(char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[0][j] != '1' && map[0][j] != '\n')
                return (0);
            if (map[i][0] != '1')
                return (0);
        }
        if (map[i][j - 2] != '1')//맨 뒷자리를 체크하는건가?
            return(0);
    }
    i -= 1;
    j = -1;
    while (map[i - 1][++j])
        if (map[i][j] != '1' && map [i][j] != '\n')
            return (0);
    return (1);
}

int ft_check_map_every(t_struc *struc, char *map)
{
    int i;
    int j;
    int e;
    int p;

    e = 0;
    p = 0;
    i = -1;
    struc->collect_img.n = 0;
    while (map[++y])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'C')
                struc->collect_img.n++;
            if (map[i][j] == 'E')
                e++;
            if (map[i][j] == 'P')
                p++;
        }
    }
    if (struc->collect_img.n < 1 || e < 1 || p != 1)
        return (0);
    return (0);
}