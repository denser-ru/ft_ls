/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_direct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:53:07 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/29 14:53:09 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_direct	*ft_direct_new(void const *content, size_t content_size, t_file *file)
{
	t_direct	*dir;

	if (!(dir = (t_direct *)malloc(sizeof(t_direct))))
		print_error(NULL, 1);
	if (!content)
	{
		dir->content = NULL;
		dir->content_size = 0;
	}
	else
	{
		if (!(dir->content = malloc(content_size)))
		{
			free(dir);
			return (NULL);
		}
		ft_memcpy(dir->content, content, content_size);
		dir->content_size = content_size;
	}
	dir->file = file;
	dir->next = NULL;
	return (dir);

}

t_direct	*ft_direct_pushb(t_direct **root, void *content, size_t content_size, t_file *file)
{
	t_direct	*new;
	t_direct	*cur;

	cur = *root;
	if (*root == NULL)
		*root = ft_direct_new(content, content_size, file);
	else
	{
		new = ft_direct_new(content, content_size, file);
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	return (*root);
}
