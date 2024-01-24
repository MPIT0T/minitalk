/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:59 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/24 16:24:40 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int		pid;

	pid = getpid();
	while (1)
	{
		printf("Server listening...\tPID : %d\n", pid);		//TODO ftprintf
		sleep(5);
	}
	return (0);
}