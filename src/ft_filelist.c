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

void			ft_get_spot(t_ls *ls, char *name)
{
	ls->sort_files(ls, name);
	ft_next_curfile(ls);
}

void			ft_next_curfile(t_ls *ls)
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

void			ft_del_filelist(t_file **file)
{
	if ((*file)->next)
		ft_del_filelist(&((*file)->next));
	if (*file)
		free(*file);
	*file = NULL;
}
