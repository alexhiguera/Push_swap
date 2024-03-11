#TODO: header

NAME	= pus_swap.exe

DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

CFLAGS 	= -Wall -Wextra -Werror
SILENCE = -s

SRC = main.c \
		cost.c do_moves.c position.c \
		push.c reverse_rotate.c \
		split.c rotate.c sort_three.c sort.c \
		stack.c start.c swap.c utils.c 

OBJS 	= ${SRC:.c=.o}

LIBFT_DIR = ./Libft_2.0/

.c.o:		%.o : %.c
					@echo "$(YELLOW)Compiling   ${RED}→   $(GREEN)$< $(DEF_COLOR)"
					@gcc ${CFLAGS} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "\033[32m *** Compiling dependencies... ***"
					@make re -C $(LIBFT_DIR) ${SILENCE}
					@make clean -C $(LIBFT_DIR) ${SILENCE}
					@gcc ${OBJS} -L Libft_2.0 -lft -o ${NAME}
					@echo "\033[36m Push_swap Compiled! o.o\n"

clean:
					@make clean -C $(LIBFT_DIR)
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C $(LIBFT_DIR) ${SILENCE}
					@rm -f $(NAME)
					@echo "\n\033[35m Deleting EVERYTHING! (-_-)\n"
					@echo "$$ART"

re:			fclean all

norminette:
		clear
		norminette src/
		norminette libft/

.PHONY: all clean fclean re norminette
