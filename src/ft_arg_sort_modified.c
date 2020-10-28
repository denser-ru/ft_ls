/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_sort_modified.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:02:06 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 21:02:08 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_ls_gsinged.h"

int			ft_arg_sort_modified_b(t_file *f)
{
	int		n;

	n = 0;
	while (f->next->next)
	{
		if (f->next->ctime < f->next->next->ctime)
			ft_change(f);
		f = f->next;
		n++;
	}
	return (n);
}

int			ft_arg_sort_modified(t_file *f0)
{
	t_file		*f;
	int			n;
	int			i;

	if (!f0->next || !f0->next->next)
		return (0);
	n = ft_arg_sort_modified_b(f0) - 1;
	while (n > 0)
	{
		i = 0;
		f = f0;
		while (i++ < n)
		{
			if (f->next->ctime < f->next->next->ctime)
				ft_change(f);
			f = f->next;
		}
		n--;
	}
	return (0);
}
