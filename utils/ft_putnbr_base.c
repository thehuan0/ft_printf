/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:57:43 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/15 11:57:43 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
}
