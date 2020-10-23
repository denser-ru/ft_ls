/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:57:33 by cayako            #+#    #+#             */
/*   Updated: 2020/03/04 18:32:54 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE 512

typedef struct	s_fdn
{
	int			fd;
	t_list		*lstline;
	void		*buf;
	void		*div;
	void		*tail;
	size_t		size;
	char		eof;
}				t_fdn;

int				get_next_line(const int fd, char **line);

#endif
