

#ifndef FT_LS_GSINGED_H
#define FT_LS_GSINGED_H

# include <errno.h>
# include "ft_ls.h"

/*
 * void	print_error(char *fname, char exit_err);
 *
 * Печатает ошибку errno, при необходимости может печатать текущий filename,
 * если filename печатать не нужно указывать "NULL";
 * exit_err - нужно ли использовать exit;
 * Использовать при malloc и т.д.
 */

/*
 * void	print_error_dir(char *fname, char print_fname);
 *
 * Возможно не понадобится
 * печатает
 *
 * ls: fname: ERRNO ERROR
 *
 * print_fname - нужно ли при выводе ошибки (пример выше) печатать вначале
 * file_name. Наприемер
 *
 * fname:
 * ls: fname: ERRNO ERROR
 *
 * Использовать при opendir и т.д.
 *
 */

/*
 * void	print_ls_error_ls(char c) - используется при чтении аргументов
 */

void	print_error(char *fname, char exit_err);
void	print_ls_error_ls(char c);
void	print_error_dir(char *fname, char print_fname);

void	ft_arguments(int argc, char **argv, t_ls *ls);
void	ft_arg_add_file(t_file *f, int i, t_stat *stat, char **argv);
int 	ft_arg_sort_lexicographical(t_file *f0, unsigned long long r);
int		ft_arg_sort_modified(t_file *f0);
void	ft_change(t_file *f);

#endif