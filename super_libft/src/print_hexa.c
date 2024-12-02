/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:27:39 by maximart          #+#    #+#             */
/*   Updated: 2024/11/11 13:27:42 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_puthexa(unsigned int n, int upper)
{
	int			count;
	const char	*base;

	if (upper)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16, upper);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_handle_hexa(unsigned int n, t_format fmt)
{
	int	count;

	count = 0;
	if (fmt.conversion == 'x')
		count += ft_puthexa(n, 1);
	else if (fmt.conversion == 'X')
		count += ft_puthexa(n, 0);
	return (count);
}
