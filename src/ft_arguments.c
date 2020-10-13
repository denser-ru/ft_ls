

#include "ft_ls.h"
#include <stdio.h>

/*
 * size[0] - i in char **argv. argv[i].
 * size[1] - number errno
 *
 * f->size[2] - количество списков
 */

void	ft_arg_add_file(t_file *f, int i, t_stat *stat, char **argv)
{
	t_file		*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		print_error(NULL, 1);
	ft_bzero(file, sizeof(t_file));
	file->size[0] = i;
	if (stat)
		file->ctime = stat->st_mtime;
	file->adr = argv[i];
	if (!f[0].next)
	{
		f[0].next = file;
		f[0 + 3].next = file;
		f[0].size[0] = 1;
	}
	else
	{
		(f[0 + 3].next)->next = file;
		f[0 + 3].next = (f[0 + 3].next)->next;
		f[0].size[0]++;
	}
}

void	ft_get_stat(char **argv, int i, t_file *f)
{
	t_stat	stat;

	errno = 0;
	if ((lstat(argv[i], &stat)) == -1)
	{
		ft_arg_add_file(&(f[0]), i, &stat, argv);
		(f[3].next)->size[1] = errno;
	}
	else if (stat.st_mode & S_IFDIR)
		ft_arg_add_file(&(f[2]), i, &stat, argv);
	else
		ft_arg_add_file(&(f[1]), i, &stat, argv);
}

char	ft_arg_r(unsigned long long r)
{
	r = r & LS_R;
	if (r > 0)
		return (1);
	else
		return (0);
}

void	ft_change(t_file *f)
{
	t_file		*c;

	c = f->next;
	f->next = f->next->next;
	c->next = f->next->next;
	f->next->next = c;
}

int		ft_arg_sort_lexicographical_r_b(t_file *f)
{
	int		n;

	n = 0;
	while (f->next->next)
	{
		if ((ft_strcmp(f->next->adr, f->next->next->adr)) < 0)
			ft_change(f);
		f = f->next;
		n++;
	}
	return (n);
}

int 	ft_arg_sort_lexicographical_r(t_file *f0)
{
	int		i;
	t_file	*f;
	int		n;

	if (!f0->next || !f0->next->next)
		return (0);
	f = f0;
	n = ft_arg_sort_lexicographical_r_b(f0) - 1;
	while (n > 0)
	{
		i = 0;
		f = f0;
		while (i++ < n)
		{
			if ((ft_strcmp(f->next->adr, f->next->next->adr)) < 0)
				ft_change(f);
			f = f->next;
		}
		n--;
	}
	return (0);
}

int		ft_arg_sort_lexicographical_b(t_file *f)
{
	int		n;

	n = 0;
	while (f->next->next)
	{
		if ((ft_strcmp(f->next->adr, f->next->next->adr)) > 0)
			ft_change(f);
		f = f->next;
		n++;
	}
	return (n);
}



int 	ft_arg_sort_lexicographical(t_file *f0, unsigned long long r)
{
	int		i;
	t_file	*f;
	int		n;

	if (!f0->next || !f0->next->next)
		return (0);
	if (ft_arg_r(r))
		return (ft_arg_sort_lexicographical_r(f0));
	f = f0;
	n = ft_arg_sort_lexicographical_b(f0) - 1;
	while (n > 0)
	{
		i = 0;
		f = f0;
		while (i++ < n)
		{
			if ((ft_strcmp(f->next->adr, f->next->next->adr)) > 0)
				ft_change(f);
			f = f->next;
		}
		n--;
	}
	return (0);
}

int			ft_arg_sort_modified(t_file *f0)
{
	t_file		*f;
	int			n;
	int			i;

	if (!f0->next || !f0->next->next)
		return (0);
	n = 0;
	f = f0;
	while (f->next->next)
	{
		if (f->next->ctime < f->next->next->ctime)
			ft_change(f);
		f = f->next;
		n++;
	}
	n--;
	while (n > 0)
	{
		i = 0;
		f = f0;
		while (i++ < n)
		{
			if (f->next->ctime < f->next->next->ctime)
				ft_change(f);
			f = f->next;
		}
		n--;
	}
	return (0);
}

void	ft_arg_gl_sort(t_file *f, unsigned long long fl)
{
	ft_arg_sort_lexicographical(&(f[0]), 0);
	ft_arg_sort_lexicographical(&(f[1]), fl);
	ft_arg_sort_lexicographical(&(f[2]), fl);
	ft_arg_sort_modified(&(f[1]));
	ft_arg_sort_modified(&(f[2]));
}

void	ft_arg_print_f1(t_file *f, char **argv)
{
	while (f)
	{
		ft_putstr("ls: ");
		ft_putstr(f->adr);
		ft_putstr(": ");
		ft_putstr(strerror(f->size[1]));
		ft_putchar('\n');
		f = f->next;
	}
}

void	ft_arg_print_test(t_file *f, char **argv)
{
	while (f)
	{
		ft_putstr(f->adr);
		ft_putchar(' ');
		ft_putstr(ctime(&f->ctime));
//		printf(" %s!\n", ctime(&f->ctime));
//		ft_putchar('\n');
		f = f->next;
	}
}

void	ft_arg_put(t_file *f, char **argv)
{
	ft_arg_print_f1(f[0].next, argv);
	//		ft_ls(1, argv, fl, 1);
	ft_arg_print_test(f[1].next, argv);
	ft_putchar('\n');
	//		ft_ls(1, argv, fl, 1);
	ft_arg_print_test(f[2].next, argv);

}

void	ft_arguments(int argc, char **argv, unsigned long long fl)
{
	int		i;
	t_file	f[6];

	ft_bzero(f, sizeof(f));
	i = 0;
	while (i < argc)
	{
		ft_get_stat(argv, i, f);
		i++;
	}
	ft_arg_gl_sort(f, fl);
	ft_arg_put(f, argv);
}

//../src/main.c ../libft ../src/ft_arguments.c
//../src bcfb ../src/main.c src arcs ../libft ../src/ft_arguments.c