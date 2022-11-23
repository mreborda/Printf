/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreborda <mreborda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:47:37 by mreborda          #+#    #+#             */
/*   Updated: 2022/11/23 13:49:44 by mreborda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_convert(va_list arg, char c)
{
	size_t	lenght;

	lenght = 0;
	if (c == 'c')
		lenght = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		lenght = ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		lenght = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		lenght = ft_print_u(va_arg(arg, unsigned int));
	else if (c == '%')
	{	
		lenght++;
		ft_putchar_fd(c, 1);
	}
	else if (c == 'p')
		lenght = ft_hex_p(va_arg(arg, long unsigned int));
	return (lenght);
}

int	ft_printf(const char *str, ...)
{	
	va_list	arg;
	size_t	lenght;
	int		i;

	i = 0;
	lenght = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			lenght += print_convert(arg, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			lenght++;
		}
		i++;
	}
	va_end(arg);
	return (lenght);
}

/* int	main(void)
{
	printf("%d\n", ft_printf("char %p\n", 5));
	printf("%d\n", ft_printf("string %s\n", "olaaa"));
	printf("%d\n", ft_printf("pointer %p\n", (char *)-1));
	printf("%p", (char *)-1);
} */
