/*ft_print_dir.c by cayako*/

#include "ft_ls.h"

void	ft_print_size(void **in, void **out, t_file *file, int *i)
{
	ft_memcpy(*in, *out, file->size[4]);
	*in += file->size[4];
	*out += file->size[4];
	*i += file->size[4] + 1;
}

void	ft_print_dir(t_ls *ls)
{
	t_file	*file;
	void	*in;
	void	*out;
	int		i;

	file = ls->filelist;
	in = ls->bufdir;
	i = 0;
	while (file)
	{
		out = file->adr + file->size[5];
		ft_print_size(&in, &out, file, &i);
		ft_memcpy(in++, " ", 1);
		ft_memcpy(in, file->adr, file->size[5]);
		in += file->size[5];
		ft_memcpy(in++, "\n", 1);
		i += file->size[5] + 1;
		file = file->next;
	}
	ft_putnstr(ls->bufdir, i);
}