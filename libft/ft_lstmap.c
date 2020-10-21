/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:40:31 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flst;
	t_list	*t1;
	t_list	*t2;

	if (!lst || !f)
		return (NULL);
	t2 = f(lst);
	if ((flst = ft_lstnew(t2->content, t2->content_size)))
	{
		t1 = flst;
		lst = lst->next;
		while (lst)
		{
			t2 = f(lst);
			if (!(t1->next = ft_lstnew(t2->content, t2->content_size)))
				return (NULL);
			t1 = t1->next;
			lst = lst->next;
		}
	}
	return (flst);
}
