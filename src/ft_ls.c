/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:51:20 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:51:26 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*ft_file_new()
{
	t_file		*file;

	if (!(file = (t_file *) malloc(sizeof(t_file))))
		print_error(NULL, 1);
	ft_bzero(file, sizeof(t_file));
	return (file);
}

void		ft_filelist_init(t_ls *ls)
{
	t_file		*file;

	if (!(ls->filelist))
		ls->filelist = ft_file_new();
	else
	{
		file = ls->filelist->next;
		ft_bzero(ls->filelist, sizeof(t_file));
		ls->filelist->next = file;
	}
	if (ls->filelist->next)
	{
		ls->endfile = ls->filelist->next;
		file = ls->endfile->next;
		ft_bzero(ls->endfile, sizeof(t_file));
		ls->endfile->next = file;
	}
	else
	{
		ls->endfile = ft_file_new();
		ls->filelist->next = ls->endfile;
	}
	ls->endfile->prev = ls->filelist;
	ft_next_curfile(ls);
}

static void		ft_ls_init(t_ls *ls)
{
	ls->curdir = ft_direct_new(NULL, NULL);
	ls->bufdir = (void*)malloc(sizeof(void) * BUF);
	ls->buffile = (void*)malloc(sizeof(void) * BUF);
	ls->i = ls->buffile;
}

void			ft_freemem(t_ls **ls)
{
	if (*ls)
	{
		ft_del_filelist(&((*ls)->filelist));
		free((*ls)->bufdir);
		(*ls)->bufdir = NULL;
		free((*ls)->buffile);
		(*ls)->buffile = NULL;
		free(*ls);
		*ls = NULL;
	}
}

static void		ft_read_func_sort(t_ls *ls)
{
	if ((ls->fl & LS_T) && (ls->fl & LS_R))
	{
		ls->sort_files = ft_sort_files_t_r;
		ls->sort_dirs = ft_sort_dirs_t_r;
	}
	else if (ls->fl & LS_T)
	{
		ls->sort_files = ft_sort_files_t;
		ls->sort_dirs = ft_sort_dirs_t;
	}
	else if (ls->fl & LS_R)
	{
		ls->sort_files = ft_sort_files_r;
		ls->sort_dirs = ft_sort_dirs_r;
	}
	else
	{
		ls->sort_files = ft_sort_files;
		ls->sort_dirs = ft_sort_dirs;
	}
}

void			ft_read_func(t_ls *ls)
{
	if (ls->fl & LS_L)
			ls->ls_func = ft_read_dir_l;
	else
		ls->ls_func = ft_read_dir;
	ft_read_func_sort(ls);
}

void			ft_ls(char *fname, char d, t_ls *ls)
{
	ft_read_func(ls);
	if (!(ls->bufdir))
		ft_ls_init(ls);
	if (!d)
		ft_ls_file(fname, ls);
	else if (d && fname && *fname)
	{
		if (d == 2)
		{
			ft_putstr(fname);
			ft_putendl(":");
		}
		ls->curdir->dname = fname;
		ft_ls_l(ls);
		//ft_del_filelist(&(ls->filelist));
//		ls->dirlist = ft_dirlist_init(ls, ft_strlen(fname), fname);
	}
}
