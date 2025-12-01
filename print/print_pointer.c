/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:32:40 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 09:08:51 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned long n)
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

static int	print_nil(t_flags flags)
{
	int	len;

	if (flags.minus)
	{
		ft_putstr("(nil)");
		return (5 + apply_width(flags.width, 5, 0));
	}
	len = apply_width(flags.width, 5, 0);
	ft_putstr("(nil)");
	return (len + 5);
}

int	print_pointer(t_flags flags, va_list *args)
{
	unsigned long	ptr;
	int				len;

	ptr = (unsigned long)va_arg(*args, void *);
	if (ptr == 0)
		return (print_nil(flags));
	len = 2 + num_len(ptr);
	if (flags.minus)
	{
		write(1, "0x", 2);
		ft_putnbr_base(ptr, "0123456789abcdef");
		return (len + apply_width(flags.width, len, 0));
	}
	len += apply_width(flags.width, len, 0);
	write(1, "0x", 2);
	ft_putnbr_base(ptr, "0123456789abcdef");
	return (len);
}
