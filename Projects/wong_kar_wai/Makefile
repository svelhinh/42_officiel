# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2016/01/31 17:56:01 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SRC = srcs/main.c srcs/init_tab.c srcs/display.c srcs/keys.c srcs/move.c	\
	  srcs/random.c srcs/check.c srcs/keys2.c srcs/move2.c srcs/game.c		\
	  srcs/menu.c

INCLUDES = includes

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "\033[91mIl n'y a plus rien a faire"

$(NAME):
		@sh sos
		@make re -C libft
		@echo "\033[96mCompilation"
		@gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) $(LIB) $(LIBFT) -I $(INCLUDES) -lncurses
		@make fclean -C libft

clean:
		@echo "\033[96mSuppression des objets"
		@rm -f $(OBJ)

fclean: clean
		@echo "\033[96mSuppression de l'executable"
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
