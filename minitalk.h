/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:55:37 by maximart          #+#    #+#             */
/*   Updated: 2024/12/09 10:50:14 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "super_libft/include/libft.h"
# include <signal.h>

volatile sig_atomic_t	g_ack = 1;

typedef struct s_message
{
	t_list	*list;
	char	c_char;
	int		bit_index;
}			t_message;

#endif