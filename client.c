/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:18:26 by jbranco-          #+#    #+#             */
/*   Updated: 2023/01/26 18:15:39 by jbranco-         ###   ########.fr       */
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
		while (str[++i])
			binary_char(pid, str[i]);
	}
}
