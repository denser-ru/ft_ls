/*
 * main.c by cayako
 */

#include "ft_ls.h"

void			ft_ls_rec(t_ls *ls)
{
	DIR			*dir;
	t_dirent	*dirp;

	dirp = NULL;
	dir = opendir(*(ls->rootdir));
	ft_read_dir(ls, dirp, dir);
	closedir(dir);
}

static void		*ft_dirlist_init(t_ls *ls, int size)
{
	t_list	*dirlist;
	char	*rootdir_name;

	rootdir_name = *(ls->rootdir);
	if(rootdir_name[size - 1] == '/')
		--size;
	dirlist = ft_lstnew(rootdir_name, size);
	return (dirlist);
}

static void		ft_ls_init(t_ls *ls, char **argv)
{
	ls->rootdir = ++argv;
	ls->dirlist = ft_dirlist_init(ls, ft_strlen(*(ls->rootdir)));
	ls->bufdir = (void*)malloc(sizeof(void) * BUF);
	ls->buffile = (void*)malloc(sizeof(void) * BUF);
	ls->i = ls->buffile;
	ls->prevdir = NULL;
	ls->curdir = ls->dirlist;
	ls->nextdir = NULL;
	ls->curfile = NULL;
	ls->filelist = NULL;
}

void			ft_freemem(t_ls *ls, t_list **list)
{
	ft_lstdel(list, ft_lstdelcontent);
	free(ls->bufdir);
	free(ls->buffile);
	free(ls);
}

int				main(int argc, char **argv)
{
	t_ls	*ls;

	if (argc <2)
		return (0);
	ls = (t_ls*)malloc(sizeof(t_ls));
	ft_ls_init(ls, argv);
	ft_ls_rec(ls);
	ft_freemem(ls, &(ls->dirlist));
	return (0);
}