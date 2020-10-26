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
	t_file	*spot;
	int		len;

	len = ft_strlen(name);
	spot = ls->filelist;
	len = len < spot->size[5] ? spot->size[5] : len;
	while (spot != ls->curfile)
	{
		if (0 > ft_strncmp(name, spot->next->adr, len))
			break ;
		spot = spot->next;
	}
	if (spot == ls->curfile)
		ft_add_file(ls);
	else
	{
		ls->curfile->next = spot->next;
		spot->next = ls->curfile;
		ls->curfile = ls->endfile;
		ft_add_file(ls);
	}
}

void			ft_add_file(t_ls *ls)
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	if (ls->curfile)
	{
		ls->curfile->next = file;
		file->adr = ls->curfile->adr;
		file->next = NULL;
		ls->endfile = ls->curfile;
		ls->curfile = file;
	}
	else
	{
		file->adr = ls->i;
		ls->curfile = (t_file*)malloc(sizeof(t_file));
		ls->curfile->next = NULL;
		ls->curfile->adr = ls->i;
		file->next = ls->curfile;
		ls->endfile = file;
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
