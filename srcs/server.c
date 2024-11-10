/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:07:53 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/10 23:21:20 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

volatile sig_atomic_t	g_char = 0;

void	signal_handler(int signum)
{
	static int	bit_count = 0;
	char		c;

	g_char = g_char << 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		c = (char)g_char;
		ft_fputc(c, STDOUT_FILENO);
		g_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_printf("Minitalk server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
