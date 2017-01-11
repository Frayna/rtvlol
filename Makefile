# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviau <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/11 11:02:36 by aviau             #+#    #+#              #
#    Updated: 2016/11/20 06:48:18 by aviau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rtv1

SRC_NAME =	main.c\
			key.c\
			mouse.c\
			math.c\
			equa.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = ./src/
OBJ_PATH = ./obj/
SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC=-L./libft/ -L./libmlx/ -L./libmatrix -I./include -I./libft -I./libmlx -I./libmatrix -I/usr/X11R6/include
ARG=-lft -lmlx -lmatrix -lm -lX11 -lXext -lpthread
CFLAGS = -Wall -Wextra# -Werror
DEPDIR				= .deps/
DEPFILES			= $(patsubst %.c,$(DEPDIR)%.d,$(SRC_NAME))

all: $(NAME)
	@printf "\t\t\e[32m[OK]\e[0m\n"

$(DEPDIR)/%.d: $(SRC_PATH)%.c $(DEPDIR)%.d
	@mkdir -p $(DEPDIR)
	@gcc $(CFLAGS) $(INC) -MM -MT $(DEPDIR)$(patsubst %.c,$(DEPDIR)%.d,$(notdir $@)) $< -MF $@

-include $(DEPFILES)

$(NAME): lib print_rt $(OBJ)
	@gcc -g -O0 $(CFLAGS) $(INC) $(OBJ) $(ARG) -o $@

lib:
	@make -C ./libft
	@make -C ./libmatrix

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	-@mkdir -p $(OBJ_PATH)
	@gcc $(CFLAGS) -c -o $@ $< $(INC)

clean:
	-@rm -rf $(OBJ_PATH) $(DEPDIR)
	@make -C ./libft $@
	@make -C ./libmatrix $@
	@printf "\e[33mobjects\t\t\e[31m[CLEAN]\e[0m\n"

fclean: clean
	-@rm $(NAME)
	@make -C ./libft $@
	@make -C ./libmatrix $@
	@printf "\e[33mrtv1\t\t\e[31m[CLEAN]\e[0m\n"

re: fclean all

print_rt:
	@printf "\e[33mrtv1"

.PHONY: fclean clean
