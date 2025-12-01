/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:00:00 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 09:07:02 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	parse_flags_chars(const char *format, int *i, t_flags *flags)
{
	while (is_flag(format[*i]))
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
}

void	parse_width(const char *format, int *i, t_flags *flags)
{
	flags->width = 0;
	while (is_digit(format[*i]))
	{
		flags->width = flags->width * 10 + (format[*i] - '0');
		(*i)++;
	}
}
