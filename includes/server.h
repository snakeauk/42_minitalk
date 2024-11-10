/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:08:10 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/10 18:30:19 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERVER_H
# define SERVER_H

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	signal_handler(int signum);
int		main(void);

#endif