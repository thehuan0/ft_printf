/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:06:19 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/15 12:06:19 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.dot = 0;
	flags.precision = -1;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.type = 0;
	return (flags);
}
