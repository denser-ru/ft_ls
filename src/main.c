
#include <stdio.h>
//#include <stdlib.h>
#include "ft_ls.h"


# define LS_UU		32
# define LS_ONE		64
# define LS_I		128




int		ft_one_argument(char **argv, unsigned long long fl)
{
	t_stat stat;

	errno = 0;
	if ((lstat(*argv, &stat)) == -1)
		print_error(*argv, 1);

	//Вызов ft_ls (main cayako)

	if (S_ISDIR(stat.st_mode))
		printf("ISDIR\n");
	else
		ft_putendl("No");
//		ft_ls(1, argv, fl, 1);

//		ft_ls(1, argv, fl, 0);

	return (0);
}

int					flags_f(char c, unsigned long long *fl)
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

	fl = flags(&argc, &argv, 0);

	if (argc == 1)
		ft_one_argument(argv, fl);
	else
		ft_arguments(argc, argv, fl);


	//Вызов ft_ls (main cayako)

	return (0);
}
