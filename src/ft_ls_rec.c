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

void			ft_tobuf(t_ls *ls, char *s, size_t size)
{
	ft_memcpy(ls->j, s, size);
	ls->j += size;
}

void	ft_nbrtobuf(t_ls *ls, int n)
{
	char	s[13];
	int		i;
	long	ln;

	if (n == 0)
	{
		ft_tobuf(ls, "0", 1);
		return ;
	}
	i = 11;
	s[12] = '\0';
	ln = n < 0 ? -(long)n : n;
	while (ln > 0)
	{
		s[i] = '0' + ln % 10;
		ln /= 10;
		--i;
	}
	if (n < 0)
		s[i--] = '-';
	ft_tobuf(ls, &s[i + 1], 11 - i);
}

void			ft_ls_rec(t_ls *ls, char *buf)
{
	DIR			*dir;
	t_dirent	*dirp;
	int			size;

	dirp = NULL;
	dir = opendir(ls->cur_dirname);
	ft_tobuf(ls, ls->cur_dirname, ft_strlen(ls->cur_dirname));
	ft_tobuf(ls, ":\n", 2);
	size = ft_read_dir(ls, dirp, dir, buf);
	closedir(dir);
	while (*(buf + 1))
	{
		ft_tobuf(ls, "\n", 1);
		buf += ft_strcpyn(ls->cur_dirname, buf) + 1;
		ft_ls_rec(ls, buf + size);
	}
}