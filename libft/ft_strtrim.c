/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:01:51 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	b;
	size_t	e;
	size_t	l;

	if (!s)
		return (NULL);
	b = 0;
	while (s[b] != '\0'
			&& (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	e = ft_strlen(s);
	while (b < e && (s[e - 1] == ' '
			|| s[e - 1] == '\n' || s[e - 1] == '\t'))
		e--;
	if (b == e)
		return (ft_strnew(0));
	l = e - b;
	return (ft_strsub(s, b, l));
}
