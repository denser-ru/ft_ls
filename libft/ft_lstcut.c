/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:03:07 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:11:42 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcut(t_list **root, t_list *cut, void (*del)(void *, size_t))
{
	t_list			*prev;
	t_list			*cur;
	t_list			*next;

	prev = *root == cut ? cut->next : *root;
	if ((*root = prev) == cut->next)
	{
		ft_lstdelone(&cut, del);
		return ;
	}
	cur = *root;
	next = NULL;
	while (cur)
	{
		if (cur == cut)
		{
			prev->next = next;
			ft_lstdelone(&cut, del);
			return ;
		}
		prev = cur;
		cur = cur->next;
		next = cur ? cur->next : NULL;
	}
}
