/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:45 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 13:11:00 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_str_precision(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	print_string(t_flags flags, va_list *args)
{
	char	*str;
	int		len;
	int		print_len;
	int		is_null;

	str = va_arg(*args, char *);
	is_null = (str == NULL);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	print_len = len;
	if (flags.dot && flags.precision < len)
		print_len = flags.precision;
	if (is_null && flags.dot && print_len < 6)
		return (apply_width(flags.width, 0, 0));
	if (flags.minus)
	{
		put_str_precision(str, print_len);
		return (print_len + apply_width(flags.width, print_len, 0));
	}
	len = apply_width(flags.width, print_len, 0);
	put_str_precision(str, print_len);
	return (len + print_len);
}
