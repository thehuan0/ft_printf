/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:56:38 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/15 11:56:38 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	len = num_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	nb = n;
	while (nb)
	{
		str[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
