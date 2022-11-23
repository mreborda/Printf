/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreborda <mreborda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:13:43 by mreborda          #+#    #+#             */
/*   Updated: 2022/11/23 10:03:56 by mreborda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int n)
{
	long int	e;

	e = n;
	if (n > 9)
		ft_putnbr_fd (n / 10, 1);
	if (n < 0)
	{	
		n = n * -1;
		ft_putchar_fd ('-', 1);
		if (n > 9)
			ft_putnbr_fd (n / 10, 1);
	}
	ft_putchar_fd ((n % 10) + 48, 1);
	return (ft_count(e));
}
