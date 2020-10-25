# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 22:11:50 by cayako            #+#    #+#              #
#    Updated: 2020/10/21 22:11:54 by cayako           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/

SRC = main.c ft_ls.c ft_file_u.c ft_filelist.c ft_print_dir.c ft_read_dir.c \
		ft_filemode.c ft_ls_rec.c ft_print_error.c ft_arguments.c \
		ft_arg_add_file.c ft_arg_sort.c ft_arg_sort_modified.c ft_sort_files.c \
		ft_read_u.c
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
