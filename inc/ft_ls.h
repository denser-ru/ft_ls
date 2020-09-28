/* cayako */

#ifndef FT_LS_H

# include "libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
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
# define BUF		65536
# define MAX_NAME	256

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct		s_file
{
	void			*adr;
	int				size[6];
	int				max_size[5];
	time_t			ctime;
	mode_t			mode;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_ls
{
	char			*rootdir;
	t_list			*dirlist;
	t_file			*filelist;
	void			*bufdir;
	void			*buffile;
	void			*i;
	char			fname[MAX_NAME];
	off_t			dirsize;
	t_list			*prevdir;
	t_list			*curdir;
	t_list			*nextdir;
	t_file			*curfile;
}					t_ls;

void				ft_read_dir(t_ls *ls, t_dirent	*dirp, DIR *dir);
void				ft_add_file(t_ls *ls);
void				ft_print_dir(t_ls *ls);

#endif