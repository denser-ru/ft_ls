/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_add_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:01:32 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 21:01:35 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_gsinged.h"

void	ft_change(t_file *f)
{
	t_file		*c;

	c = f->next;
	f->next = f->next->next;
	c->next = f->next->next;
	f->next->next = c;
}

void	ft_arg_add_file(t_file *f, int i, t_stat *stat, char **argv)
{
	t_file		*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		print_error(NULL, 1);
	ft_bzero(file, sizeof(t_file));
	file->size[0] = i;
	if (stat)
		file->ctime = stat->st_mtime;
	file->adr = argv[i];
	if (!f[0].next)
	{
		f[0].next = file;
		f[0 + 3].next = file;
		f[0].size[0] = 1;
	}
	else
	{
		(f[0 + 3].next)->next = file;
		f[0 + 3].next = file;
		f[0].size[0]++;
	}
}
