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

# define LS_A		1U
# define LS_L		2U
# define LS_RR		4U
# define LS_R		8U
# define LS_T		16U
# define LS_D		32U
# define LS_G		64U
# define LS_ONE		128U
# define LS_SS		256U
# define LS_S		512U
# define LS_UU		1024U
# define LS_I		2048U

# define BUF		1048576000U
# define MAX_NAME	1024

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_file
{
	void				*adr;
	int					size[7];
	time_t				ctime;
	mode_t				mode;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

typedef struct			s_direct
{
	char				*dname;
	t_file				*file;
	struct s_direct		*next;
}						t_direct;

typedef struct			s_ls
{
//	t_list				*dirlist;
	t_file				*filelist;
	void				(*ls_func)();
	void				(*sort_dirs)();
	void 				(*sort_files)();
	void				*bufdir;
	void				*buffile;
	void				*i;
	unsigned long long	fl;
	char				fname[MAX_NAME];
	off_t				dirsize;
	t_direct			*curdir;
	t_file				*curfile;
	t_file				*endfile;
	int					f_max_size[5];
	time_t				ltime;
}						t_ls;

void					ft_ls(char *fname, char d, t_ls *ls);
void					ft_read_dir_l(t_ls *ls, t_dirent *dirp, DIR *dir, \
											t_direct **dirlist);
void					ft_read_dir(t_ls *ls, t_dirent *dirp, DIR *dir, \
											t_direct **dirlist);


void					ft_sort_files(t_ls *ls, char *name);
void					ft_sort_files_r(t_ls *ls, char *name);
void					ft_sort_files_t(t_ls *ls, char *name);
void					ft_sort_files_t_r(t_ls *ls, char *name);
void					ft_get_spot(t_ls *ls, char *name);
void					ft_ls_rec(t_ls *ls);
void					ft_ls_l(t_ls *ls);
t_file					*ft_file_new();
void					ft_filelist_init(t_ls *ls);
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

t_direct				*ft_direct_new(char *dname, t_file *file);
void					ft_direct_pushb(t_direct **root, char *dname, t_ls *ls);

void					ft_sort_dirs(t_direct *d, t_direct *cur);
void					ft_sort_dirs_r(t_direct *d, t_direct *cur);
void					ft_sort_dirs_t(t_direct *d, t_direct *cur);
void					ft_sort_dirs_t_r(t_direct *d, t_direct *cur);

void					ft_ls_file(char *fname, t_ls *ls);
void					ft_read_file(char *fname, t_ls *ls);
void 					ft_get_symlink(t_ls *ls);


#endif
