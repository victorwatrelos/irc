CC=clang
LIBFT_PATH=../libft
CB_PATH=../circular_buffer
UTILS_PATH=../utility
FLAGS=-Wall -Wextra -g
LIB=-L./$(LIBFT_PATH) -lft_printf -lft_core -lft_list -L./$(CB_PATH) -lcircular_buffer \
	-L./$(UTILS_PATH) -lutils
NAME=client
INCLUDES=-I ../libft/includes -I ./includes -I ../includes -I ../circular_buffer/includes \
		 -I ../utility/includes


SRC=main.c \
	read_client.c \
	add_cmd.c \
	read_stdin.c \
	write_client.c \
	client_const_global.c \
	fn_stdin/nick_fn.c \
	parser/user_cmd.c \
	network/check_select.c \
	network/launch_connection.c \
	network/connect_to_server.c \
	errors/bad_cmd_stdin.c \
	errors/server_disconnect.c

HEADER=$(SRC:.c=.h)

OBJ=$(SRC:.c=.o)

all: $(NAME)

.PHONY: clean fclean all re
.SILENT:

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ $^ $(LIB) $(MLXLIB)
	echo "\t\xF0\x9F\x8F\x81   Linking \033[35m$(NAME) \033[0mDONE!"

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[34m$@ \033[0mDONE!"

clean:
	rm -rf $(OBJ)
	echo "\t\xF0\x9F\x92\xA3   Cleaning"

fclean: clean
	rm -rf $(NAME)
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"

re: fclean all
