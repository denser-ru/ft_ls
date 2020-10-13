

#ifndef FT_LS_GSINGED_H
#define FT_LS_GSINGED_H

#include <errno.h>

void		print_error(char *fname, char exit_err);
void		print_ls_error_ls(char c);
void		print_error_dir(char *fname, char print_fname);

void		ft_arguments(int argc, char **argv, unsigned long long fl);


#endif //FT_LS_GSINGED_FT_LS_GSINGED_H
