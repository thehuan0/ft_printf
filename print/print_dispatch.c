/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dispatch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:12:02 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/15 12:12:02 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dispatch(t_flags flags, va_list *args)
{
	if (flags.type == 'c')
		return (print_char(flags, args));
	if (flags.type == 's')
		return (print_string(flags, args));
	if (flags.type == 'p')
		return (print_pointer(flags, args));
	if (flags.type == 'd' || flags.type == 'i')
		return (print_number(flags, args));
	if (flags.type == 'u')
		return (print_unsigned(flags, args));
	if (flags.type == 'x')
		return (print_hex(flags, args, 0));
	if (flags.type == 'X')
		return (print_hex(flags, args, 1));
	if (flags.type == '%')
		return (print_percent(flags));
	return (0);
}
