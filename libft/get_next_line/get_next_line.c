/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denser <denser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 04:07:27 by denser            #+#    #+#             */
/*   Updated: 2019/10/26 01:34:03 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "get_next_line.h"

static int		ft_lstfdnew(t_list **fdlst, t_fdn *fdn, int fd)
{
	if (!(*fdlst = ft_lstnew(NULL, 0)))
		return (0);
	if (!(fdn = (t_fdn *)malloc(sizeof(*fdn))))
	{
		ft_lstdelone(fdlst, ft_lstdelcontent);
		return (0);
	}
	if (!(fdn->buf = ft_memalloc(BUFF_SIZE)))
	{
		free(fdn);
		ft_lstdelone(fdlst, ft_lstdelcontent);
		return (0);
	}
	fdn->fd = fd;
	fdn->lstline = NULL;
	fdn->div = fdn->buf;
	fdn->tail = NULL;
	fdn->size = 0;
	fdn->eof = 0;
	(*fdlst)->content = fdn;
	return (1);
}

static void		*ft_lstfdselect(t_list *fdlst, const int fd)
{
	while (fdlst && fdlst->next)
	{
		if (((t_fdn *)fdlst->content)->fd == fd)
			return (fdlst);
		fdlst = fdlst->next;
	}
	if (((t_fdn *)fdlst->content)->fd == fd)
		return (fdlst);
	if (!(ft_lstfdnew(&fdlst->next, NULL, fd)))
		return (NULL);
	return (fdlst->next);
}

static int		ft_rdbuf(t_fdn *fdn, t_list ***lstline, void *div, int res)
{
	if (!fdn->tail && !fdn->eof)
		if ((res = read(fdn->fd, fdn->buf, BUFF_SIZE)) == -1)
			return (0);
	fdn->eof = !res && !fdn->tail ? 1 : 0;
	if (fdn->eof && !fdn->tail)
		return (1);
	(**lstline) = ft_lstnew(NULL, 0);
	fdn->tail = res > 0 ? fdn->buf + res : fdn->tail;
	div = res > 0 ? fdn->buf : div;
	if (div == fdn->buf)
		fdn->div = ft_memchr(fdn->buf, '\n', fdn->tail - fdn->buf);
	if (!res && div != fdn->buf)
		(fdn->div = ft_memchr(div, '\n', fdn->tail - div));
	fdn->div = !fdn->div ? fdn->tail : fdn->div;
	if (!((**lstline)->content = malloc(fdn->div - div)))
		return (0);
	ft_memcpy((**lstline)->content, div, fdn->div - div);
	(**lstline)->content_size = fdn->div - div;
	fdn->size += fdn->div - div;
	fdn->tail = fdn->div == fdn->tail ? NULL : fdn->tail;
	if (fdn->tail)
		if (*(char *)fdn->div == '\n')
			return (1);
	*lstline = &(**lstline)->next;
	return (1);
}

static int		ft_rwline(t_list **fdlist, t_list *lstcur, t_list *lstline,
		char **line)
{
	char	*cur;
	t_fdn	*fdn;

	fdn = (t_fdn *)lstcur->content;
	*line = ft_memalloc(fdn->size + 1);
	cur = *line;
	while (lstline)
	{
		cur = ft_memcpy(cur, lstline->content, lstline->content_size)
				+ lstline->content_size;
		lstline = lstline->next;
	}
	ft_lstdel(&fdn->lstline, ft_lstdelcontent);
	fdn->size = 0;
	if (fdn->eof && !**line)
	{
		free(fdn->buf);
		ft_lstdel(&fdn->lstline, ft_lstdelcontent);
		ft_lstcut(fdlist, lstcur, ft_lstdelcontent);
		return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fdlst = NULL;
	t_list			*cur;
	t_list			**lstline;

	if (!fdlst)
		if (!ft_lstfdnew(&fdlst, NULL, fd))
			return (-1);
	if (!(cur = ft_lstfdselect(fdlst, fd)))
		return (-1);
	lstline = &((t_fdn *)cur->content)->lstline;
	while (!((t_fdn *)cur->content)->eof || ((t_fdn *)cur->content)->tail)
		if (!(ft_rdbuf((t_fdn *)cur->content, &lstline,
				((t_fdn *)cur->content)->div + 1, 0)))
			return (-1);
		else if (((t_fdn *)cur->content)->tail)
			if (*(char *)((t_fdn *)cur->content)->div == '\n')
				break ;
	if (!(ft_rwline(&fdlst, cur,
			((t_fdn *)cur->content)->lstline, line)))
		return (0);
	return (1);
}
