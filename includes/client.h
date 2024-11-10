/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:08:04 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/10 18:29:02 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_sendc(const pid_t pid, char c);
void	ft_sends(const pid_t pid, char *str);
int		main(int argc, char **argv);

#endif