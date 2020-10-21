
## Created by cayako

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/

SRC = ft_ls.c ft_file_u.c ft_filelist.c ft_print_dir.c ft_read_dir.c ft_filemode.c \
		ft_ls_rec.c
OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))
LIBFT = $(FTDIR)libft.a

.PHONY: all clean fclean count

all: obj $(LIBFT) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(FTDIR) -o $@ -c $<

$(LIBFT):
	make -C $(FTDIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

count:
	wc ./src/*.c ./inc/*.h

clean:
	rm -f $(OBJDIR)*.o
	make -C $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTDIR) fclean

re: fclean all
