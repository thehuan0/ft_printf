/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:33:22 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 09:08:37 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num_len(char *str, t_flags flags)
{
	int	len;

	len = ft_strlen(str);
	if (flags.precision > len && str[0] != '-')
		len = flags.precision;
	if (flags.precision > (ft_strlen(str) - 1) && str[0] == '-')
		len = flags.precision + 1;
	if ((flags.plus || flags.space) && str[0] != '-')
		len++;
	return (len);
}

static void	print_sign(char *str, t_flags flags)
{
	if (str[0] == '-')
		ft_putchar('-');
	else if (flags.plus)
		ft_putchar('+');
	else if (flags.space)
		ft_putchar(' ');
}

static void	print_precision(char *str, t_flags flags)
{
	int	prec;
	int	len;
	int	start;

	start = 0;
	if (str[0] == '-')
		start = 1;
	len = ft_strlen(str) - start;
	prec = flags.precision - len;
	while (prec > 0)
	{
		ft_putchar('0');
		prec--;
	}
	ft_putstr(str + start);
}

static int	print_number_content(char *str, t_flags flags, int len)
{
	print_sign(str, flags);
	if (!flags.minus && flags.zero && !flags.dot)
		len += apply_width(flags.width, len, 1);
	if (flags.dot)
		print_precision(str, flags);
	else
		ft_putstr(str + (str[0] == '-'));
	if (flags.minus)
		len += apply_width(flags.width, len, 0);
	return (len);
}

int	print_number(t_flags flags, va_list *args)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(*args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	if (flags.dot && flags.precision == 0 && n == 0)
	{
		len = apply_width(flags.width, 0, 0);
		return (free(str), len);
	}
	len = get_num_len(str, flags);
	if (!flags.minus && (!flags.zero || flags.dot))
		len += apply_width(flags.width, len, 0);
	len = print_number_content(str, flags, len);
	return (free(str), len);
}
