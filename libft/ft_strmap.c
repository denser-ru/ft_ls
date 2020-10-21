/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:53:41 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*buf;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(buf = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i++])
		buf[i - 1] = (*f)(s[i - 1]);
	buf[i - 1] = '\0';
	return (buf);
}
