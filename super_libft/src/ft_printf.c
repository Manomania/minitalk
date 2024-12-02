/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h.c                                      :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:04:46 by maximart          #+#    #+#             */
/*   Updated: 2024/11/05 09:42:18 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_check_args(t_format fmt, va_list args)
{
	if (fmt.conversion == 'c')
		return (ft_handle_char(va_arg(args, int)));
	else if (fmt.conversion == 's')
		return (ft_handle_str(va_arg(args, char *)));
	else if (fmt.conversion == 'p')
		return (ft_handle_ptr(va_arg(args, unsigned long)));
	else if (fmt.conversion == 'd' || fmt.conversion == 'i')
		return (ft_handle_int(va_arg(args, int)));
	else if (fmt.conversion == 'u')
		return (ft_handle_nbr_unsigned(va_arg(args, unsigned int)));
	else if (fmt.conversion == 'x' || fmt.conversion == 'X')
		return (ft_handle_hexa(va_arg(args, unsigned int), fmt));
	else if (fmt.conversion == '%')
		return (ft_handle_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		args;
	t_format	fmt;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			parse_format(&format, &fmt);
			count += ft_check_args(fmt, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
