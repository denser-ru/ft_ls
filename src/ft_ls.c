/*
 * main.c by cayako
 */

#include "ft_ls.h"
#include <stdio.h>

/*int		ft_get_atr(t_ls *ls, t_dirent *dirp, size_t start)
{
	int		i;
	t_stat	*stat;
	//dirp->d_reclen, ft_strlen(dirp->d_name), dirp->d_name

	i = 0;
	return(i);
}*/

void	ft_ls_rec(t_ls *ls, t_list *dirlist)
{
//	DIR		*dir;
//	t_dirent	*dirp;
	size_t		i;

	i = dirlist->content_size;
	ft_memcpy(ls->buf, dirlist->content, i);
	ft_memcpy(ls->buf + i, ":\0", 2);
//	dir = opendir(ls->rootdir);
/*	while ((dirp = readdir(dir)) != NULL)
	{
		i += ft_get_atr(ls, dirp, i);
	}*/
	ft_putnstr(ls->buf, i);
	ft_putchar('\n');
/*	printf("%d\t%ld\t%s\n", (char*)ls->buf);*/
}

int		main(int argc, char **argv)
{
	t_ls	*ls;

	if (argc <2)
		return (0);
	ls = (t_ls*)malloc(sizeof(t_ls));
	ls->buf = (void*)malloc(sizeof(void) * BUF);
	ls->rootdir = argv[1];
	ls->dirlist = ft_lstnew(ls->rootdir, ft_strlen(ls->rootdir));
	printf("List %s dir:\n", ls->rootdir);
	ft_ls_rec(ls, ls->dirlist);
	return (0);
}