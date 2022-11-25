/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:52:43 by mbarreto          #+#    #+#             */
/*   Updated: 2022/11/20 17:51:45 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str && str[i])
		i++;
	return (write(1, str, i));
}