/*
 * ft_read_dir.c by cayako
 */

#include "ft_ls.h"

static void		ft_get_fname(t_ls *ls, t_dirent *dirp, char *fname)
{
	size_t	size;

	size = ls->curdir->content_size;
	ft_memcpy(fname, ls->curdir->content, size);
	fname += size;
	ft_memcpy(fname++, "/", 1);
	size = ft_strlen(dirp->d_name);
	ft_memcpy(fname, dirp->d_name, size);
	ft_memcpy(ls->i, dirp->d_name, size);
	fname += size;
	ft_memcpy(fname, "\0", 1);
	ls->i += size;
	ls->curfile->size[5] = size;
}

static void			ft_init_max_size(t_ls *ls, int i)
{
	while (i < 6)
		ls->f_max_size[i++] = 0;
}

void			ft_read_dir(t_ls *ls, t_dirent	*dirp, DIR *dir)
{
	t_stat	stat;

	ls->i = ls->buffile;
	ft_init_max_size(ls, 0);
	ls->dirsize = 0;
	while ((dirp = readdir(dir)) != NULL)
	{
		ft_add_file(ls);
		ft_get_fname(ls, dirp, ls->fname);
		lstat(ls->fname, &stat);
		ft_get_mode(ls, &stat);
		ft_get_size(ls, &stat);
	}
	ft_print_dir(ls);
	ft_del_filelist(ls->filelist);
}