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

static void		*ft_dirlist_init(t_ls *ls, int size, char *fname)
{
	t_direct	*dirlist;
	char		*rootdir_name;

	rootdir_name = fname;
	if (rootdir_name[size - 1] == '/' && size > 1 && rootdir_name[size] != '\0')
		--size;
	dirlist = ft_lstnew(rootdir_name, size);
	ls->curdir = dirlist;
	return (dirlist);
}

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

static void		ft_ls_init(t_ls *ls, char *fname)
{
	ls->dirlist = ft_dirlist_init(ls, ft_strlen(fname), fname);
	ls->bufdir = (void*)malloc(sizeof(void) * BUF);
	ls->buffile = (void*)malloc(sizeof(void) * BUF);
	ls->i = ls->buffile;
	ft_filelist_init(ls);
}

void			ft_freemem(t_ls *ls, t_list **list)
{
	ft_del_filelist(&(ls->filelist));
	ft_lstdel(list, ft_lstdelcontent);
	free(ls->bufdir);
	free(ls->buffile);
	free(ls);
}

static void		ft_read_func_sort(t_ls *ls)
{
	if ((ls->fl & LS_T) && (ls->fl & LS_R))
	{
		ls->sort_files = ft_sort_files_t_r;
//		ls->sort_dirs = ft_sort_dirs_r;
	}
	else if (ls->fl & LS_T)
	{
		ls->sort_files = ft_sort_files_t;
//		ls->sort_dirs = ft_sort_dirs;
	}
	else if (ls->fl & LS_R)
	{
		ls->sort_files = ft_sort_files_r;
//		ls->sort_dirs = ft_sort_dirs_r;
	}
	else
	{
		ls->sort_files = ft_sort_files;
//		ls->sort_dirs = ft_sort_dirs;
	}
}

void			ft_read_func(t_ls *ls)
{
	if (ls->fl & LS_L)
			ls->ls_func = ft_read_dir_l;
	else
		ls->ls_func = ft_read_dir;
	if (ls->fl & LS_UU)
	{
		ls->sort_files = ft_void_func;
		ls->sort_dirs = ft_void_func_dir;
	}
	ft_read_func_sort(ls);
	if (ls->fl & LS_RR)
		ft_ls_rec(ls);
	else
		ft_ls_l(ls);
}

void			ft_ls(char *fname, char d, t_ls *ls)
{
	if (d && fname && *fname)
	{
		if (!(ls->bufdir))
			ft_ls_init(ls, fname);
		ft_read_func(ls);
		//ft_del_filelist(&(ls->filelist));
//		ls->dirlist = ft_dirlist_init(ls, ft_strlen(fname), fname);
	}
}
