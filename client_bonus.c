/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:11:20 by maximart          #+#    #+#             */
/*   Updated: 2024/12/04 12:11:26 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"


void	handle_ack(int signal)
{
	g_ack = 0;
	if (signal == SIGUSR2)
		ft_printf("\033[92mMessage send\033[0m");
}

void	send_char(pid_t pid, unsigned char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ack)
			pause();
		g_ack = 1;
		i++;
	}
}

void	send_message(pid_t pid, const char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t		pid;

	act.sa_handler = handle_ack;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else if (argc > 3)
	{
		ft_printf("\033[91mError: Too many arguments\033[0m\n");
		return (1);
	}
	else
	{
		ft_printf("\033[91mError: Not enough arguments\033[0m\n");
		return (1);
	}
	return (0);
}