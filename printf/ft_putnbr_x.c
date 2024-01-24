/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:16:49 by mpitot            #+#    #+#             */
/*   Updated: 2023/12/19 14:51:06 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(unsigned int nbr, char *base)
{
	int		x;
	int		y;

	if (nbr < 16)
		return (ft_putchar(base[nbr]));
	x = ft_putnbr_x(nbr / 16, base);
	if (x == -1)
		return (-1);
	y = ft_putchar(base[nbr % 16]);
	if (y == -1)
		return (-1);
	return (x + y);
}
