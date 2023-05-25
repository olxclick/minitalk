/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:29 by jbranco-          #+#    #+#             */
/*   Updated: 2023/01/28 17:03:26 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
SIGUSR1 == 0
SIGUSR2 == 1
*/
void	binary_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(50);
	}
}

void	handler(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Received.\n", 10);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	if (argc == 3)
	{
		i = -1;
		str = argv[2];
		pid = ft_atoi(argv[1]);
		signal(SIGUSR2, &handler);
		while (str[++i])
			binary_char(pid, str[i]);
	}
}
