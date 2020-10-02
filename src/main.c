
#include <stdio.h>
//#include <stdlib.h>
#include "ft_ls.h"

void				print_err(char c)
{
	printf("ls: illegal option -- %c\n", c);
	printf("usage: ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%%] [file ...]");
	exit (0);
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
	else
		print_err(c);
	return (0);
}

unsigned long long	flags(int argc, char ** argv, unsigned long long fl)
{
	int		i;
	int		j;

	i = 1;
	*(argv[0]) = '\0';
	while (i < argc && *(argv[i]) == '-')
	{
		j = 1;
		while (argv[i][j])
			flags_f(argv[i][j++], &fl);
		*(argv[i]) = '\0';
		i++;
	}
	return (fl);
}

int					main(int argc, char **argv)
{
	unsigned long long	fl;

	fl = flags(argc, argv, 0);

	//Вызов ft_ls (main cayako)

	return (0);
}
