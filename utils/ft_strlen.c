/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:00:55 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/15 13:00:02 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
