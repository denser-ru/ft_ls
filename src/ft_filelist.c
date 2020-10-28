/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:50:30 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:50:37 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_get_spot(t_ls *ls, char *name)
{
//	t_file	*spot;
//	int		len;

	ls->sort_files(ls, name);
	ft_next_curfile(ls);
	/*
	len = ft_strlen(name);
	spot = ls->filelist;
	while (spot && spot->next && spot != ls->curfile && spot->next->adr)
	{
//		if (0 < ft_strncmp(name, spot->next->adr, len))
		if (ls->sort_files(ls))
			break ;
		spot = spot->next;
	}
	if (spot->next == ls->endfile)
		ft_add_file(ls);
	else
	{
		if (spot->next)
			ls->curfile->next = spot->next->next;
		spot->next = ls->curfile;
		//ls->curfile = ls->endfile;
		ft_add_file(ls);
	}
	 */
}


static void	ft_arg_print_test(t_file *f)
{


	while (f)
	{

		ft_putnbr(f->size[5]);

		ft_putstr(f->adr);

//		write(1, f->adr, f->size[5]);
		ft_putendl("!");

		f = f->next;
	}
}

void			ft_add_file(t_ls *ls)
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	ft_bzero(file, sizeof(t_file));
	if (ls->curfile)
	{
		ls->curfile->next = file;
		ls->endfile->adr = ls->curfile->adr;
		ls->endfile->size[5] = ls->curfile->size[5];
		ls->curfile = ls->endfile;
		ls->endfile = file;
	}
	else
	{
		file->adr = ls->i;
		ls->curfile = file;
		ls->endfile = (t_file*)malloc(sizeof(t_file));
		ft_bzero(ls->endfile, sizeof(t_file));
		ls->curfile->next = ls->endfile;
		ls->endfile->adr = ls->i;
		ls->filelist = file;
	}

	ft_putendl("\n-----add_file----");


//	ft_putstr(file->adr);
	ft_arg_print_test(ls->filelist);

	ft_putendl("/end");

}

void			ft_next_curfile(t_ls *ls)
{
	t_file		*file;

	if (ls->endfile->next)
	{
		file = ls->endfile->next;
		ls->endfile->next = file->next;
		ft_bzero(file, sizeof(t_file));
	}
	else
		file = ft_file_new();
	file->prev = ls->endfile->prev;
	file->next = ls->endfile;
	ls->endfile->prev->next = file;
	ls->endfile->prev = file;
	ls->curfile = file;
}

void			ft_del_filelist(t_file **file)
{
	if ((*file)->next)
		ft_del_filelist(&((*file)->next));
	free(*file);
	*file = NULL;
}
