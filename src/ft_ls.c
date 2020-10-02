/*
 * main.c by cayako
 */

#include "ft_ls.h"

static void		ft_ls_init(t_ls *ls, char **argv)
{
	ls->argv = ++argv;
//	ls->bufls = (void*)malloc(sizeof(void) * BUF_LS);
	ls->bufdir = (void*)malloc(sizeof(void) * BUF);
	ls->buffile = (void*)malloc(sizeof(void) * BUF);
	ls->bufrec = (char*)malloc(sizeof(char) * BUF_REC);
	ft_strcpy(ls->cur_dirname, *(ls->argv));
	ls->i = ls->buffile;
	ls->filelist = NULL;
	ft_add_file(ls);
}

static void			ft_freemem(t_ls *ls)
{
	ft_del_filelist(&(ls->filelist));
	free(ls->bufdir);
	free(ls->buffile);
	free(ls->bufrec);
	free(ls);
}

int				main(int argc, char **argv)
{
	t_ls	*ls;

	if (argc <2)
		return (0);
	ls = (t_ls*)malloc(sizeof(t_ls));
	ft_ls_init(ls, argv);
	ft_ls_rec(ls, ls->bufrec);
	ft_freemem(ls);
	return (0);
}