# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 18:39:00 by ahiguera          #+#    #+#              #
#    Updated: 2024/03/18 13:40:13 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#████████████████████████████ Configuration ███████████████████████████████████#
NAME			= 	push_swap
CC				=	gcc
RM				=	rm -rf
CFLAGS 			= 	-Wall -Wextra -Werror

#██████████████████████████████ Colors ████████████████████████████████████████#
DEF_COLOR 		=	\033[0;39m
GRAY 			=	\033[0;90m
RED 			=	\033[0;91m
GREEN 			=	\033[0;92m
YELLOW 			=	\033[0;93m
BLUE 			=	\033[0;94m
MAGENTA 		=	\033[0;95m
CYAN 			=	\033[0;96m
WHITE 			=	\033[0;97m
BLACK 			=	\033[0;99m
ORANGE 			=	\033[38;5;209m
DARK_GRAY 		=	\033[38;5;234m
MID_GRAY 		=	\033[38;5;245m
DARK_YELLOW 	=	\033[38;5;143m
DARK_GREEN 		=	\033[38;2;75;179;82m
BROWN 			=	\033[38;2;184;143;29m

#█████████████████████████████ SOURCES █████████████████████████████████████████#
SRC_DIR			=	./src/
SRC 			= 	$(SRC_DIR)main.c 		$(SRC_DIR)cost.c					\
					$(SRC_DIR)do_moves.c 	$(SRC_DIR)position.c				\
					$(SRC_DIR)push.c 		$(SRC_DIR)reverse_rotate.c			\
					$(SRC_DIR)split.c 		$(SRC_DIR)rotate.c 					\
					$(SRC_DIR)sort_three.c	$(SRC_DIR)swap.c					\
					$(SRC_DIR)stack.c 		$(SRC_DIR)start.c					\
					$(SRC_DIR)sort.c 		$(SRC_DIR)utils.c					\

LIBFT			=	Libft_2.0/

#███████████████████████████████████████████████████████████████████████████████#

all:$(NAME)

$(NAME): 	$(SRC)
					@echo "$(GREEN)nCompiling dependencies...\n"
					@make re -C $(LIBFT) -s
					@$(CC) $(CFLAGS) Libft_2.0/libft.a $(SRC) -o $(NAME) 
					@echo "$(CYAN)\nPush_swap Compiled!\n"

clean:
					@make clean -C $(LIBFT)

fclean: 	clean
					@make fclean -C $(LIBFT)
					@$(RM) $(NAME)
					@echo "$(RED)\nDeleting EVERYTHING!\n"


normi:
					clear
					norminette src/

re: 		fclean all 

.PHONY: 	all clean fclean re