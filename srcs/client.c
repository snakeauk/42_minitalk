/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:07:49 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/21 04:30:37 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_sendc(const pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(100);
	}
}

void	ft_sends(const pid_t pid, char *str)
{
	while (*str)
	{
		ft_sendc(pid, *str);
		str++;
	}
	ft_sendc(pid, '\0');
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		write(STDOUT_FILENO, "Message acknowledged by server\n", 32);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./client <PID> <message>\n");
		return (EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	if (pid <= 3 || pid > 32768)
	{
		ft_dprintf(STDERR_FILENO, "Error: Invalid PID\n");
		return (EXIT_FAILURE);
	}
	ft_sends(pid, argv[2]);
	signal(SIGUSR1, handle_ack);
	return (EXIT_SUCCESS);
}
