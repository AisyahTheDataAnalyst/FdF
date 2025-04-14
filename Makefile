# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 13:45:31 by aimokhta          #+#    #+#              #
#    Updated: 2025/04/14 16:18:51 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc #-g3 -O3 -O0 -fsanitize=address -fsanitize-recover=leak

CFLAGS = -Wall -Wextra -Werror 

# directory that contains source files
FILE_DIR = srcs 

# use shell to find all files in the specified directories
SRC = $(shell find $(FILE_DIR) -type f -name '*.c')

INC = -I include -I libft -I ft_printf -I minilibx-linux
# this is what is caused to not write explicit path for all #includes in all header and c files
# -I means it will search the header in that directory that is mentioned in the each file's #include

OBJ_FOLDER = obj_files

# patsubst : pattern substitution function
# create a list of .o files in the object folder
OBJ_SRC = $(patsubst %.c, $(OBJ_FOLDER)/%.o, $(SRC))

LIBFT_DIR = libft/libft.a

FTPRINTF_DIR = ft_printf/ft_printf.a

# color
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m  #white

MINILIBX = minilibx-linux/
MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	make -C $(MINILIBX)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_SRC) $(INC) $(LIBFT_DIR) $(FTPRINTF_DIR) $(MINILIBX_LIBRARY) -o $(NAME)
	@echo "${GREEN}----------COMPILED DONE----------\n${RESET}"

$(OBJ_FOLDER)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
# add $(INC) to not do explicite path to all #include of all header and c files

clean:
	rm -rf $(OBJ_FOLDER)
	make fclean -C libft
	make fclean -C ft_printf
	make clean -C $(MINILIBX)
	rm -f libft.a

fclean : clean
	rm -f $(NAME)
	@echo "${GREEN}----------FULLY REMOVE----------\n${RESET}"

re : fclean all

norm : 
	@echo "${BLUE}----------NORMINETTE TIME!----------\n${RESET}"	
	@echo "${GREEN}----------srcs----------${RESET}"
	@norminette srcs
	@echo "${GREEN}\n----------include----------${RESET}"
	@norminette include
	@echo "${GREEN}\n----------libft----------${RESET}"
	@norminette libft
	@echo "${GREEN}\n----------ft_printf----------${RESET}"
	@norminette ft_printf
	@echo "${GREEN}\n       ALL CLEAR!✅✅✅\n${RESET}"

.PHONY : all clean fclean re norm