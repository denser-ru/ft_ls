/*
 * ft_file_u.c by cayako
 */

#include "ft_ls.h"

static int		ft_get_size(t_ls *ls, t_stat *stat, char **start)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, stat->st_size);
	ft_memcpy(*start, ls->bufdir, size);
	*start += size;
	return (size);
}

static int		ft_get_fullname(t_dirent *dirp, char *fname)
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
void			ft_read_file(t_ls *ls, t_dirent	*dirp, DIR *dir)
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
