/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_file_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:31:43 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 21:31:45 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_sort_files_t_name(t_ls *ls, t_file *f)
{

}

void	ft_sort_files_t(t_ls *ls, char *name)
{
	time_t		curtime;
	t_file		*f;
	t_file		*c;

	curtime = ls->curfile->ctime;
	f = ls->filelist;
	while (f->next != ls->curfile)
	{
		if (ls->curfile->ctime >= f->next->ctime)
			break;
		f = f->next;
	}
	if (f->next != ls->curfile && ls->curfile->ctime > f->next->ctime)
	{
		ls->curfile->prev->next = ls->curfile->next;
		ls->endfile->prev = ls->curfile->prev;
		ls->curfile->prev = NULL;
		c = f->next;
		f->next = ls->curfile;
		ls->curfile->next = c;
	}
	else if (f->next != ls->curfile && ls->curfile->ctime == f->next->ctime)
		ft_sort_files_t_name(ls, f);
}
