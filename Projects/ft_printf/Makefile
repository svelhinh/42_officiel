# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:14:36 by svelhinh          #+#    #+#              #
#    Updated: 2016/08/10 14:25:36 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
		libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memalloc.c libft/ft_memccpy.c \
		libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c \
		libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c \
		libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_strcat.c \
		libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c \
		libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c \
		libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c \
		libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c \
		libft/ft_strrchr.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c \
		libft/ft_tolower.c libft/ft_toupper.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c \
		libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_putrainbow.c libft/ft_putcolor.c \
		libft/ft_islower.c libft/ft_isupper.c libft/ft_putnbrendl.c libft/ft_itoa_base.c libft/ft_atoi_base.c \
		libft/ft_ftoa.c libft/get_next_line.c libft/ft_atof.c libft/ft_itoa_l.c libft/ft_putwchar.c\
		libft/ft_putwstr.c ft_printf.c conversions.c conversions2.c conversions3.c other.c

OBJ = $(SRC:.c=.o)

INCLUDES = includes -I libft/includes

SHELL = ZSH

all: $(NAME)

$(NAME) : $(OBJ)
		@ar rcs $(NAME) $(OBJ) $(OBJ2)
		@ranlib $(NAME)

%.o: %.c
		@echo "\033[96m"$< "\033[92m			√\033[0m"
		@gcc -o $@ -c $< -Wall -Wextra -Werror -I $(INCLUDES)

clean:
		@echo "\033[33mSuppression Objets LIBFT\033[0m"
		@rm -f $(OBJ)

fclean: clean
		@echo "\033[33mSuppression LIBFT\033[0m"
		@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
