/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:49:43 by cayako            #+#    #+#             */
/*   Updated: 2019/11/01 02:17:37 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lststrsplit(char const *s, char c)
{
	t_list		*root;
	const char	*e;

	root = NULL;
	if (!(s))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (!(e = ft_strchr(s, c)))
			e = s + ft_strlen(s);
		if (e != s)
			ft_lstpushb(&root, (void *)s, e - s);
		s = e;
	}
	return (root);
}
