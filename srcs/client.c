/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:07:49 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/10 18:36:16 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_sendc(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
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
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_dprintf(STDERR_FILENO, "Usage: %s <PID> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	ft_sends(pid, argv[2]);
	return (EXIT_SUCCESS);
}
