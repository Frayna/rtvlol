# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviau <aviau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 02:00:53 by aviau             #+#    #+#              #
#    Updated: 2016/11/16 09:25:22 by aviau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmatrix.a

SRC =	mtrx3.c\
		mtrx2.c\
		deg_rad.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : print_lib ./matrix.h $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\t\e[32m[OK]\e[0m\n"

%.o:%.c
	@gcc -c $< -o $@

clean :
	@printf "\e[33mlibmatrix"
	@rm -f $(OBJ)
	@printf "\t\e[31m[CLEAN]\e[0m\n"

fclean : clean
	@printf "\e[33mlibmatrix.a"
	@rm -f $(NAME)
	@printf "\t\e[31m[CLEAN]\e[0m\n"

re : clean all

print_lib :
	@printf "\e[33mlibmatrix"

.PHONY : all clean fclean re print_lib
