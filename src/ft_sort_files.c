/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:12:36 by cayako            #+#    #+#             */
/*   Updated: 2020/10/23 16:13:13 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_files(t_ls *ls, t_file **curfile)
{
	t_file	*file;

	file = (*curfile)->next;
	if (!((*curfile)->prev))
	{
		ls->filelist = file;
		(*curfile)->next = file->next;
		(*curfile)->next->prev = *curfile;
		(*curfile)->prev = file;
		file->prev = NULL;
		file->next = *curfile;
	}
	else
	{
		file->prev = (*curfile)->prev;
		(*curfile)->next = file->next;
		(*curfile)->next->prev = *curfile;
		(*curfile)->prev->next = file;
		(*curfile)->prev = file;
		file->next = *curfile;
	}
	*curfile = ls->filelist;
}

//void	ft_sort_files(t_ls *ls)
//{
//	int		i;
//	t_file	*file;
//
//	i = 0;
//	file = ls->filelist;
//	while (file && file->adr && file->next->adr)
//	{
//		i = ft_strncmp(file->adr, file->next->adr, file->size[5] >
//			file->next->size[5] ? file->next->size[5] : file->size[5]);
//		if (i > 0 || (!i && file->size[5] > file->next->size[5]))
//		ft_swap_files(ls, &file);
//		else
//			file = file->next;
//	}
//}

void	ft_sort_files_r(t_ls *ls, char *name)
{
	t_file		*f;
	t_file		*c;
	int			i;
	int			len;

	f = ls->filelist;
	len = ft_strlen(name);
	while (f->next != ls->curfile)
	{
		i = ft_strncmp(name, f->next->adr, len <= f->next->size[5] ? len : f->next->size[5]);
		if (i > 0)
			break;
		else if (i == 0 && len > f->next->size[5])
			break;
		f = f->next;
	}
	if (f->next != ls->curfile)
	{
		ls->curfile->prev->next = ls->curfile->next;
		ls->endfile->prev = ls->curfile->prev;
		ls->curfile->prev = NULL;
		c = f->next;
		f->next = ls->curfile;
		ls->curfile->next = c;
	}
}

void	ft_sort_files(t_ls *ls, char *name)
{
	t_file		*f;
	t_file		*c;
	int			i;
	int			len;

	f = ls->filelist;
	len = ft_strlen(name);
	while (f->next != ls->curfile)
	{
		i = ft_strncmp(name, f->next->adr, len <= f->next->size[5] ? len : f->next->size[5]);
		if (i < 0)
			break;
		else if (i == 0 && len < f->next->size[5])
			break;
		f = f->next;
	}
	if (f->next != ls->curfile)
	{
		ls->curfile->prev->next = ls->curfile->next;
		ls->endfile->prev = ls->curfile->prev;
		ls->curfile->prev = NULL;
		c = f->next;
		f->next = ls->curfile;
		ls->curfile->next = c;
	}
}

/*
void	ft_swap_dirs(t_ls *ls, t_list **curdir)
{
	t_list	*next;
	t_list	*prev;

	next = (*curdir)->next;
	prev = ls->curdir;
	while (prev->next && prev != *curdir && prev->next != *curdir)
		prev = prev->next;
	if (prev != *curdir)
		prev->next = next;
	(*curdir)->next = next->next;
	next->next = *curdir;
	*curdir = ls->curdir;
}

int 	ft_sort_dirs_r(t_ls *ls)
{
	int		i;
	t_list	*dir;

	i = 0;
	dir = ls->curdir;

	while (dir && dir->next)
	{
		i = ft_strncmp(dir->content, dir->next->content, dir->content_size >
		dir->next->content_size ? dir->next->content_size :
		dir->content_size);
		if (i < 0 || (!i && dir->content_size < dir->next->content_size))
			ft_swap_dirs(ls, &dir);
		else
			dir = dir->next;
	}
	return (0);
}

int 	ft_sort_dirs(t_ls *ls)
{
	int		i;
	t_list	*dir;

	i = 0;
	dir = ls->curdir;

	while (dir && dir->next)
	{
		i = ft_strncmp(dir->content, dir->next->content, dir->content_size >
			dir->next->content_size ? dir->next->content_size :
			dir->content_size);
		if (i > 0 || (!i && dir->content_size > dir->next->content_size))
			ft_swap_dirs(ls, &dir);
		else
			dir = dir->next;
	}
	return (0);
}
 */
