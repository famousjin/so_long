/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:45:09 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 10:25:58 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static  int check_match(char *str, char *find)
{
    int i;

    i= 0;
    while(find[i])
    {
        if (find[i] != str[i])
            return (0);
        i++;
    }
    if (str[i] == '\0')
        return (1);
    return (0);
}

void    map_check(char *mapaddr)
{
    while (*mapaddr)
    {
        if(*mapaddr == '.')
        {
            if(check_match(mapaddr, ".ber"))
                return (0);
        }
        mapaddr++;
    }
    perror("File name is odd!");
    exit (1);
}