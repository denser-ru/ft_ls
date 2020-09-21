/*
 * main.c by cayako
 */

#include "ft_ls.h"

int		ft_get_size(t_ls *ls, t_stat *stat, char **start)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, stat->st_size);
	ft_memcpy(*start, ls->bufdir, size);
	*start += size;
	return (size);
}

int		ft_get_fullname(t_dirent *dirp, char *fname)
{
	size_t	size;

	size = ft_strlen(dirp->d_name);
	ft_memcpy(fname, dirp->d_name, size);
	ft_memcpy(fname + size, "\0", 1);
	return (size);
}

/*void	ft_print_dir(t_ls *ls, 
	ft_putnstr(ls->buffile, buf_i - (char*)ls->buffile);
	ft_putchar('\n');
*/
void	ft_read_file(t_ls *ls, t_dirent	*dirp, DIR *dir)
{
	t_stat	stat;
	char	fname[MAX_NAME];
	int		*i;
	char	*buf_i;

	i = ls->i;
	buf_i = ls->buffile;
	while ((dirp = readdir(dir)) != NULL)
	{
		*(i + 1) = ft_get_fullname(dirp, fname);
		lstat(fname, &stat);
		*i = ft_get_size(ls, &stat, &buf_i);
		ft_memcpy(buf_i, fname, *(++i));
		buf_i += *(i);
		++i;
	}
//	ft_print_dir(ls, buf_i - (char*)ls->buffile, i - ls->i);
	ft_putnstr(ls->buffile, buf_i - (char*)ls->buffile);
	ft_putchar('\n');
}

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