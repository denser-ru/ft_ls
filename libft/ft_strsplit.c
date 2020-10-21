/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 00:36:17 by cayako            #+#    #+#             */
/*   Updated: 2019/11/01 00:42:52 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**buf;
	t_list	*lststr;

	lststr = ft_lststrsplit(s, c);
	buf = ft_lststrtoarr(lststr);
	if (lststr)
		ft_lstdel(&lststr, ft_lstdelcontent);
	return (buf);
}
