/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:58:58 by mpitot            #+#    #+#             */
/*   Updated: 2023/12/19 13:48:43 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		x;
	int		y;

	if (n < 0)
	{
		x = ft_putchar('-');
		if (x == -1)
			return (-1);
		y = ft_putnbr_u(n * -1);
		if (y == -1)
			return (-1);
		return (x + y);
	}
	else
		return (ft_putnbr_u(n));
}
