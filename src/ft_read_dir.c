/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:52:29 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:52:31 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_stat(t_ls *ls, t_stat *stat)
{
	ft_get_mode(ls, stat);
	ft_get_nlink(ls, stat);
	ft_get_pwd(ls, stat);
	ft_get_size(ls, stat);
	ft_get_ctime(ls, stat);
}

/*
#include <stdio.h>
static void	ft_arg_print_test(t_file *f)
{


	while (f)
	{
		if (!f->next)
			ft_putendl("//");
		ft_putnbr(f->size[5]);

		if (f->adr)
			ft_putstr(f->adr);


		printf("|%p!!\n", f);
//		write(1, f->adr, f->size[5]);
//		ft_putendl("!");

		if (!f->next)
			ft_putendl("//");

		f = f->next;
	}


//	ft_putchar(' ');
//	ft_putstr(ctime(&f->ctime));
}
*/

void			ft_read_dir_l(t_ls *ls, t_dirent *dirp, DIR *dir,
					t_list **dirlist)
{
	t_stat	stat;

	ft_filelist_init(ls);
	ls->i = ls->buffile;
	ft_init_max_size(ls, 0);
	ls->dirsize = 0;

/*
	ft_putendl("\n-----Before_print----");


//	ft_putstr(file->adr);
	ft_arg_print_test(ls->filelist);

//	ft_putnbr(ls->curfile->size[5]);

//	ft_putstr(ls->curfile->adr);
//	ft_putendl("!");
	printf("%p\n%p\n", ls->curfile, ls->endfile);
	ft_putendl("/end");
*/

	while ((dirp = ft_get_dirp(dirp, dir , ls->fl)))
	{
		ls->curfile->adr = ls->i;
		ft_get_fname(ls, dirp, ls->fname);
		lstat(ls->fname, &stat);
		if (dirlist && (stat.st_mode & S_IFDIR) &&
				ft_strcmp(dirp->d_name, ".") && ft_strcmp(dirp->d_name, ".."))
			ft_direct_pushb(dirlist, ls->fname, NULL);
//			ft_lstpushb(dirlist, ls->fname, ft_strlen(ls->fname));
		ft_get_stat(ls, &stat);
		ft_get_spot(ls, dirp->d_name);
	}
	ft_print_dir_l(ls, ls->filelist, 0);
}

void			ft_read_dir(t_ls *ls, t_dirent *dirp, DIR *dir,
					t_list **dirlist)
{
	t_stat	stat;

	ft_filelist_init(ls);
	ls->i = ls->buffile;
	ft_init_max_size(ls, 0);
	ls->dirsize = 0;
	while ((dirp = ft_get_dirp(dirp, dir , ls->fl)))
	{
		ls->curfile->adr = ls->i;
		ft_get_fname(ls, dirp, ls->fname);
		lstat(ls->fname, &stat);
		if (dirlist && (stat.st_mode & S_IFDIR) && ft_strcmp(dirp->d_name, ".") && ft_strcmp(dirp->d_name, ".."))
			ft_direct_pushb(dirlist, ls->fname, NULL);
//			ft_lstpushb(dirlist, ls->fname, ft_strlen(ls->fname));
		ft_get_stat(ls, &stat);
		ft_get_spot(ls, dirp->d_name);
	}
	ft_print_dir(ls, ls->filelist, 0);
}