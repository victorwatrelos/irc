CC=clang
FLAGS=-Wall -Wextra -g
LIB=-L./libft -lft_printf -lft_core -lft_list
NAME=server
INCLUDES=-I libft/includes -I ./

SRC=main.c \
	circular_buffer.c \
	init_server.c \
	server.c \
	server2.c \
	check_select.c \
	get_client.c \
	read_client.c \
	add_cmd.c \
	const_global.c \
	fn/nick.c \
	utility/str_utils.c \
	utility/client_utils.c \
	send_err_cmd.c \
	failure_exit.c


HEADER=$(SRC:.c=.h)

OBJ=$(SRC:.c=.o)

all: $(NAME)

.PHONY: clean fclean all re
.SILENT:

$(NAME): $(OBJ) libft/libft_core.a libft/libft_printf.a libft/libft_list.a
	$(CC) $(FLAGS) $(INCLUDES) -o $@ $^ $(LIB) $(MLXLIB)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME) \033[0mDONE!"

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$@ \033[0mDONE!"

libft/libft_core.a:
	(cd libft && $(MAKE))

clean:
	rm -rf $(OBJ)
	echo "\t\xF0\x9F\x92\xA3   Cleaning"
	(cd libft && $(MAKE) clean)

fclean: clean
	rm -rf $(NAME)
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	(cd libft && $(MAKE) fclean)

re: fclean all
