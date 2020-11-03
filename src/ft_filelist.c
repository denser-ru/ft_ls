/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:50:30 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:50:37 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_get_spot(t_ls *ls, char *name)
{
	ls->sort_files(ls, name);
	ft_next_curfile(ls);
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

t_file		*ft_file_new(void)
{
	t_file		*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		print_error(NULL, 1);
	ft_bzero(file, sizeof(t_file));
	return (file);
}

void		ft_next_curfile(t_ls *ls)
{
	t_file		*file;

	if (ls->endfile->next)
	{
		file = ls->endfile->next;
		ls->endfile->next = file->next;
		ft_bzero(file, sizeof(t_file));
	}
	else
		file = ft_file_new();
	file->prev = ls->endfile->prev;
	file->next = ls->endfile;
	ls->endfile->prev->next = file;
	ls->endfile->prev = file;
	ls->curfile = file;
}

void		ft_del_filelist(t_file **file)
{
	if (*file)
	{
		if ((*file)->next)
			ft_del_filelist(&((*file)->next));
		free(*file);
	}
	*file = NULL;
}
