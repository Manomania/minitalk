/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:26:51 by maximart          #+#    #+#             */
/*   Updated: 2024/11/14 10:27:06 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar(const char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_handle_char(int c)
{
	return (ft_putchar(c));
}

int	ft_handle_percent(void)
{
	return (ft_putchar('%'));
}

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}

int	ft_handle_str(const char *str)
{
	return (ft_putstr(str));
}
