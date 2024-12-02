/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:35 by maximart          #+#    #+#             */
/*   Updated: 2024/11/13 14:17:39 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printmemory(unsigned long n)
{
	int			count;
	const char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_printmemory(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_printmemory(ptr);
	return (count);
}

int	ft_handle_ptr(unsigned long ptr)
{
	return (ft_putptr(ptr));
}
