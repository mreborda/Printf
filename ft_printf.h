/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreborda <mreborda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:48:16 by mreborda          #+#    #+#             */
/*   Updated: 2022/11/28 10:59:19 by mreborda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
size_t	print_convert(va_list arg, char c);
size_t	ft_count(long int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long int n);
int		ft_print_u(unsigned int n);
int		ft_hex_p(long unsigned int p);
int		ft_hex_xx(long unsigned int x, int format);
size_t	ft_xx_size(long unsigned int x);
#endif