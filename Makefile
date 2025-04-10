NAME = fdf

CC = cc -g3 -O3 -O0 -fsanitize=address -fsanitize-recover=leak

CFLAGS = -Wall -Wextra -Werror 

# directory that contains source files
FILE_DIR = srcs 

# use shell to find all files in the specified directories
SRC = $(shell find $(FILE_DIR) -type f -name '*.c')

INC = -I include

OBJ_FOLDER = obj_files

# create a list of .o files in the object folder
OBJ_SRC = $(patsubst %.c, $(OBJ_FOLDER)/%.o, $(SRC))

LIBFT_DIR = libft/libft.a

FTPRINTF_DIR = ft_printf/ft_printf.a

# color
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

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
	$(CC) $(CFLAGS) -c $< -o $@

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

.PHONY : all clean fclean re