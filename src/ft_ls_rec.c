/*
 * ft_ls_rec.c by cayako
 */

#include "ft_ls.h"

int				ft_strcpyn(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (i);
}

void			ft_ls_rec(t_ls *ls, char *buf)
{
	DIR			*dir;
	t_dirent	*dirp;
	int			size;

	dirp = NULL;
	dir = opendir(ls->cur_dirname);
	ft_putstr(ls->cur_dirname);
	ft_putstr(":\n");
	size = ft_read_dir(ls, dirp, dir, buf);
	closedir(dir);
	while (*(buf + 1))
	{
		ft_putchar('\n');
		buf += ft_strcpyn(ls->cur_dirname, buf) + 1;
		ft_ls_rec(ls, buf + size);
	}
}