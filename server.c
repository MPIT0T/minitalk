/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:59 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/01 16:50:21 by mpitot           ###   ########.fr       */
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

void	ft_print_bin(int *tab, int client_pid)
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
	if (c == 0)
		kill(client_pid, SIGUSR2);
	ft_printf("%c", c);
	(void) client_pid;
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static size_t	i = 0;
	static int		tab[8];
	int				client_pid;

	(void) ucontext;
	client_pid = info->si_pid;
	(void) client_pid;
	if (sig == SIGINT)
	{
		ft_printf("\nServer closed.\n");
		exit(0);
	}
	if (sig == SIGUSR1)
		tab[i++] = 0;
	if (sig == SIGUSR2)
		tab[i++] = 1;
	kill(client_pid, SIGUSR1);
//	ft_printf("%d", tab[i - 1]);
	if (i == 8)
	{
		ft_print_bin(tab, client_pid);
		i = 0;
//		ft_printf("\n");
	}
}

void	ft_startup(int pid)
{
	ft_printf("Server loading");
	usleep(500000);
	ft_printf(".");
	usleep(500000);
	ft_printf(".");
	usleep(500000);
	ft_printf(".\n");
	usleep(500000);
	ft_printf("\033[1;35mWelcome to mpitot's server.\n");
	ft_printf("\033[1;0mThe PID is :\t");
	usleep(800000);
	ft_printf("\033[1;31m%d\033[1;0m\n", pid);
}

int	main(void)
{
	int		pid;
	struct sigaction	action;

	pid = getpid();
	ft_startup(pid);
	action.sa_sigaction = &handle_sig;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	while(1)
		pause();
}
