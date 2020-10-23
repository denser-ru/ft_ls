# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayako <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:28:03 by cayako            #+#    #+#              #
#    Updated: 2019/10/09 13:28:07 by cayako           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printfile

SRC = 	main.c\
		get_next_line.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I get_next_line.h

all: $(NAME)

$(OBJ): %.o: %.c
		-@gcc -c -Wall -Werror -Wextra -I libft/ $< -o $@

$(LIBFT):
	-@ make -C libft 

$(NAME): $(LIBFT) $(OBJ)
	-@ gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	-@ /bin/rm -f $(OBJ)
	-@ make -C libft clean

fclean: clean
	-@ /bin/rm -f $(NAME)
	-@ make -C libft fclean

re: fclean all
