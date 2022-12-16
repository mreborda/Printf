/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreborda <mreborda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:21:00 by mreborda          #+#    #+#             */
/*   Updated: 2022/11/29 15:38:15 by mreborda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hex_size(long unsigned int p, size_t i)
{
	char	*format;

	format = "0123456789abcdef";
	if (p > 15)
		i = ft_hex_size(p / 16, i);
	ft_putchar_fd(format[p % 16], 1);
	i++;
	return (i);
}

int	ft_hex_p(long unsigned int p)
{
	size_t	i;

	i = 2;
	if (!p)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	return (ft_hex_size(p, i));
}

size_t	ft_xx_size(long unsigned int x)
{
	size_t				lenght;
	long unsigned int	n;

	n = x;
	lenght = 0;
	if (x == 0)
		return (1);
	while (n != 0)
	{
		lenght++;
		n /= 16;
	}
	return (lenght);
}

int	ft_hex_xx(long unsigned int x, int format)
{
	char	*c;

	if (format)
		c = "0123456789abcdef";
	else
		c = "0123456789ABCDEF";
	if (x > 15)
		ft_hex_xx(x / 16, format);
	ft_putchar_fd(c[x % 16], 1);
	return (ft_xx_size((long)x));
}
