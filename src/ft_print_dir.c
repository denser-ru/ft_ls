/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:52:08 by cayako            #+#    #+#             */
/*   Updated: 2020/11/05 15:44:28 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_size2(t_ls *ls, void **in, void **out, t_file *file)
{
	ft_memset((*in)++, ',', 1);
	if (file->size[7] <= ls->f_max_size[5])
	{
		ft_memset(*in, ' ', ls->f_max_size[5] - file->size[7] + 1);
		*in += ls->f_max_size[5] - file->size[7] + 1;
	}
	else
	{
		ft_memset(*in, ' ', 1);
		*in += 1;
	}
	ft_memcpy(*in, *out, file->size[7]);
	*in += file->size[7];
	*out += file->size[7];
}

static int		ft_print_size(t_ls *ls, void **in, void **out, t_file *file)
{
	int		i;

	i = 0;
	if (!(file->size[7] > 0) && ls->f_max_size[5] > 0)
		i = ls->f_max_size[5] + 2;
	ft_memset(*in, ' ', ls->f_max_size[3] + i - file->size[3]);
	*in += ls->f_max_size[3] + i - file->size[3];
	ft_memcpy(*in, *out, file->size[3]);
	*in += file->size[3];
	*out += file->size[3];
	if (file->size[7] > 0)
		ft_print_size2(ls, in, out, file);
	ft_memcpy(*in, " ", 1);
	(*in)++;
	if (file->size[7] > ls->f_max_size[5])
		i = file->size[7] - ls->f_max_size[5];
	return (i + ls->f_max_size[3] + (file->size[7] > 0 ?
		ls->f_max_size[5] + 3 : 1));
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
	ft_memset(*in, ' ', 1);
	*in += 1;
	*out += file->size[1];
	ft_memset(*in, ' ', ls->f_max_size[1] - file->size[1] + 1);
	*in += ls->f_max_size[1] - file->size[1] + 1;
	ft_memcpy(*in, *out, file->size[2]);
	*in += file->size[2];
	*out += file->size[2];
	ft_memset(*in, ' ', ls->f_max_size[2] - file->size[2] + 1);
	*in += ls->f_max_size[2] - file->size[2] + 1;
	ft_memset(*in, ' ', 1);
	*in += 1;
	return (ls->f_max_size[1] + ls->f_max_size[2] + 2 + 2);
}

void			ft_print_dir_l(t_ls *ls, t_file *file, int i)
{
	void	*in;
	void	*out;

	in = ls->bufdir;
	file = file->next;
	while (file && file != ls->curfile)
	{
		out = file->adr + file->size[5];
		i += ft_print_mod(&in, &out);
		i += ft_print_nlink(ls, &in, &out, file);
		i += ft_print_pwd(ls, &in, &out, file);
		i += ft_print_size(ls, &in, &out, file);
		i += ft_print_time(&in, &out, file);
		i += ft_print_name(&in, &out, file);
		file = file->next;
	}
	if (in != ls->bufdir && ls->i != NULL)
	{
		ft_putnstr("total ", 6);
		ft_putnbr(ls->dirsize >> 10);
		ft_putchar('\n');
	}
	ft_putnstr(ls->bufdir, i);
}
