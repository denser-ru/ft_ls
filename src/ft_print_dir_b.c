/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 03:11:15 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/03 03:11:17 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_print_name(void **in, void **out, t_file *file)
{
	ft_memcpy(*in, file->adr, file->size[5]);
	*in += file->size[5];
	ft_memcpy(*in, *out, file->size[6]);
	*in += file->size[6];
	ft_memcpy((*in)++, "\n", 1);
	return (file->size[5] + file->size[6] + 1);
}

int				ft_print_mod(void **in, void **out)
{
	ft_memcpy(*in, *out, 11);
	*in += 11;
	ft_memset(*in, ' ', 1);
	*in += 1;
	*out += 11;
	return (11 + 1);
}
