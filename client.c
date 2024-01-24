/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:56 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/24 20:56:00 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_ctob(int c, char *str)
{
	size_t	i;

	i = 0;
	while (i < 9)
		str[i++] = 0;

}

char	**ft_encrypt(char *str)
{
	size_t	i;
	size_t	size;
	int		tmp;
	char	**tab;

	size = ft_strlen(str);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tab[i] = malloc(sizeof(char) * 9);
		if (!tab[i])
			return (NULL);
		ft_ctob(str[i], tab[i]);
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	int		serv_pid;

	if (argc != 3)
		return (1);
	serv_pid = atoi(argv[1]);

}