/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:43:58 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 20:44:58 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_gsinged.h"


/*
 *
 * void	ft_ls(char *fname, char d, t_ls *ls);
 * fname - filename
 * d - является ли filename каталогом. 0 (нет) или 1 (да)
 * ls - структура ls
 * В ls->filelist есть уже листы
 *
 */

/*static void	ft_ls(char *fname, char d, t_ls *ls)
{

}*/

void		ft_one_argument(char **argv, t_ls *ls)
{
	t_stat stat;

	errno = 0;
	if ((lstat(*argv, &stat)) == -1)
		print_error(*argv, 1);
	if (S_ISDIR(stat.st_mode))
		ft_ls(*argv, 1, ls);
	else
		ft_ls(*argv, 0, ls);
}

static int			flags_f(char c, unsigned long long *fl)
{
	if (c == 'a')
		*fl = *fl | LS_A;
	else if (c == 'l')
		*(fl) = *fl | LS_L;
	else if (c == 'R')
		*(fl) = *fl | LS_RR;
	else if (c == 'r')
		*(fl) = *fl | LS_R;
	else if (c == 't')
		*(fl) = *fl | LS_T;
	else if (c == 'U')
		*(fl) = *fl | LS_UU;
	else if (c == '1')
		*(fl) = *fl | LS_ONE;
	else if (c == 'i')
		*(fl) = *fl | LS_I;
	else
		print_ls_error_ls(c);
	return (0);
}

unsigned long long	flags(int *argc, char ***argv_orig, unsigned long long fl)
{
	int		i;
	int		j;
	char	**argv;

	i = 1;
	argv = *argv_orig;
	*(argv[0]) = '\0';
	while (i < *argc && *(argv[i]) == '-')
	{
		j = 1;
		while (argv[i][j])
			flags_f(argv[i][j++], &fl);
		*(argv[i]) = '\0';
		i++;
	}
	*argc -= i;
	* argv_orig = argv + i;
	return (fl);
}

int					main(int argc, char **argv)
{
	unsigned long long	fl;
	t_ls				*ls;

	fl = flags(&argc, &argv, 0);
	if (!(ls = (t_ls*)malloc(sizeof(t_ls))))
		print_error(NULL, 1);
	ft_bzero(ls, sizeof(t_ls));
	ls->fl = fl;
	if (argc == 1)
		ft_one_argument(argv, ls);
	else
		ft_arguments(argc, argv, ls);

//	void			ft_freemem(t_ls *ls, t_list **list)
//	ft_freemem(t_*ls, t_list **list);
	return (0);
}
