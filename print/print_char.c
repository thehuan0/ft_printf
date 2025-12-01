/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:12:50 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 12:00:00 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_flags flags, va_list *args)
{
	char	c;
	int		len;

	c = va_arg(*args, int);
	len = 0;
	if (flags.minus)
	{
		ft_putchar(c);
		len += apply_width(flags.width, 1, 0);
	}
	else
	{
		len += apply_width(flags.width, 1, 0);
		ft_putchar(c);
	}
	return (len + 1);
}
