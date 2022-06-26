# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 14:56:42 by bfiguet           #+#    #+#              #
#    Updated: 2022/06/10 18:08:46 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f
INC = -Iinc/ -Ilibft/ \

LIBFT = -Llibft -lft

SRCS = $(addsuffix .c,	\
		$(addprefix src/, 	\
		push_swap \
		quick_sort \
		move \
		rot \
		rerot \
		utils \
		init_stack \
		list_utils \
		))	\
		

OBJS = $(SRCS:src/%.c=obj/%.o)

all:	$(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(OBJ_DIR): 
	@mkdir $(OBJ_DIR)

obj/%.o:src/%.c Makefile
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -sC libft clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -sC libft fclean
	@rmdir obj/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
