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

	if(!(getpwuid(stat->st_uid)))
		name = ft_itoa(stat->st_uid);
	else
		name = getpwuid(stat->st_uid)->pw_name;
	size = ft_strlen(name);
	ft_memcpy(ls->i, name, size);
	ls->i += size;
	ls->curfile->size[1] = size;
	if (ls->f_max_size[1] < size)
		ls->f_max_size[1] = size;
	if(!(getgrgid(stat->st_gid)))
		name = ft_itoa(stat->st_gid);
	else
		name = getgrgid(stat->st_gid)->gr_name;
	size = ft_strlen(name);
	ft_memcpy(ls->i, name, size);
	ls->i += size;
	ls->curfile->size[2] = size;
	if (ls->f_max_size[2] < size)
		ls->f_max_size[2] = size;
}

size_t 		ft_itoa_mem_2d(t_ls *ls, t_stat *stat, int *size2)
{
	int 	size;

	size = ft_itoa_mem_d(ls->bufdir, major(stat->st_rdev));
	if (!size)
		ft_memset(ls->bufdir, '0', ++size);
	*size2 = ft_itoa_mem_d(ls->bufdir + size, minor(stat->st_rdev));
	if (!(*size2))
		ft_memset(ls->bufdir + size, '0', ++(*size2));
	ls->curfile->size[7] = *size2;
	if (ls->f_max_size[5] < *size2)
		ls->f_max_size[5] = *size2;
	return (size);
}

void		ft_get_size(t_ls *ls, t_stat *stat, int size, int size2)
{
	ls->curfile->mode = (S_ISCHR(stat->st_mode)
			|| S_ISBLK(stat->st_mode));
	if (ls->curfile->mode)
		size = ft_itoa_mem_2d(ls, stat, &size2);
	else
		size = ft_itoa_mem_d(ls->bufdir, stat->st_size);
	if (!size)
		ft_memset(ls->i, '0', ++size);
	else
		ft_memcpy(ls->i, ls->bufdir, size + size2);
	ls->i += size + size2;
	ls->curfile->size[3] = size;
	if (ls->f_max_size[3] < size)
		ls->f_max_size[3] = size;
	ls->dirsize += stat->st_blocks << 10;
}

static	char	*ft_time_b(char *str, int *size, t_ls *ls)
{
	int		i;

	i = 0;
	while (*str == ' ')
		str++;
	while (*str != '\n')
	{
		i++;
		str++;
	}
	str -= i;
	ft_memset(ls->i + 7, ' ', 1);
	ft_memcpy(ls->i + 8, str, i);
	*size = 8 + i;
	return (str);
}

void		ft_get_ctime(t_ls *ls, t_stat *stat)
{

	int		size;
	char	*time;

	time = ctime(&(stat->st_mtime));
	ls->curfile->ctime = stat->st_mtime;
	time += 4;
	size = ft_strlen(time);
	ft_memcpy(ls->i, time, 7);
	if ((ls->curfile->ctime < ls->ltime - 15724800) || (ls->curfile->ctime > ls->ltime + 15724800))
	{
		if (size > 21)
			ft_time_b(time + 15, &size, ls);
		else
		{
			ft_memcpy(ls->i + 7, time + 15, 5);
			size = 12;
		}
	}
	else
	{
		ft_memcpy(ls->i + 7, time + 7, 5);
		size = 12;
	}
	ls->i += size;
	ls->curfile->size[4] = size;
}
