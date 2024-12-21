/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:07:53 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/21 04:09:15 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static int bit = 0;
    static char c = 0;

    (void)context;

	c = c << 1;
	if (sig == SIGUSR1)
		c |= 1;
    bit++;
    if (bit == 8)
	{
        if (c == '\0')
		{
			ft_fputs("\n", STDOUT_FILENO);
            kill(info->si_pid, SIGUSR1);
        }
		else
            write(STDOUT_FILENO, &c, 1);
        bit = 0;
        c = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
	ft_printf("Minitalk server PID: %d\n", getpid());
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    while (1)
        pause();
}
// volatile sig_atomic_t	g_char = 0;

// void	signal_handler(int signum)
// {
// 	static int	bit_count = 0;
// 	char		c;

// 	g_char = g_char << 1;
// 	if (signum == SIGUSR1)
// 		g_char |= 1;
// 	bit_count++;
// 	if (bit_count == 8)
// 	{
// 		c = (char)g_char;
// 		ft_fputc(c, STDOUT_FILENO);
// 		g_char = 0;
// 		bit_count = 0;
// 	}
// }

// int	main(void)
// {
// 	ft_printf("Minitalk server PID: %d\n", getpid());
// 	signal(SIGUSR1, signal_handler);
// 	signal(SIGUSR2, signal_handler);
// 	while (1)
// 		pause();
// }
