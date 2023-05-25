/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:45:12 by jbranco-          #+#    #+#             */
/*   Updated: 2023/01/29 16:57:27 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SIGUSR1 == 0
SIGUSR2 == 1
*/

#include "minitalk.h"

void	handle(int signal)
{
	static char	letter = 0;
	static int	bits = 0;

	if (signal == SIGUSR2)
		letter += 1 << bits;
	if (bits == 7)
	{
		write(1, &letter, 1);
		bits = 0;
		letter = 0;
	}
	else
		bits++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, &handle);
		signal(SIGUSR2, &handle);
		pause();
	}
}
