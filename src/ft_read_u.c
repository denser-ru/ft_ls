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

void		ft_get_fname(t_ls *ls, t_dirent *dirp, char *fname)
{
	size_t	size;

	size = ls->curdir->content_size;
	ft_memcpy(fname, ls->curdir->content, size);
	fname += size;
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

t_dirent		*ft_get_dirp(t_dirent *dirp, DIR *dir, unsigned long long fl)
{
	while ((dirp = readdir(dir)) != NULL)
	{
		if ((dirp->d_name)[0] != '.' || (fl & LS_A))
			return (dirp);
	}
	return (NULL);
}

void			ft_void_func(void)
{
	return ;
}
