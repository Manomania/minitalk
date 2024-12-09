/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:12:02 by maximart          #+#    #+#             */
/*   Updated: 2024/12/04 12:12:05 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	add_message(t_message *message, char c)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return ;
	str[0] = c;
	str[1] = '\0';
	ft_lstadd_back(&message->list, ft_lstnew(str));
}

void	clear_and_print_message(t_message *message)
{
	t_list	*current;

	current = message->list;
	while (current)
	{
		ft_printf("%s", (char *)current->content);
		current = current->next;
	}
	ft_printf("\n");
	ft_lstclear(&message->list, free);
	message->list = NULL;
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static t_message	message = {NULL, 0, 0};

	(void)context;
	if (signal == SIGUSR1)
		message.c_char |= (0x01 << message.bit_index);
	message.bit_index++;
	if (message.bit_index == 8)
	{
		if (message.c_char == '\0')
		{
			clear_and_print_message(&message);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			add_message(&message, message.c_char);
		}
		message.c_char = 0;
		message.bit_index = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				pid;

	(void)argv;
	act.sa_sigaction = handle_signal;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (argc != 1)
	{
		ft_printf("\033[91mError: Too many arguments\033[0m\n");
		return (1);
	}
	pid = getpid();
	ft_printf("\033[94mPID ->\033[0m %d\n", pid);
	while (1)
		pause();
	return (0);
}
