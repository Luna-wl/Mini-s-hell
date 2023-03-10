NAME = minishell

SRCS =	my_split.c handle_problems.c

BLK=\e[0;30m
RED=\e[0;31m
GRN=\e[0;32m
YEL=\e[0;33m
BLU=\e[0;34m
MAG=\e[0;35m
CYN=\e[0;36m
WHT=\e[0;37m
RESET=\e[0m

LIB_DIR = libft/
LIB = $(LIB_DIR)/libft.a

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

DEL = rm -rf

%o: %c 
	@printf "$(GREEN)"
	@$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(LIB) -L/usr/local/lib -I/usr/local/include -lreadline -o $(NAME) $(OBJS)
#	@printf "$(RED)"
#	@cat hell.txt

clean:
	@make -C $(LIB_DIR) clean
	@$(DEL) $(OBJS)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@$(DEL) $(NAME)

re: fclean all

norm:
	@echo "---- NORMINETTE ----"
	@norminette -R CheckDefine *.h
	@norminette -R CheckForbiddenSourceHeader *.c
	@echo "---- THANK YOU ^w^Y ----"

.PHONY: norm clean fclean all re