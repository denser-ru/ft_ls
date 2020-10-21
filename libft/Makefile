# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayako <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 15:01:39 by cayako            #+#    #+#              #
#    Updated: 2020/03/04 18:33:45 by cayako           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC = *.c
OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))

INC=./

all: $(NAME)

$(NAME): $(SRC) libft.h
	gcc -c -Wall -Wextra -Werror $(SRC) -I$(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
