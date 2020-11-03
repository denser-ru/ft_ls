/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filemode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:51:00 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:51:02 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_umode(t_ls *ls, t_stat *stat)
{
	if (stat->st_mode & S_IRUSR)
		ft_memset(ls->i + 1, 'r', 1);
	if (stat->st_mode & S_IWUSR)
		ft_memset(ls->i + 2, 'w', 1);
	if (stat->st_mode & S_ISUID)
	{
		if (stat->st_mode & S_IXUSR)
			ft_memset(ls->i + 3, 's', 1);
		else
			ft_memset(ls->i + 3, 'S', 1);
	}
	else
	{
		if (stat->st_mode & S_IXUSR)
			ft_memset(ls->i + 3, 'x', 1);
	}
}

static void		ft_get_gmode(t_ls *ls, t_stat *stat)
{
	if (stat->st_mode & S_IRGRP)
		ft_memset(ls->i + 4, 'r', 1);
	if (stat->st_mode & S_IWGRP)
		ft_memset(ls->i + 5, 'w', 1);
	if (stat->st_mode & S_ISGID)
	{
		if (stat->st_mode & S_IXGRP)
			ft_memset(ls->i + 6, 's', 1);
		else
			ft_memset(ls->i + 6, 'S', 1);
	}
	else
	{
		if (stat->st_mode & S_IXGRP)
			ft_memset(ls->i + 6, 'x', 1);
	}
}

static void		ft_get_omode(t_ls *ls, t_stat *stat)
{
	if (stat->st_mode & S_IROTH)
		ft_memset(ls->i + 7, 'r', 1);
	if (stat->st_mode & S_IWOTH)
		ft_memset(ls->i + 8, 'w', 1);
	if (stat->st_mode & S_ISVTX)
	{
		if (stat->st_mode & S_IXOTH)
			ft_memset(ls->i + 9, 't', 1);
		else
			ft_memset(ls->i + 9, 'T', 1);
	}
	else
	{
		if (stat->st_mode & S_IXOTH)
			ft_memset(ls->i + 9, 'x', 1);
	}
}

void			ft_get_symlink(t_ls *ls)
{
	ssize_t		len;

	if ((len = readlink(ls->fname, ls->bufdir, BUF)) == -1)
		print_error(ls->fname, 0);
	else
	{
		ft_memcpy(ls->i, " -> ", 4);
		ft_memcpy(ls->i + 4, ls->bufdir, len);
		ls->curfile->size[6] = len + 4;
		ls->i += len + 4;
	}
}

void			ft_get_mode(t_ls *ls, t_stat *stat)
{
	ft_memset(ls->i, '-', 10);
	ft_memset(ls->i + 10, ' ', 1);
	if (S_ISDIR(stat->st_mode))
		ft_memset(ls->i, 'd', 1);
	else if (S_ISLNK(stat->st_mode))
		ft_memset(ls->i, 'l', 1);
	else if (S_ISSOCK(stat->st_mode))
		ft_memset(ls->i, 's', 1);
	else if (S_ISCHR(stat->st_mode))
		ft_memset(ls->i, 'c', 1);
	else if (S_ISBLK(stat->st_mode))
		ft_memset(ls->i, 'b', 1);
	else if (S_ISFIFO(stat->st_mode))
		ft_memset(ls->i, 'p', 1);
	ft_get_umode(ls, stat);
	ft_get_gmode(ls, stat);
	ft_get_omode(ls, stat);
	ls->i += 11;
	ls->curfile->mode = stat->st_mode;
}
