/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:00:00 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 12:00:00 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_width(int width, int len, int zero)
{
	int		count;
	char	pad;

	count = 0;
	pad = ' ';
	if (zero)
		pad = '0';
	while (width > len)
	{
		write(1, &pad, 1);
		width--;
		count++;
	}
	return (count);
}
