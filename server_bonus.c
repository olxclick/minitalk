/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:57 by jbranco-          #+#    #+#             */
/*   Updated: 2023/01/28 17:03:18 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SIGUSR1 == 0
SIGUSR2 == 1
*/

#include "minitalk.h"

void	handle(int signal, siginfo_t *siginfo, void *context)
{
	static char	letter = 0;
	static int	bits = 0;
	int			client_pid;

	(void)context;
	client_pid = siginfo-> si_pid;
	if (signal == SIGUSR2)
		letter += 1 << bits;
	if (bits == 7)
	{
		write(1, &letter, 1);
		kill(client_pid, SIGUSR2);
		bits = 0;
		letter = 0;
	}
	else
		bits++;
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
