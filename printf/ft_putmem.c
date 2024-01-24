/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:08:46 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/24 14:29:48 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recurs(uintptr_t n, const char *base)
{
	int		x;
	int		y;

	if (n < 16)
		return (ft_putchar(base[n]));
	x = ft_recurs(n / 16, base);
	if (x == -1)
		return (-1);
	y = ft_putchar(base[n % 16]);
	if (y == -1)
		return (-1);
	return (x + y);
}

int	ft_putmem(void *ptr)
{
	int		x;
	int		y;

	if (!ptr)
		return (ft_putstr("(nil)"));
	x = ft_putstr("0x");
	if (x == -1)
		return (-1);
	y = ft_recurs(((uintptr_t) ptr), "0123456789abcdef");
	if (y == -1)
		return (-1);
	return (x + y);
}
