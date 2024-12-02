#include <stdlib.h>

#include "minitalk.h"

#include <signal.h>
#include <unistd.h>

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024



void	handle_signal(int signal)
{
	static unsigned char	buffer[BUFFER_SIZE + 1];
	static unsigned char	current_char = 0;
	static int				bit_index = 0;
	static int				char_index = 0;

	if (signal == SIGUSR1)
		current_char |= (0x01 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		buffer[char_index] = current_char;
		if (current_char == '\0' || char_index == BUFFER_SIZE - 1)
		{
			buffer[char_index] = '\0';
			ft_printf("%s", buffer);
			ft_bzero(buffer, BUFFER_SIZE);
			char_index = 0;
		}
		else
			char_index++;
		current_char = 0;
		bit_index = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction act;
	pid_t pid;

	(void)argv;
	act.sa_handler = handle_signal;
	if (argc != 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	pid = getpid();
	printf("Server PID: %d\n", pid);
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return (0);
}




