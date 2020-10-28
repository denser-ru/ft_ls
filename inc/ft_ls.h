/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:02:57 by cayako            #+#    #+#             */
/*   Updated: 2020/10/21 22:03:01 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_ls_error.h"
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

/*
** -a (LS_A) to display hidden files, current folder and previous folder,
** -l (LS_L) to get more details, -d to display current folder only,
** -R (LS_RR) recursively list subfolders encountered,
** -r (LS_R) reverse the order of the sort to get reverse ASCII order or the
** oldest entries first (or largest files last, if combined with sort by size
** -t (LS_T) to display by time creation
** -c (LS_C) to color folders
** -1 (LS_ONE) to display results on one column,
*/

# define LS_A		1
# define LS_L		2
# define LS_RR		4
# define LS_R		8
# define LS_T		16
# define LS_D		32
# define LS_G		64
# define LS_ONE		128
# define LS_SS		256
# define LS_S		512
# define LS_UU		1024
# define LS_I		2048

# define BUF		1048576
# define MAX_NAME	1024

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_file
{
	void				*adr;
	int					size[6];
	time_t				ctime;
	mode_t				mode;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

typedef struct			s_ls
{
	t_list				*dirlist;
	t_file				*filelist;
	void				(*ls_func)();
	int					(*sort_dirs)();
	void 				(*sort_files)();
	void				*bufdir;
	void				*buffile;
	void				*i;
	unsigned long long	fl;
	char				fname[MAX_NAME];
	off_t				dirsize;
	t_list				*curdir;
	t_file				*curfile;
	t_file				*endfile;
	int					f_max_size[5];
}						t_ls;

void					ft_ls(char *fname, char d, t_ls *ls);
void					ft_read_dir_l(t_ls *ls, t_dirent	*dirp, DIR *dir,
						t_list **dirlist);
void					ft_read_dir(t_ls *ls, t_dirent	*dirp, DIR *dir,
						t_list **dirlist);
int 					ft_sort_dirs(t_ls *ls);
int 					ft_sort_dirs_r(t_ls *ls);
void					ft_sort_files(t_ls *ls, char *name);
void					ft_sort_files_r(t_ls *ls, char *name);
void					ft_get_spot(t_ls *ls, char *name);
void					ft_ls_rec(t_ls *ls);
void					ft_ls_l(t_ls *ls);
t_file					*ft_file_new();
void					ft_add_file(t_ls *ls);
void					ft_next_curfile(t_ls *ls);
void					ft_del_filelist(t_file **file);

void					ft_get_mode(t_ls *ls, t_stat *stat);
void					ft_get_nlink(t_ls *ls, t_stat *stat);
void					ft_get_pwd(t_ls *ls, t_stat *stat);
void					ft_get_size(t_ls *ls, t_stat *stat);
void					ft_get_ctime(t_ls *ls, t_stat *stat);

int						ft_print_mod(void **in, void **out);
void					ft_print_dir_l(t_ls *ls, t_file	*file, int i);
void					ft_print_dir(t_ls *ls, t_file	*file, int i);

void					ft_get_fname(t_ls *ls, t_dirent *dirp, char *fname);
void					ft_init_max_size(t_ls *ls, int i);
t_dirent				*ft_get_dirp(t_dirent *dirp, DIR *dir,
									unsigned long long fl);
void					ft_void_func(void);
int						ft_void_func_dir(void);
void					ft_print_dirlist(t_ls *ls, int one);

#endif
