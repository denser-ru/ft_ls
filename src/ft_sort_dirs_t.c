/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dirs_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:16:33 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/31 18:16:35 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_sort_dirs_t_r_name(t_direct *d, t_direct *cur)
{
	t_direct	*c;

	while (d->next != NULL && cur->file->ctime == d->next->file->ctime)
	{
		if ((ft_strcmp(cur->dname, d->next->dname)) > 0)
			break ;
		d = d->next;
	}
	if (d->next != NULL)
	{
		c = d->next;
		d->next = cur;
		cur->next = c;
	}
	else
		d->next = cur;
}

void		ft_sort_dirs_t_r(t_direct *d, t_direct *cur)
{
	t_direct	*c;

	while (d->next != NULL)
	{
		if (cur->file->ctime <= d->next->file->ctime)
			break ;
		d = d->next;
	}
	if (d->next == NULL)
		d->next = cur;
	else if (cur->file->ctime < d->next->file->ctime)
	{
		c = d->next;
		d->next = cur;
		cur->next = c;
	}
	else if (cur->file->ctime == d->next->file->ctime)
		ft_sort_dirs_t_r_name(d, cur);
}

static void	ft_sort_dirs_t_name(t_direct *d, t_direct *cur)
{
	t_direct	*c;

	while (d->next != NULL && cur->file->ctime == d->next->file->ctime)
	{
		if ((ft_strcmp(cur->dname, d->next->dname)) < 0)
			break ;
		d = d->next;
	}
	if (d->next != NULL)
	{
		c = d->next;
		d->next = cur;
		cur->next = c;
	}
	else
		d->next = cur;
}

void		ft_sort_dirs_t(t_direct *d, t_direct *cur)
{
	t_direct	*c;

	while (d->next != NULL)
	{
		if (cur->file->ctime >= d->next->file->ctime)
			break ;
		d = d->next;
	}
	if (d->next == NULL)
		d->next = cur;
	else if (cur->file->ctime > d->next->file->ctime)
	{
		c = d->next;
		d->next = cur;
		cur->next = c;
	}
	else if (cur->file->ctime == d->next->file->ctime)
		ft_sort_dirs_t_name(d, cur);
}
