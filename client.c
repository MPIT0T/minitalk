/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:56 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/06 14:05:33 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

ssize_t	ft_power(int nb, ssize_t power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_power(nb, power - 1));
}

void	ft_send_n_wait(int bit, int pid)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	pause();
//	usleep(100);
}

void	ft_convert(char c, int pid)
{
	if (c < 2)
		ft_send_n_wait(c, pid);
	else
	{
		ft_convert(c / 2, pid);
		ft_convert(c % 2, pid);
	}
}

void	ft_kill_zero(ssize_t n, int pid, ssize_t i)
{
	while (i >= 0)
	{
		if (ft_power(2, i) > n)
			ft_send_n_wait(0, pid);
		else
			return ;
		i--;
	}
}

void	ft_send_size(ssize_t size, int pid)
{
	if (size < 2)
		ft_send_n_wait(size, pid);
	else
	{
		ft_send_size(size / 2, pid);
		ft_send_size(size % 2, pid);
	}
}

void	ft_send_all(char *str, int serv_pid)
{
	size_t	i;
	//ssize_t	size;

	/*size = (ssize_t) ft_strlen(str);
	ft_kill_zero(size, serv_pid, 31);
	ft_send_size(size + 1, serv_pid);*/
	i = 0;
	while (str[i])
	{
		ft_kill_zero(str[i], serv_pid, 7);
		ft_convert(str[i], serv_pid);
		i++;
	}
	ft_kill_zero(0, serv_pid, 7);
}

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("bit received\n");
		return ;
	}
	if (sig == SIGUSR2)
	{
		ft_printf("Message transmitted succesfully\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3)
		return (1);
	action.sa_handler = &handle_sig;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_send_all(argv[2], ft_atoi(argv[1]));
	usleep(100000);
}