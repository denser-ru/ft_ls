/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_u2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:50:10 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:50:13 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ft_itoa_mem_x(void *dest, unsigned int nb)
{
	const char		*hex = "0123456789abcdef";
	int				i;
	char			buf[8];

	i = 0;
	ft_memset(buf, '0', 8);
	ft_memset(dest, '0', 10);
	((char*)dest)[1] = 'x';
	dest += 2;
	while (nb > 0)
	{
		buf[i++] = hex[nb % 16];
		nb /= 16;
	}
	i = 7;
	while (i >= 0)
	{
		*(char*)(dest + 7 - i) = (char)buf[i];
		--i;
	}
	return (9);
}

static size_t		ft_itoa_mem_2d(t_ls *ls, t_stat *stat, int *size2)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, major(stat->st_rdev));
	if (!size)
		ft_memset(ls->bufdir, '0', ++size);
	*size2 = ft_itoa_mem_d(ls->bufdir + size, minor(stat->st_rdev));
	if (minor(stat->st_rdev) > 255)
		*size2 = ft_itoa_mem_x(ls->bufdir + size, minor(stat->st_rdev));
	if (!(*size2))
		ft_memset(ls->bufdir + size, '0', ++(*size2));
	ls->curfile->size[7] = *size2;
	if (ls->f_max_size[5] < *size2 && minor(stat->st_rdev) <= 255)
		ls->f_max_size[5] = *size2;
	return (size);
}

void				ft_get_size(t_ls *ls, t_stat *stat, int size, int size2)
{
	ls->curfile->mode = (S_ISCHR(stat->st_mode) || S_ISBLK(stat->st_mode));
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
