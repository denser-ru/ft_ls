/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:52:34 by cayako            #+#    #+#             */
/*   Updated: 2020/10/25 19:52:38 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_print_time(void **in, void **out, t_file *file)
{
	ft_memcpy(*in, *out, file->size[4]);
	*in += file->size[4];
	*out += file->size[4];
	ft_memset((*in)++, ' ', 1);
	return (file->size[4] + 1);
}

void		ft_get_fname(t_ls *ls, t_dirent *dirp, char *fname)
{
	size_t	size;

	ft_strcpy(fname, ls->curdir->dname);
	fname += ft_strlen(ls->curdir->dname);
	if (*(fname - 1) != '/')
		ft_memcpy(fname++, "/", 1);
	size = ft_strlen(dirp->d_name);
	ft_memcpy(fname, dirp->d_name, size);
	ft_memcpy(ls->i, dirp->d_name, size);
	fname += size;
	ft_memcpy(fname, "\0", 1);
	ls->i += size;
	ls->curfile->size[5] = size;
}

void		ft_init_max_size(t_ls *ls, int i)
{
	while (i < 6)
		ls->f_max_size[i++] = 0;
}

t_dirent	*ft_get_dirp(t_dirent *dirp, DIR *dir, unsigned long long fl)
{
	while ((dirp = readdir(dir)) != NULL)
	{
		if ((dirp->d_name)[0] != '.' || (fl & LS_A))
			return (dirp);
	}
	return (NULL);
}

void		ft_print_dir(t_ls *ls, t_file *file, int i)
{
	void	*in;
	int		one;

	one = ls->fl & LS_ONE ? 1 : 0;
	in = ls->bufdir;
	file = file->next;
	while (file && file != ls->curfile)
	{
		ft_memcpy(in, file->adr, file->size[5]);
		in += file->size[5];
		ft_memcpy(in++, one ? "\n" : "\t", 1);
		i += file->size[5] + 1;
		file = file->next;
	}
	ft_putnstr(ls->bufdir, i);
	if (!one)
		ft_putchar('\n');
}
