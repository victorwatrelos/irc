CC=clang
FLAGS=-Wall -Wextra
LIB=-L./libft -lft_printf -lft_core -lft_list
NAME=server
INCLUDES=-I libft/includes -I ./

SRC=main.c \
	init_server.c \
	server.c \
	server2.c \
	check_select.c \
	get_client.c \
	read_client.c \
	failure_exit.c


HEADER=$(SRC:.c=.h)

OBJ=$(SRC:.c=.o)

all: $(NAME)

.PHONY: clean fclean all re

$(NAME): $(OBJ) libft/libft_core.a libft/libft_printf.a libft/libft_list.a
	$(CC) $(FLAGS) $(INCLUDES) -o $@ $^ $(LIB) $(MLXLIB)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

libft/libft_core.a:
	(cd libft && $(MAKE))

clean:
	rm -rf $(OBJ)
	(cd libft && $(MAKE) clean)

fclean: clean
	rm -rf $(NAME)
	(cd libft && $(MAKE) fclean)

re: fclean all
