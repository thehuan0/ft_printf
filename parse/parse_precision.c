/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:06:23 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 09:06:27 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(const char *format, int *i, t_flags *flags)
{
	if (format[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		flags->precision = 0;
		while (is_digit(format[*i]))
		{
			flags->precision = flags->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
}

void	parse_flags(const char *format, int *i, t_flags *flags)
{
	(*i)++;
	parse_flags_chars(format, i, flags);
	parse_width(format, i, flags);
	parse_precision(format, i, flags);
	flags->type = format[*i];
}
