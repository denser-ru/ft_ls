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

	file = (*curfile);
	if (!(file->prev))
	{
		ls->filelist = file->next;
		file->next = file;

	}
	else
	{
		file->prev->next = file->next;
		file->next = file->next->next;
		file->prev->next = file;
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
		while(file && file->adr && file->next && file->next->adr)
		{
			i = ft_strncmp(file->adr, file->next->adr, file->size[5] >
				file->next->size[5] ? file->next->size[5] : file->size[5]);
			if (!i && file->size[5] != file->next->size[5])
				ft_swap_files(ls, &file);
			file = file->next;
		}
}