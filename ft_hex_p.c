/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreborda <mreborda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:21:00 by mreborda          #+#    #+#             */
/*   Updated: 2022/11/23 13:49:11 by mreborda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hex_size(long unsigned int p, size_t i)
{
	char	*base;

	base = "0123456789abcdef";
	if (p > 15)
		i = ft_hex_size(p / 16, i);
	ft_putchar_fd(base[p % 16], 1);
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
