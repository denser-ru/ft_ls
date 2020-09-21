/*
 * main.c by cayako
 */

#include "ft_ls.h"

void	ft_ls_rec(t_ls *ls)
{
	DIR		*dir;
	t_dirent	*dirp;

	dirp = NULL;
	dir = opendir(ls->rootdir);
	ft_read_file(ls, dirp, dir);
	closedir(dir);
}

int		main(int argc, char **argv)
{
	t_ls	*ls;

	if (argc <2)
		return (0);
	ls = (t_ls*)malloc(sizeof(t_ls));
	ls->bufdir = (void*)malloc(sizeof(void) * BUF);
	ls->buffile = (void*)malloc(sizeof(void) * BUF);
	ls->i = (int*)malloc(sizeof(int) * (BUF / MAX_NAME));
	ls->rootdir = argv[1];
	ls->dirlist = ft_lstnew(ls->rootdir, ft_strlen(ls->rootdir));
	ft_ls_rec(ls);
	return (0);
}