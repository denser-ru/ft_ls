/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:52:29 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:52:31 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_stat(t_ls *ls, t_stat *stat)
{
	ft_get_mode(ls, stat);
	ft_get_nlink(ls, stat);
	ft_get_pwd(ls, stat);
	ft_get_size(ls, stat);
	ft_get_ctime(ls, stat);
}

void			ft_read_dir_l(t_ls *ls, t_dirent *dirp, DIR *dir,
					t_list **dirlist)
{
	t_stat	stat;

	ls->i = ls->buffile;
	ft_init_max_size(ls, 0);
	ls->dirsize = 0;
	ls->curfile = ls->filelist;
	while ((dirp = ft_get_dirp(dirp, dir , ls->fl)))
	{
		ls->curfile->adr = ls->i;
		ft_get_fname(ls, dirp, ls->fname);
		lstat(ls->fname, &stat);
		if ((stat.st_mode & S_IFDIR) && ft_strcmp(dirp->d_name, ".") &&
				ft_strcmp(dirp->d_name, ".."))
			ft_lstpushb(dirlist, ls->fname, ft_strlen(ls->fname));
		ft_get_stat(ls, &stat);
		if (!(ls->curfile->next))
			ft_add_file(ls);
		else
			ls->curfile = ls->curfile->next;
	}
	ls->curfile->adr = NULL;
	ls->sort_dirs(ls);
	ls->sort_files(ls);
	ft_print_dir_l(ls, ls->filelist, 0);
}

void			ft_read_dir(t_ls *ls, t_dirent *dirp, DIR *dir,
					t_list **dirlist)
{
	t_stat	stat;

	ls->i = ls->buffile;
	ls->curfile = ls->filelist;
	while ((dirp = ft_get_dirp(dirp, dir , ls->fl)))
	{
		ls->curfile->adr = ls->i;
		ft_get_fname(ls, dirp, ls->fname);
		lstat(ls->fname, &stat);
		if ((stat.st_mode & S_IFDIR) && ft_strcmp(dirp->d_name, ".") &&
				ft_strcmp(dirp->d_name, ".."))
			ft_lstpushb(dirlist, ls->fname, ft_strlen(ls->fname));
		ft_get_stat(ls, &stat);
		if (!(ls->curfile->next))
			ft_add_file(ls);
		else
			ls->curfile = ls->curfile->next;
	}
	ls->curfile->adr = NULL;
	ls->sort_dirs(ls);
	ls->sort_files(ls);
	ft_print_dir(ls, ls->filelist, 0);
}