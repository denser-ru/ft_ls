/*
 * main.c by cayako
 */

#include "ft_ls.h"

void		ft_ls_rec(t_ls *ls)
{
	DIR			*dir;
	t_dirent	*dirp;

	dirp = NULL;
	dir = opendir(ls->rootdir);
	ft_read_dir(ls, dirp, dir);
	closedir(dir);
}

static void		ft_ls_init(t_ls *ls, char **argv)
{
	ls->rootdir = argv[1];
	ls->dirlist = ft_lstnew(ls->rootdir, ft_strlen(ls->rootdir));
	ls->bufdir = (void*)malloc(sizeof(void) * BUF);
	ls->buffile = (void*)malloc(sizeof(void) * BUF);
	ls->i = ls->buffile;
	ls->prevdir = NULL;
	ls->curdir = ls->dirlist;
	ls->nextdir = NULL;
	ls->curfile = NULL;
	ls->filelist = NULL;
}

int			main(int argc, char **argv)
{
	t_ls	*ls;

	if (argc <2)
		return (0);
	ls = (t_ls*)malloc(sizeof(t_ls));
	ft_ls_init(ls, argv);
	ft_ls_rec(ls);
	return (0);
}