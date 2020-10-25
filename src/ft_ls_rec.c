/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:51:47 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:51:50 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_rec(t_ls *ls)
{
	DIR			*dir;
	t_dirent	*dirp;
	t_list		*dirlist;
	t_list		*curlist;

	dirp = NULL;
	ft_memcpy(ls->fname, ls->curdir->content, ls->curdir->content_size);
	ft_memset(ls->fname + ls->curdir->content_size, '\0', 1);
	dirlist = NULL;
	dir = opendir(ls->fname);
	ft_putstr(ls->fname);
	ft_putstr(":\n");
	//ft_read_dir(ls, dirp, dir, &dirlist);
	ls->ft_ls_func(ls, dirp, dir, &dirlist);
	closedir(dir);
	curlist = dirlist;
	while (curlist)
	{
		ft_putchar('\n');
		ls->curdir = curlist;
		ft_ls_rec(ls);
		curlist = curlist->next;
	}
	ft_lstdel(&dirlist, &ft_lstdelcontent);
}
