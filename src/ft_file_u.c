/*
 * ft_file_u.c by cayako
 */

#include "ft_ls.h"

static int		ft_get_size(t_ls *ls, t_stat *stat)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, stat->st_size);
	if (!size)
		ft_memset(ls->i, '0', ++size);
	else
		ft_memcpy(ls->i, ls->bufdir, size);
	ls->i += size;
	ls->curfile->size[4] = size;
	if (ls->f_max_size[4] < size)
		ls->f_max_size[4] = size;
//	if (S_ISREG(stat->st_mode) || S_ISDIR(stat->st_mode))
		ls->dirsize += stat->st_blocks << 9;
	return (size);
}

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
	ls->dirsize = 0;
	while ((dirp = readdir(dir)) != NULL)
	{
		ft_add_file(ls);
		ft_get_fname(ls, dirp, ls->fname);
		lstat(ls->fname, &stat);
		ft_get_size(ls, &stat);
	}
	ft_print_dir(ls);
	ft_del_filelist(ls->filelist);
}
