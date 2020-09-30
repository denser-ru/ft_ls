/*
 * ft_ls_rec.c by cayako
 */

#include "ft_ls.h"

void			ft_ls_rec(t_ls *ls)
{
	DIR			*dir;
	t_dirent	*dirp;

	dirp = NULL;
	while (ls->curdir)
	{
		ft_memcpy(ls->fname, ls->curdir->content, ls->curdir->content_size);
		ft_memset(ls->fname + ls->curdir->content_size, '\0', 1);
		dir = opendir(ls->fname);
		ft_putstr(ls->fname);
		ft_putstr(":\n");
		ft_read_dir(ls, dirp, dir);
		closedir(dir);
		ls->curdir = ls->curdir->next;
	}
}