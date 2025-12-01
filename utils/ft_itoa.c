/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:55:23 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/15 11:55:23 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	len = num_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	if (n == 0)
		str[0] = '0';
	while (nbr)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
