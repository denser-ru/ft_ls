/*
 * ft_file_u.c by cayako
 */

#include "ft_ls.h"

static int		ft_get_size(t_ls *ls, t_stat *stat)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, stat->st_size);
	ft_memcpy(ls->i, ls->bufdir, size);
	ls->i += size;
	ls->curfile->size[4] = size;
	if (ls->f_max_size[4] < size)
		ls->f_max_size[4] = size;
	if (S_ISREG(stat->st_mode) || S_ISDIR(stat->st_mode))
		ls->curdir->content_size += stat->st_size / 1024;
	return (size);
}

static void		ft_get_fname(t_ls *ls, t_dirent *dirp,
								t_list *parentdir, char *fname)
{
	size_t	size;

	if (parentdir)
	{
		size = parentdir->content_size;
		ft_memcpy(fname, parentdir->content, size);
		fname += size;
		ft_memcpy(fname++, "/", 1);
	}
	size = ft_strlen(dirp->d_name);
	ft_memcpy(fname, dirp->d_name, size);
	ft_memcpy(ls->i, dirp->d_name, size);
	fname += size;
	ft_memcpy(fname, "\0", 1);
	ls->i += size;
	ls->curfile->size[5] = size;
}

void			ft_init_max_size(t_ls *ls, int i)
{
	while (i < 6)
		ls->f_max_size[i++] = 0;
}

void			ft_read_dir(t_ls *ls, t_dirent	*dirp, DIR *dir)
{
	t_stat	stat;

	ls->i = ls->buffile;
	ft_init_max_size(ls, 0);
	while ((dirp = readdir(dir)) != NULL)
	{
		ft_add_file(ls);
		ft_get_fname(ls, dirp, ls->prevdir, ls->fname);
		lstat(ls->fname, &stat);
		ft_get_size(ls, &stat);
	}
	ft_print_dir(ls);
}
