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

t_direct	*ft_direct_new(char *dname, t_file *file)
{
	t_direct	*dir;

	if (!(dir = (t_direct *)malloc(sizeof(t_direct))))
		print_error(NULL, 1);
	if (!dname)
		dir->dname = NULL;
	else
	{
		if (!(dir->dname = ft_strdup(dname)))
			print_error(NULL, 1);
	}
	dir->file = file;
	dir->next = NULL;
	return (dir);
}

void		ft_direct_pushb(t_direct **root, char *dname, t_ls *ls)
{
	t_direct	*new;
	t_direct	dir;

	if (*root == NULL)
	{
		*root = ft_direct_new(dname, ls->curfile);
	}
	else
	{
		new = ft_direct_new(dname, ls->curfile);
		dir.next = *root;
		ls->sort_dirs(&dir, new);
		*root = dir.next;
	}
}

void		ft_direct_del(t_direct **d)
{
	if (*d)
	{
		if ((*d)->next)
			ft_direct_del(&((*d)->next));
		if ((*d)->dname)
		{
			ft_strclr((*d)->dname);
			ft_strdel(&((*d)->dname));
		}
		free(*d);
	}
	*d = NULL;
}
