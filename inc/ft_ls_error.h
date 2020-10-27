//
// Created by amazing_alex on 27.10.2020.
//

#ifndef FT_LS_ERROR_H
# define FT_LS_ERROR_H
# include <errno.h>

/*
 * malloc error use
 * print_error(NULL, 1);
 */

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

#endif
