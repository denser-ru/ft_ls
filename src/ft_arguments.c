/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:02:24 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 21:02:26 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_gsinged.h"

static void		ft_get_stat_gs(char **argv, int i, t_file *f)
{
	t_stat	stat;

	errno = 0;
	if ((lstat(argv[i], &stat)) == -1)
	{
		ft_arg_add_file(&(f[0]), i, &stat, argv);
		(f[3].next)->size[1] = errno;
	}
	else if (S_ISDIR(stat.st_mode))
		ft_arg_add_file(&(f[2]), i, &stat, argv);
	else
		ft_arg_add_file(&(f[1]), i, &stat, argv);
}

static void		ft_arg_gl_sort(t_file *f, unsigned long long fl)
{
	ft_arg_sort_lexicographical(&(f[0]), 0);
	ft_arg_sort_lexicographical(&(f[1]), fl);
	ft_arg_sort_lexicographical(&(f[2]), fl);
	if (fl & LS_T)
	{
		ft_arg_sort_modified(&(f[1]));
		ft_arg_sort_modified(&(f[2]));
	}
}

static void		ft_arg_print_f1(t_file *f)
{
	while (f)
	{
		ft_putstr("ls: ");
		ft_putstr(f->adr);
		ft_putstr(": ");
		ft_putstr(strerror(f->size[1]));
		ft_putchar('\n');
		f = f->next;
	}
}

static void		ft_arg_put_b(t_file *fsix, t_ls *ls, int n, char d)
{
	t_file		*f;
	t_file		*c;

	ls->filelist = fsix[0].next;
	if ((f = fsix[n].next))
	{
		while (f->next)
		{
			ft_ls(f->adr, d, ls);
			c = f;
			f = f->next;
			c->next = ls->filelist;
			ls->filelist = c;
		}
		ft_ls(f->adr, d, ls);
		f->next = ls->filelist;
		ls->filelist = f;
	}
}

void			ft_arguments(int argc, char **argv, t_ls *ls)
{
	int		i;
	t_file	fsix[6];

	ft_bzero(fsix, sizeof(fsix));
	i = 0;
	while (i < argc)
	{
		ft_get_stat_gs(argv, i, fsix);
		i++;
	}
	ft_arg_gl_sort(fsix, ls->fl);
	ft_arg_print_f1(fsix[0].next);
	ft_arg_put_b(fsix, ls, 1, 0);
//	if (fsix[1].size[0] && fsix[2].size[0])
//		ft_putchar('\n');
	ft_arg_put_b(fsix, ls, 2, 2);
}
