/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:52:34 by cayako            #+#    #+#             */
/*   Updated: 2020/10/25 19:52:38 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_get_fname(t_ls *ls, t_dirent *dirp, char *fname)
{
	size_t	size;

	ft_strcpy(fname, ls->curdir->dname);
	fname += ft_strlen(ls->curdir->dname);
	if (*(fname - 1) != '/')
		ft_memcpy(fname++, "/", 1);
	size = ft_strlen(dirp->d_name);
	ft_memcpy(fname, dirp->d_name, size);
	ft_memcpy(ls->i, dirp->d_name, size);
	fname += size;
	ft_memcpy(fname, "\0", 1);
	ls->i += size;
	ls->curfile->size[5] = size;
}

void		ft_init_max_size(t_ls *ls, int i)
{
	while (i < 6)
		ls->f_max_size[i++] = 0;
}

t_dirent		*ft_get_dirp(t_dirent *dirp, DIR *dir, unsigned long long fl)
{
	while ((dirp = readdir(dir)) != NULL)
	{
		if ((dirp->d_name)[0] != '.' || (fl & LS_A))
			return (dirp);
	}
	return (NULL);
}

/*void	ft_print_dirlist(t_ls *ls, int one)
{
	t_list	*list;

	list = ls->curdir->next;
	while (list)
	{
		ft_putnstr(list->content, list->content_size);
		ft_putchar(one ? '\n' : '\t');
		list = list->next;
	}
	if (!one)
		ft_putchar('\n');
}*/

/*
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


//	ft_putchar(' ');
//	ft_putstr(ctime(&f->ctime));
}*/

void			ft_print_dir(t_ls *ls, t_file *file, int i)
{
	void	*in;
	int		one;

/*
	ft_putendl("\n-----Before_print----");


//	ft_putstr(file->adr);
	ft_arg_print_test(file);

	ft_putendl("/end");
 */

	one = ls->fl & LS_ONE ? 1 : 0;
	in = ls->bufdir;
	file = file->next;
	while (file && file != ls->curfile)
	{
		ft_memcpy(in, file->adr, file->size[5]);
		in += file->size[5];
		ft_memcpy(in++, one ? "\n" : "\t", 1);
		i += file->size[5] + 1;
		file = file->next;
	}
	ft_putnstr(ls->bufdir, i);
	if (!one)
		ft_putchar('\n');
}
