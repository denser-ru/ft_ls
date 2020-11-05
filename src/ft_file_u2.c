/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_u2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:50:10 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:50:13 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_itoa_mem_x(void *dest, unsigned int nb)
{
	const char	*hex = "0123456789abcdef";
	int		i;
	char	buf[8];

	i = 0;
	ft_memset(buf, '0', 8);
	ft_memset(dest, '0', 10);
	((char*)dest)[1] = 'x';
	dest += 2;
	while (nb > 0)
	{
		buf[i++] = hex[nb % 16];
		nb /= 16;
	}
	i = 7;
	while (i >= 0)
	{
		*(char*)(dest + 7 - i) = (char)buf[i];
		--i;
	}
	return (9);
}