/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:02:45 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 21:02:47 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_gsinged.h"

void			print_ls_error_ls(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ./ft_ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%%] [file ...]");
	exit(0);
}

static void		print_err_ls(char *fname)
{
	ft_putstr("ls: ");
	if (fname)
	{
		ft_putstr(fname);
		ft_putstr(": ");
	}
	ft_putstr(strerror(errno));
	ft_putchar('\n');
}

void			print_error_dir(char *fname, char print_fname)
{
	if (print_fname)
	{
		ft_putstr(fname);
		ft_putendl(":");
	}
	print_err_ls(fname);
}

void			print_error(char *fname, char exit_err)
{
	if (errno != 0)
		print_err_ls(fname);
	if (exit_err)
		exit(0);
}
