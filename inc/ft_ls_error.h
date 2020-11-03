/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:57:50 by gsinged           #+#    #+#             */
/*   Updated: 2020/10/28 20:57:56 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_ERROR_H
# define FT_LS_ERROR_H
# include <errno.h>

/*
** malloc error use
** print_error(NULL, 1);
*/

/*
** void	print_error(char *fname, char exit_err);
**
** Печатает ошибку errno, при необходимости может печатать текущий filename,
** если filename печатать не нужно указывать "NULL";
** exit_err - нужно ли использовать exit;
** Использовать при malloc и т.д.
*/

/*
** void	print_error_dir(char *fname, char print_fname);
**
** Возможно не понадобится
** печатает
**
** ls: fname: ERRNO ERROR
**
** print_fname - нужно ли при выводе ошибки (пример выше) печатать вначале
** file_name. Наприемер
**
** fname:
** ls: fname: ERRNO ERROR
**
** Использовать при opendir и т.д.
*/

/*
** void	print_ls_error_ls(char c) - используется при чтении аргументов
*/

void	print_error(char *fname, char exit_err);
void	print_ls_error_ls(char c);
void	print_error_dir(char *fname, char print_fname);

#endif
