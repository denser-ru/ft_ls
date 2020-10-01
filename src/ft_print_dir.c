/*ft_print_dir.c by cayako*/

#include "ft_ls.h"

static int		ft_print_size(t_ls *ls, void **in, void **out, t_file *file)
{
	ft_memset(*in, ' ', ls->f_max_size[3] - file->size[3]);
	*in += ls->f_max_size[3] - file->size[3];
	ft_memcpy(*in, *out, file->size[3]);
	*in += file->size[3];
	*out += file->size[3];
	ft_memcpy(*in, " ", 1);
	(*in)++;
	return (file->size[3] + 1 + ls->f_max_size[3] - file->size[3]);
}

static int		ft_print_nlink(t_ls *ls, void **in, void **out, t_file *file)
{
	ft_memset(*in, ' ', ls->f_max_size[0] - file->size[0]);
	*in += ls->f_max_size[0] - file->size[0];
	ft_memcpy(*in, *out, file->size[0]);
	*in += file->size[0];
	*out += file->size[0];
	ft_memcpy(*in, " ", 1);
	(*in)++;
	return (ls->f_max_size[0] + 1);
}

static int		ft_print_pwd(t_ls *ls, void **in, void **out, t_file *file)
{
	ft_memcpy(*in, *out, file->size[1]);
	*in += file->size[1];
	*out += file->size[1];
	ft_memset(*in, ' ', ls->f_max_size[1] - file->size[1] + 1);
	*in += ls->f_max_size[1] - file->size[1] +1;
	ft_memcpy(*in, *out, file->size[2]);
	*in += file->size[2];
	*out += file->size[2];
	ft_memset(*in, ' ', ls->f_max_size[2] - file->size[2] + 1);
	*in += ls->f_max_size[2] - file->size[2] +1;
	return (ls->f_max_size[1] + ls->f_max_size[2] + 2);
}

int		ft_print_time(void **in, void **out)
{
	ft_memcpy(*in, *out, 11);
	*in += 11;
	*out += 11;
	ft_memset((*in)++, ' ', 1);
	return (12);
}

void	ft_print_dir(t_ls *ls, t_file	*file, int i)
{
	void	*in;
	void	*out;

	in = ls->bufdir;
	while (file->adr)
	{
		out = file->adr + file->size[5];
		i += ft_print_mod(&in, &out);
		i += ft_print_nlink(ls, &in, &out, file);
		i += ft_print_pwd(ls, &in, &out, file);
		i += ft_print_size(ls, &in, &out, file);
		i += ft_print_time(&in, &out);
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