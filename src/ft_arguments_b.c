/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:51:17 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/03 21:51:18 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_gsinged.h"

int			ft_get_stat_link(char *fname)
{
	t_stat	st;

	if ((stat(fname, &st) == -1))
		return (0);
	if (S_ISDIR(st.st_mode))
		return (1);
	else
		return (0);
}
