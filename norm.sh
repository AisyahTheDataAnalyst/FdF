#!/bin/bash

GREEN="\033[0;32m"
RESET="\033[0m"

echo -e "${GREEN}srcs${RESET}"
norminette srcs
echo ""
norminette include
echo ""
norminette libft
echo ""
norminette ft_printf
