/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:59 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/11 15:47:26 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

char	*g_str;

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

char	*ft_join(char *str, char c)
{
	size_t	i;
	char	*new;

	if (!str)
		new = malloc(sizeof(char) * 2);
	else
		new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (free(str), NULL);
	if (!str)
		return (new[0] = c, new[1] = 0, new);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	return (new[i] = c, new[i + 1] = 0, free(str), new);
}

void	ft_print_bin(int *tab, int client_pid)
{
	size_t	i;
	int		c;

	i = -1;
	c = 0;
	while (++i < 8)
		c += ft_power(2, 7 - (int)(i)) * tab[i];
	g_str = ft_join(g_str, c);
	if (!g_str)
	{
		usleep(100);
		kill(client_pid, SIGUSR2);
		exit(1);
	}
	if (c == 0)
	{
		ft_printf("%s", g_str);
		usleep(100);
		free(g_str);
		g_str = NULL;
		kill(client_pid, SIGUSR2);
		return ;
	}
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	int			client_pid;
	static int	tab[8];
	static int	i = 0;

	(void) ucontext;
	client_pid = info->si_pid;
	if (sig == SIGINT)
	{
		free(g_str);
		ft_printf("\nServer closed.\n");
		exit(0);
	}
	if (sig == SIGUSR1)
		tab[i++] = 0;
	if (sig == SIGUSR2)
		tab[i++] = 1;
	if (i == 8)
	{
		i = 0;
		ft_print_bin(tab, client_pid);
	}
	usleep(100);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
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
	action.sa_sigaction = &handle_sig;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	while (1)
		pause();
}
