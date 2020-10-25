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
	t_list	*dirlist;
	char	*rootdir_name;

	rootdir_name = fname;
	if (rootdir_name[size - 1] == '/' && size > 1 && rootdir_name[size] != '\0')
		--size;
	dirlist = ft_lstnew(rootdir_name, size);
	ls->curdir = dirlist;
	return (dirlist);
}

static void		ft_ls_init(t_ls *ls, char *fname)
{
	ls->dirlist = ft_dirlist_init(ls, ft_strlen(fname), fname);
	ls->bufdir = (void*)malloc(sizeof(void) * BUF);
	ls->buffile = (void*)malloc(sizeof(void) * BUF);
	ls->i = ls->buffile;
	ls->filelist = NULL;
	ft_add_file(ls);
}

void			ft_freemem(t_ls *ls, t_list **list)
{
	ft_del_filelist(&(ls->filelist));
	ft_lstdel(list, ft_lstdelcontent);
	free(ls->bufdir);
	free(ls->buffile);
	free(ls);
}

void			ft_read_func(t_ls *ls)
{
	if (ls->fl & LS_UU)
		ls->ft_ls_func = ft_read_dir_lru;
	else
		ls->ft_ls_func = ft_read_dir;
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
		ft_del_filelist(&(ls->filelist));
		ls->dirlist = ft_dirlist_init(ls, ft_strlen(fname), fname);
	}
}
