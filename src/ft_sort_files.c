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
/*
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
*/
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
			break ;
		else if (i == 0 && len < f->next->size[5])
			break ;
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

void	ft_sort_dirs_r(t_direct *d, t_direct *cur)
{
	t_direct	*c;

	while (d->next != NULL)
	{
		if ((ft_strcmp(cur->dname, d->next->dname)) > 0)
			break ;
		d = d->next;
	}
	if (d->next != NULL)
	{
		c = d->next;
		d->next = cur;
		cur->next = c;
	}
	else
		d->next = cur;
}

void	ft_sort_dirs(t_direct *d, t_direct *cur)
{
	t_direct	*c;

	while (d->next != NULL)
	{
		if ((ft_strcmp(cur->dname, d->next->dname)) < 0)
			break ;
		d = d->next;
	}
	if (d->next != NULL)
	{
		c = d->next;
		d->next = cur;
		cur->next = c;
	}
	else
		d->next = cur;
}
