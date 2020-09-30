/*ft_print_dir.c by cayako*/

#include "ft_ls.h"

static int		ft_print_size(t_ls *ls, void **in, void **out, t_file *file)
{
	ft_memset(*in, ' ', ls->f_max_size[4] - file->size[4]);
	*in += ls->f_max_size[4] - file->size[4];
	ft_memcpy(*in, *out, file->size[4]);
	*in += file->size[4];
	*out += file->size[4];
	ft_memcpy(*in, " ", 1);
	(*in)++;
	return (file->size[4] + 1 + ls->f_max_size[4] - file->size[4]);
}

int		ft_print_mod(void **in, void **out)
{
	ft_memcpy(*in, *out, 11);
	*in += 11;
	*out += 11;
	return (11);
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
		i += ft_print_mod(&in, &out);
		i += ft_print_size(ls, &in, &out, file);
		ft_memcpy(in, file->adr, file->size[5]);
		in += file->size[5];
		ft_memcpy(in++, "\n", 1);
		i += file->size[5] + 1;
		file = file->next;
	}
	ft_putnstr("total: ", 7);
	ft_putnbr(ls->dirsize >> 10);
	ft_putchar('\n');
	ft_putnstr(ls->bufdir, i);
}