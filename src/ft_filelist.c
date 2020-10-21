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

void			ft_add_file(t_ls *ls)
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	if (ls->curfile)
	{
		ls->curfile->next = file;
		file->adr = ls->i;
		file->next = NULL;
		ls->curfile = file;
	}
	else
	{
		file->adr = ls->i;
		file->next = NULL;
		ls->curfile = file;
		ls->filelist = file;
	}
}

void			ft_del_filelist(t_file **file)
{
	if ((*file)->next)
		ft_del_filelist(&((*file)->next));
	free(*file);
	*file = NULL;
}
