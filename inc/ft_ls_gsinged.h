/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_gsinged.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:57:35 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 20:57:39 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_GSINGED_H
# define FT_LS_GSINGED_H

# include <errno.h>
# include "ft_ls.h"

void	ft_arguments(int argc, char **argv, t_ls *ls);
void	ft_arg_add_file(t_file *f, int i, t_stat *stat, char **argv);
int		ft_arg_sort_lexicographical(t_file *f0, unsigned long long r);
int		ft_arg_sort_modified(t_file *f0);
void	ft_change(t_file *f);

#endif
