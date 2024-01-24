/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:16:37 by mpitot            #+#    #+#             */
/*   Updated: 2023/12/19 15:16:37 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char c, va_list args)
{
	if (!c)
		return (-1);
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'x')
		return (ft_putnbr_x(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_x(va_arg(args, int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_putmem(va_arg(args, void *)));
	return (ft_putchar('%') + ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		res;
	int		temp;

	va_start(args, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
			temp = ft_convert(format[++i], args);
		else
			temp = ft_putchar(format[i]);
		if (temp == -1)
			return (-1);
		res += temp;
		i++;
	}
	va_end(args);
	return (res);
}
