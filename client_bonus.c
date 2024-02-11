/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:45:38 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/10 14:47:39 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <signal.h>

static ssize_t	ft_power(int nb, ssize_t power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_power(nb, power - 1));
}

static void	ft_convert(int c, int pid)
{
	if (c < 2)
	{
		usleep(100);
		if (c == 0)
			kill(pid, SIGUSR1);
		else if (c == 1)
			kill(pid, SIGUSR2);
		pause();
	}
	else
	{
		ft_convert(c / 2, pid);
		ft_convert(c % 2, pid);
	}
}

static void	ft_kill_zero(ssize_t n, int pid, ssize_t i)
{
	while (i >= 0)
	{
		if (ft_power(2, i) > n)
		{
			usleep(100);
			kill(pid, SIGUSR1);
			pause();
		}
		else
			return ;
		i--;
	}
}

static void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		usleep(200);
		ft_printf("\nProgram interrupted.\n");
		ft_printf("You might want to restart the server,\n");
		ft_printf("as things might be broken.\n");
		exit(0);
	}
	if (sig == SIGUSR1)
		return ;
	if (sig == SIGUSR2)
	{
		ft_printf("Message transmitted.");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	size_t				i;

	if (argc != 3)
		return (1);
	action.sa_handler = &handle_sig;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	i = 0;
	while (argv[2][i])
	{
		ft_kill_zero(argv[2][i], ft_atoi(argv[1]), 7);
		ft_convert(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	ft_kill_zero(0, ft_atoi(argv[1]), 7);
	usleep(100);
}
