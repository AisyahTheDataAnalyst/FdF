# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 10:41:24 by aimokhta          #+#    #+#              #
#    Updated: 2025/02/25 11:34:00 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	ft_printf.a

SRC		=	ft_printf.c	\
			ft_printf_putnbr.c \
			ft_printf_putchar.c	\
			ft_printf_putstr.c \
			ft_printf_hex.c \
			ft_printf_pointer.c \
			ft_printf_unsigned.c 

OBJ		= 	$(SRC:.c=.o)
RM		= 	rm -f
LIBC	= 	ar -rcs
CC		= 	cc -g3 #-O0 -fsanitize=address
FLAG	= 	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@
# $@ (the target), $< (the first prerequisite).
# Stick to $() unless theres a specific reason to use ${}. It works in most cases without issues.
# Use ${} only if you’re combining variables with text directly (ex: echo ${VAR}world ) || referencing shell-specific variables like (ex: echo ${PATH}) or ${HOME}

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
