/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:33:59 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 12:00:00 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	t_flags	flags;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			flags = init_flags();
			parse_flags(format, &i, &flags);
			len += print_dispatch(flags, &args);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
