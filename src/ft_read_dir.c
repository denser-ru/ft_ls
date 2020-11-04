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
	ft_get_size(ls, stat, 0, 0);
	ft_get_ctime(ls, stat);
	if (S_ISLNK(stat->st_mode))
		ft_get_symlink(ls);
}

void			ft_read_file(char *fname, t_ls *ls, char d)
{
	t_stat	stat;
	size_t	size;

	if (!ls->curfile)
	{
		ft_filelist_init(ls);
		ls->i = ls->buffile;
	}
	ft_init_max_size(ls, 0);
	ls->dirsize = 0;
	ls->curfile->adr = ls->i;
	size = ft_strlen(fname);
	ft_memcpy(ls->i, fname, size);
	ls->i += size;
	ls->curfile->size[5] = size;
	lstat(fname, &stat);
	ft_get_stat(ls, &stat);
	ft_get_spot(ls, fname);
//	ls->i = NULL;
	if (d == 4)
	{
		if (ls->fl & LS_L)
			ft_print_dir_l(ls, ls->filelist, 0);
		else
			ft_print_dir(ls, ls->filelist, 0);
	}
	ft_direct_del_cur(&(ls->curdir));
}

static void		ft_ifdir(t_ls *ls, t_stat stat, t_direct **dirl, t_dirent *dirp)
{
	if (dirl && S_ISDIR(stat.st_mode) &&
		ft_strcmp(dirp->d_name, ".") && ft_strcmp(dirp->d_name, ".."))
		ft_direct_pushb(dirl, ls->fname, ls);
}

void			ft_read_dir_l(t_ls *ls, t_dirent *dirp, DIR *dir, \
										t_direct **dirlist)
{
	t_stat	stat;

	ft_filelist_init(ls);
	ls->i = ls->buffile;
	ft_init_max_size(ls, 0);
	ls->dirsize = 0;
	while ((dirp = ft_get_dirp(dirp, dir, ls->fl)))
	{
		ls->curfile->adr = ls->i;
		ft_get_fname(ls, dirp, ls->fname);
		if ((lstat(ls->fname, &stat)) == -1 && errno != 0)
			print_error(dirp->d_name, 0);
		else
		{
			ft_get_stat(ls, &stat);
			ft_ifdir(ls, stat, dirlist, dirp);
			ft_get_spot(ls, dirp->d_name);
		}
		errno = 0;
	}
	if (!(errno))
		ft_print_dir_l(ls, ls->filelist, 0);
	else
		print_error_dir(ls->curdir->dname, 0);
}

void			ft_read_dir(t_ls *ls, t_dirent *dirp, DIR *dir, \
						t_direct **dirlist)
{
	t_stat	stat;

	ft_filelist_init(ls);
	ls->i = ls->buffile;
	ft_init_max_size(ls, 0);
	ls->dirsize = 0;
	while ((dirp = ft_get_dirp(dirp, dir, ls->fl)))
	{
		ls->curfile->adr = ls->i;
		ft_get_fname(ls, dirp, ls->fname);
		if ((lstat(ls->fname, &stat)) == -1 && errno != 0)
			print_error(dirp->d_name, 0);
		else
		{
			ft_get_stat(ls, &stat);
			ft_ifdir(ls, stat, dirlist, dirp);
			ft_get_spot(ls, dirp->d_name);
		}
		errno = 0;
	}
	if (!(errno))
		ft_print_dir(ls, ls->filelist, 0);
	else
		print_error_dir(ls->curdir->dname, 0);
}
