/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:59 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/26 19:11:21 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_power(nb, power - 1));
}

void	ft_print_bin(int *tab)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		if (tab[i] == 1)
			c += ft_power(2, 7 - i);
		i++;
	}
	ft_printf("%c", c);
}

void	handle_sigusr(int sig)
{
	static size_t	i = 0;
	static int		tab[8];

	if (sig == SIGUSR1)
		tab[i++] = 0;
	if (sig == SIGUSR2)
		tab[i++] = 1;
	if (i == 8)
	{
		ft_print_bin(tab);
		while (i < 0)
			tab[i--] = 0;
		tab[0] = 0;
		i = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	ft_printf("\033[1;35mWelcome to mpitot's server.\n");
	ft_printf("\033[1;0mThe PID is :\t");
	ft_printf("\033[1;31m%d\033[1;0m\n", pid);
	while(1)
	{
		pause();
	}
	return (0);
}
