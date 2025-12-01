/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:34:35 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 09:08:09 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	print_prec(unsigned int n, char *base, int prec, int len)
{
	while (prec > len)
	{
		ft_putchar('0');
		prec--;
	}
	ft_putnbr_base(n, base);
}

static int	get_hex_len(unsigned int n, t_flags flags)
{
	int	len;

	len = num_len(n);
	if (flags.precision > len)
		len = flags.precision;
	if (flags.hash && n != 0)
		len += 2;
	return (len);
}

static void	print_hex_prefix(int uppercase, unsigned int n, t_flags flags)
{
	if (flags.hash && n != 0)
	{
		if (uppercase)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
}

int	print_hex(t_flags flags, va_list *args, int uppercase)
{
	unsigned int	n;
	char			*base;
	int				len;

	n = va_arg(*args, unsigned int);
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (flags.dot && flags.precision == 0 && n == 0)
		return (apply_width(flags.width, 0, 0));
	len = get_hex_len(n, flags);
	if (!flags.minus && (!flags.zero || flags.dot))
		len += apply_width(flags.width, len, 0);
	print_hex_prefix(uppercase, n, flags);
	if (!flags.minus && flags.zero && !flags.dot)
		len += apply_width(flags.width, len, 1);
	if (flags.dot)
		print_prec(n, base, flags.precision, num_len(n));
	else
		ft_putnbr_base(n, base);
	if (flags.minus)
		len += apply_width(flags.width, len, 0);
	return (len);
}
