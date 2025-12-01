/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:34:10 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 09:08:56 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_precision(char *str, int precision)
{
	int	prec;
	int	len;

	len = ft_strlen(str);
	prec = precision - len;
	while (prec > 0)
	{
		ft_putchar('0');
		prec--;
	}
	ft_putstr(str);
}

static int	print_unsigned_content(char *str, t_flags flags, int len)
{
	if (!flags.minus && flags.zero && !flags.dot)
		len += apply_width(flags.width, len, 1);
	if (flags.dot)
		print_precision(str, flags.precision);
	else
		ft_putstr(str);
	if (flags.minus)
		len += apply_width(flags.width, len, 0);
	return (len);
}

int	print_unsigned(t_flags flags, va_list *args)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(*args, unsigned int);
	str = ft_utoa(n);
	if (!str)
		return (0);
	if (flags.dot && flags.precision == 0 && n == 0)
	{
		len = apply_width(flags.width, 0, 0);
		return (free(str), len);
	}
	len = ft_strlen(str);
	if (flags.precision > len)
		len = flags.precision;
	if (!flags.minus && (!flags.zero || flags.dot))
		len += apply_width(flags.width, len, 0);
	len = print_unsigned_content(str, flags, len);
	return (free(str), len);
}
