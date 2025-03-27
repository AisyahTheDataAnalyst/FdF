# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:26:57 by aimokhta          #+#    #+#              #
#    Updated: 2025/03/27 13:42:58 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc #-g3 -O3 -O0 -fsanitize=address -fsanitize-recover=leak
CFLAGS = -Wall -Wextra -Werror  -Iinclude -Ilibft -Ift_printf -Iminilibx-linux #-g3

SRC_DIR = srcs
BUILD_DIR = build
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
INCLUDE_DIR = include
MLX_DIR = minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
MLX = $(MLX_DIR)/libmlx_Linux.a

FDF_SRCS = main.c \
			1.1_parsing.c \
			1.2_parsing_helper.c \
			1.3_parsing_freeing.c \
			mlx_functions.c

FDF_OBJS = $(FDF_SRCS:.c=.o)
FDF_OBJ_PATHS = $(FDF_OBJS:%=$(BUILD_DIR)/%)

# BONUS_SRCS = BONUS_bonus.c

# BONUS_OBJS = $(BONUS_SRCS:.c=.o)
# BONUS_OBJ_PATHS = $(BONUS_OBJS:%=$(BUILD_DIR)/%)
				
# BONUS_EXTRA_OBJS = a_to_b.o \
# 					b_to_a.o \
# 					error_handling.o \
# 					executions.o \
# 					freeing_exit.o \
# 					input_into_cdllist.o \
# 					inputting.o \
# 					opr_push.o \
# 					opr_reverse_rotate.o \
# 					opr_rotate.o \
# 					opr_swap.o \
# 					sort_small.o \
# 					steps_calc.o \
# 					turk_algo.o \
# 					FDF.o \
# 					utils.o 

# BONUS_EXTRA_OBJ_PATHS = $(BONUS_EXTRA_OBJS:%=$(BUILD_DIR)/%)

# Program Name
NAME = fdf
# BONUS_NAME = BONUS

# Colour
GREEN = \033[0;32m
WHITE = \033[0m

all: $(NAME)

$(NAME): $(FDF_OBJ_PATHS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -lXext -lX11 -lm -lz $(FDF_OBJ_PATHS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)
	@echo "$(GREEN)----------COMPILED FDF DONE---------\n$(WHITE)"

# bonus : $(BONUS_NAME)

# $(BONUS_NAME) : $(BONUS_OBJ_PATHS) $(LIBFT) $(FT_PRINTF) #$(BONUS_EXTRA_OBJ_PATHS)#$(BONUS_EXTRA_OBJ_PATHS)
# 	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ_PATHS) $(LIBFT) $(FT_PRINTF)  
# 	@echo "$(GREEN)----------COMPILED BONUS DONE---------\n$(WHITE)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I minilibx_linux -O3 -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@echo "$(GREEN)----------FULLY REMOVED----------\n$(WHITE)"

re: fclean all

.PHONY: all clean fclean re bonus