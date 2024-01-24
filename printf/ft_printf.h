/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:04:03 by mpitot            #+#    #+#             */
/*   Updated: 2023/12/19 12:12:38 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(int c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_x(unsigned int nbr, char *base);
int		ft_putmem(void *ptr);

size_t	ft_strlen(const char *s);
#endif
