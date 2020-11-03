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

void			ft_ls_l(t_ls *ls)
{
	DIR			*dir;
	t_dirent	*dirp;
	t_direct	*dirlist;

	dirp = NULL;
	ft_strcpy(ls->fname, ls->curdir->dname);
	dirlist = NULL;
	errno = 0;
	if (!(dir = opendir(ls->fname)))
		print_error_dir(ls->curdir->dname, 0);
	else
	{
		ls->ls_func(ls, dirp, dir, (ls->fl & LS_RR ? &dirlist : NULL));
		closedir(dir);
		ft_direct_del_cur(&(ls->curdir));
		while (dirlist)
		{
			ls->curdir = dirlist;
			ft_ls_rec(ls);
			dirlist = dirlist->next;
		}
	}
	ft_direct_del(&dirlist);
}

static void		ft_ls_rec_b(t_ls *ls, t_direct **dirlist)
{
	*dirlist = NULL;
	ft_putstr(ls->fname);
	ft_putstr(":\n");
}

void			ft_ls_rec(t_ls *ls)
{
	DIR			*dir;
	t_dirent	*dirp;
	t_direct	*dirlist;
	t_direct	*curlist;

	ft_putchar('\n');
	dirp = NULL;
	ft_strcpy(ls->fname, ls->curdir->dname);
	ft_ls_rec_b(ls, &dirlist);
	errno = 0;
	if (!(dir = opendir(ls->fname)))
		print_error_dir(ls->curdir->dname, 0);
	else
	{
		ls->ls_func(ls, dirp, dir, &dirlist);
		closedir(dir);
		curlist = dirlist;
		while (curlist)
		{
			ls->curdir = curlist;
			ft_ls_rec(ls);
			curlist = curlist->next;
		}
	}
	ft_direct_del(&dirlist);
}
