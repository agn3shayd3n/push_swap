NAME = push_swap

SRCS = \
	srcs/utils/error_handling.c \
	srcs/utils/split.c \
	srcs/utils/stack_utils.c \
	srcs/node_stacking/init_nodes_a.c \
	srcs/node_stacking/init_nodes_b.c \
	srcs/node_stacking/push_swap.c \
	srcs/node_stacking/sort_stacks.c \
	srcs/node_stacking/start_stack.c \
	srcs/node_commands/push.c \
	srcs/node_commands/swap.c \
	srcs/node_commands/rev_rotate.c \
	srcs/node_commands/rotate.c \
	srcs/node_commands/sort_three.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Isrcs
RM = rm -f

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@${RM} ${OBJS}
	@echo "${GREEN}PUSH_SWAP COMPILED ✧*｡٩(ˊᗜˋ*)و✧*｡ ${RESET}"

clean:
	@${RM} ${OBJS}
	@echo "${YELLOW}CLEANED OBJECT FILES ╰( ´・ω・)つ──☆ *:・ﾟ✧ ${RESET}"

fclean: clean
	@${RM} ${NAME}
	@echo "${YELLOW}CLEANED EXECUTABLE °•°٩(◕‿◕｡)°•° ${RESET}"

re: fclean all

.PHONY: all clean fclean re
