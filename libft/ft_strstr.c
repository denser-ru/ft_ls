/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:28:04 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	l;

	l = ft_strlen(needle);
	if (!l)
		return ((char *)haystack);
	while ((haystack = ft_memchr(haystack, *needle, ft_strlen(haystack))))
	{
		if (!ft_memcmp(haystack, needle, l))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
