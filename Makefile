# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 21:12:21 by vcourtin          #+#    #+#              #
#    Updated: 2014/02/11 21:12:24 by vcourtin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_C = main.c new_room.c aff_test.c way.c ft_parsing.c ft_dijkstra.c

LIB_A = libft.a

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@cd libft; make re
	gcc -o $(NAME) $(FLAG) $(SRC_C) $(LIB_A)

gdb:
	@cd libft; make re
	gcc -g -o $(NAME) $(FLAG) $(SRC_C) $(LIB_A)

reload: re
	./$(NAME)

test: fclean gdb
	./$(NAME) 2>> TEST

clean:
	@cd libft; make clean
	@/bin/rm -f $(LIB_A)
	@rm -rf $(NAME).dSYM

fclean: clean
	@cd libft; make fclean
	@/bin/rm -f $(NAME)

re: fclean all

