/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:59 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/06 18:03:49 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int nb, ssize_t power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_power(nb, power - 1));
}
/*

static void	ft_free(int **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i]);
	free(tab);
}
*/

void	ft_print_bin(int *tab, int client_pid, int *reset)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c += ft_power(2, 7 - (int) (i)) * tab[i];
		i++;
	}
	ft_printf("%c", c);
	if (c == 0)
	{
		*reset = 0;
		kill(client_pid, SIGUSR2);
	}
	return ;
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	int			client_pid;
	static int	tab[8];
	static int	i = 0;
	(void) ucontext;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		tab[i++] = 0;
	if (sig == SIGUSR2)
		tab[i++] = 1;
	if (i == 8)
	{
		i = 0;
		ft_print_bin(tab,client_pid, &i);
	}
	kill(client_pid, SIGUSR1);
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
	//sigaction(SIGINT, &action, NULL);
	while(1)
	{
		pause();
	}
}
