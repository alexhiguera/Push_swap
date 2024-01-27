NAME	= pus_swap.exe

CFLAGS 	= -Wall -Wextra -Werror
SILENCE = -s

SRCS 	=  	src/Push_swap.c	\
OBJS 	= ${SRCS:.c=.o}

LIBFT_DIR = ./Libft_2.0/

.c.o:		%.o : %.c
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
