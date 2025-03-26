NAME = push_swap

SRCS = error_handling.c init_nodes_a.c init_nodes_b.c push_swap.c push.c swap.c \
rev_rotate.c rotate.c sort_stacks.c sort_three.c split.c stack_utils.c \
start_stack.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all:		${NAME}

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@${RM} ${OBJS}
			@echo "${GREEN}PUSH_SWAP COMPILED ✧*｡٩(ˊᗜˋ*)و✧*｡ ${RESET}"

clean:
	@${RM} ${OBJS}
	@echo "${YELLOW}CLEANED OBJECT FILES ╰( ´・ω・)つ──☆ *:・ﾟ✧ ${RESET}"

fclean:	clean
	@${RM} ${NAME}
	@echo "${YELLOW}CLEANED EXECUTABLE °•°٩(◕‿◕｡)°•° ${RESET}"

re:		fclean all

.PHONY: all clean fclean re