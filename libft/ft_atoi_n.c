/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:45:05 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_n(const char *str, size_t n)
{
	long	nbr;
	int		neg;

	while (ft_iswhitespace(*str) && n--)
		++str;
	neg = (*str == '-');
	if (*str == '+' || *str == '-')
	{
		++str;
		--n;
	}
	nbr = 0;
	while (n-- && ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		if (nbr * 10 < nbr)
			return ((neg) ? 0 : -1);
		++str;
	}
	return (neg ? (int)(-nbr) : (int)nbr);
}
