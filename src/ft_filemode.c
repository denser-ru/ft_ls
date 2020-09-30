/*
 * ft_filemode.c by cayako
 */

#include "ft_ls.h"

static void		ft_get_umode(t_ls *ls, t_stat *stat)
{
	if (stat->st_mode & S_IRUSR)
		ft_memset(ls->i + 1, 'r', 1);
	if (stat->st_mode & S_IWUSR)
		ft_memset(ls->i + 2, 'w', 1);
	if (stat->st_mode & S_ISUID)
		ft_memset(ls->i + 3, 'S', 1);
	if (stat->st_mode & S_IXUSR)
	{
		if(stat->st_mode & S_ISUID)
			ft_memset(ls->i + 3, 's', 1);
		else
		ft_memset(ls->i + 3, 'x', 1);
	}
}

static void		ft_get_gmode(t_ls *ls, t_stat *stat)
{
	if (stat->st_mode & S_IRGRP)
		ft_memset(ls->i + 4, 'r', 1);
	if (stat->st_mode & S_IWGRP)
		ft_memset(ls->i + 5, 'w', 1);
	if (stat->st_mode & S_ISGID)
		ft_memset(ls->i + 6, 'S', 1);
	if (stat->st_mode & S_IXGRP)
	{
		if(stat->st_mode & S_ISGID)
			ft_memset(ls->i + 6, 's', 1);
		else
		ft_memset(ls->i + 6, 'x', 1);
	}
}

void		ft_get_mode(t_ls *ls, t_stat *stat)
{
	ft_memset(ls->i, '-', 10);
	ft_memset(ls->i + 10, ' ', 1);
	if (stat->st_mode & S_IFDIR)
		ft_memset(ls->i, 'd', 1);
	if (stat->st_mode & S_IFCHR)
		ft_memset(ls->i, 'l', 1);
	ft_get_umode(ls, stat);
	ft_get_gmode(ls, stat);
	if (stat->st_mode & S_IROTH)
		ft_memset(ls->i + 7, 'r', 1);
	if (stat->st_mode & S_IWOTH)
		ft_memset(ls->i + 8, 'w', 1);
	if (stat->st_mode & S_IXOTH)
		ft_memset(ls->i + 9, 'x', 1);
	if (stat->st_mode & S_ISVTX)
		ft_memset(ls->i + 9, 't', 1);
	ls->i += 11;
	ls->curfile->mode = stat->st_mode;
}

int		ft_print_mod(void **in, void **out)
{
	ft_memcpy(*in, *out, 11);
	*in += 11;
	*out += 11;
	return (11);
}