/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:04:17 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/24 14:30:11 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int		x;
	int		y;

	if (n < 10)
		return (ft_putchar((int) n + 48));
	x = ft_putnbr_u(n / 10);
	if (x == -1)
		return (-1);
	y = ft_putchar(((int)(n % 10) + 48));
	if (y == -1)
		return (-1);
	return (x + y);
}
