/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:01:47 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 21:01:49 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_gsinged.h"

int		ft_arg_sort_lexicographical_r_b(t_file *f)
{
	int		n;

	n = 0;
	while (f->next->next)
	{
		if ((ft_strcmp(f->next->adr, f->next->next->adr)) < 0)
			ft_change(f);
		f = f->next;
		n++;
	}
	return (n);
}

int		ft_arg_sort_lexicographical_r(t_file *f0)
{
	int		i;
	t_file	*f;
	int		n;

	if (!f0->next || !f0->next->next)
		return (0);
	f = f0;
	n = ft_arg_sort_lexicographical_r_b(f0) - 1;
	while (n > 0)
	{
		i = 0;
		f = f0;
		while (i++ < n)
		{
			if ((ft_strcmp(f->next->adr, f->next->next->adr)) < 0)
				ft_change(f);
			f = f->next;
		}
		n--;
	}
	return (0);
}

int		ft_arg_sort_lexicographical_b(t_file *f)
{
	int		n;

	n = 0;
	while (f->next->next)
	{
		if ((ft_strcmp(f->next->adr, f->next->next->adr)) > 0)
			ft_change(f);
		f = f->next;
		n++;
	}
	return (n);
}

int		ft_arg_sort_lexicographical(t_file *f0, unsigned long long r)
{
	int		i;
	t_file	*f;
	int		n;

	if (!f0->next || !f0->next->next)
		return (0);
	if ((r & LS_R))
		return (ft_arg_sort_lexicographical_r(f0));
	f = f0;
	n = ft_arg_sort_lexicographical_b(f0) - 1;
	while (n > 0)
	{
		i = 0;
		f = f0;
		while (i++ < n)
		{
			if ((ft_strcmp(f->next->adr, f->next->next->adr)) > 0)
				ft_change(f);
			f = f->next;
		}
		n--;
	}
	return (0);
}
