/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:56 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/26 18:06:20 by mpitot           ###   ########.fr       */
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

void	ft_convert(char c, int pid)
{
	if (c < 2)
	{
		if (c == 0)
		{
			kill(pid, SIGUSR1);
			usleep(SLEEP_TIME);
		}
		if (c == 1)
		{
			kill(pid, SIGUSR2);
			usleep(SLEEP_TIME);
		}
	}
	else
	{
		ft_convert(c / 2, pid);
		ft_convert(c % 2, pid);
	}
}

void	ft_kill_zero(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (ft_power(2, i) > c)
		{
			kill(pid, SIGUSR1);
			usleep(SLEEP_TIME);
		}
		else
			return ;
		i--;
	}
}

void	ft_send(char *str, int pid)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_kill_zero(str[i], pid);
		ft_convert(str[i++], pid);
	}
	ft_kill_zero(0, pid);
}

int	main(int argc, char **argv)
{
	int		serv_pid;

	if (argc != 3)
		return (1);
	serv_pid = ft_atoi(argv[1]);
	ft_send(argv[2], serv_pid);
}