/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:50:10 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:50:13 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_get_nlink(t_ls *ls, t_stat *stat)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, stat->st_nlink);
	ft_memcpy(ls->i, ls->bufdir, size);
	ls->i += size;
	ls->curfile->size[0] = size;
	if (ls->f_max_size[0] < size)
		ls->f_max_size[0] = size;
}

void		ft_get_pwd(t_ls *ls, t_stat *stat)
{
	int		size;
	char	*name;

	name = getpwuid(stat->st_uid)->pw_name;
	size = ft_strlen(name);
	ft_memcpy(ls->i, name, size);
	ls->i += size;
	ls->curfile->size[1] = size;
	if (ls->f_max_size[1] < size)
		ls->f_max_size[1] = size;
	name = getgrgid(stat->st_gid)->gr_name;
	size = ft_strlen(name);
	ft_memcpy(ls->i, name, size);
	ls->i += size;
	ls->curfile->size[2] = size;
	if (ls->f_max_size[2] < size)
		ls->f_max_size[2] = size;
}

void		ft_get_size(t_ls *ls, t_stat *stat)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, stat->st_size);
	if (!size)
		ft_memset(ls->i, '0', ++size);
	else
		ft_memcpy(ls->i, ls->bufdir, size);
	ls->i += size;
	ls->curfile->size[3] = size;
	if (ls->f_max_size[3] < size)
		ls->f_max_size[3] = size;
	ls->dirsize += stat->st_blocks << 10;
}

void		ft_get_ctime(t_ls *ls, t_stat *stat)
{
	int		size;
	char	*time;

	time = ctime(&(stat->st_mtime));
	ls->curfile->ctime = stat->st_mtime;
	size = ft_strlen(time);
	ft_memcpy(ls->i, time, size);
	ls->i += ++size;
	ls->curfile->size[4] = size;
}
