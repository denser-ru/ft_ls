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
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ./ft_ls [-Ralrt1] [file ...]", 2);
	exit(1);
}

static void		print_err_ls(char *fname)
{
	ft_putstr_fd("ls: ", 2);
	if (fname)
	{
		ft_putstr_fd(fname, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}

void			print_error_dir(char *fname, char print_fname)
{
	char	*s;

	s = fname;
	while (*s)
	{
		if (*s == '/')
			fname = s + 1;
		s++;
	}
	if (print_fname)
	{
		ft_putstr_fd(fname, 2);
		ft_putendl_fd(":", 2);
	}
	print_err_ls(fname);
}

void			print_error(char *fname, char exit_err)
{
	if (errno != 0)
		print_err_ls(fname);
	if (exit_err)
		exit(1);
}
