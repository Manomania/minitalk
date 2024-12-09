/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:12:24 by maximart          #+#    #+#             */
/*   Updated: 2024/12/09 10:50:25 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
