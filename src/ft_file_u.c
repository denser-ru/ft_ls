/*
 * ft_file_u.c by cayako
 */

#include "ft_ls.h"

void		ft_get_size(t_ls *ls, t_stat *stat)
{
	int		size;

	size = ft_itoa_mem_d(ls->bufdir, stat->st_size);
	if (!size)
		ft_memset(ls->i, '0', ++size);
	else
		ft_memcpy(ls->i, ls->bufdir, size);
	ls->i += size;
	ls->curfile->size[4] = size;
	if (ls->f_max_size[4] < size)
		ls->f_max_size[4] = size;
	ls->dirsize += stat->st_blocks << 9;
}