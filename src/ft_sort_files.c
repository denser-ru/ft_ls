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

void	ft_sort_files(t_ls *ls)
{
	int 	i;
	t_file	*file;

	i = 0;
	file = ls->filelist;
	if(!(ls->fl))
		while(file && file->adr && file->next->adr)
		{
			i = ft_strncmp(file->adr, file->next->adr, file->size[5] > 
				file->next->size[5] ? file->next->size[5] : file->size[5]);
			if (i > 0 || (!i && file->size[5] > file->next->size[5]))
				ft_swap_files(ls, &file);
			else
				file = file->next;
		}
}