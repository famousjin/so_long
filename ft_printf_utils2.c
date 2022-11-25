/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:51:30 by myyou             #+#    #+#             */
/*   Updated: 2022/11/20 17:51:50 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_conv_base(unsigned long long n, char *base, unsigned long long base_size)
{
	int	count;

	count = 0;
	if (n >= base_size)
		count = ft_conv_base(n / base_size, base, base_size);
	count += ft_putchar(base[n % bas_size]);
	return (count);
}

int	ft_putnumber(int n)
{
	unsigned long int	sig;

	sig = 1;
	if (n < 0)
	{
		sig = -1;
		ft_putchar('-');
	}
	return (ft_conv_base(n * sig, "0123456789", 10) + (n < 0));
}

int	ft_putui(unsigned int n, char *base, int base_size)
{
	return (ft_conv_base(n, base, base_size));
}

int	ft_putul(unsigned long n)
{
	return (ft_conv_base(n, "0123456789abcdef", 16));
}
