NAME = minihell

SRCS =	my_split.c

RED=\033[0;31;41m
GREEN=\033[0;32m
YEL=\033[0;37;47m
CYA=\033[1;36m
RESET=\033[0m

LIB_DIR = libft/
LIB = $(LIB_DIR)/libft.a

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

DEL = rm -rf

%o: %c 
	@printf "$(GREEN)"
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(LIB) -L/usr/local/lib -I/usr/local/include -lreadline -o $(NAME) $(OBJS)

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