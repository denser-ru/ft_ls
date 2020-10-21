/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:56:56 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(buf = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i++])
		buf[i - 1] = (*f)(i - 1, s[i - 1]);
	buf[i - 1] = '\0';
	return (buf);
}
