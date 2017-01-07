CC=clang
LIBFT_PATH=../libft
CB_PATH=../circular_buffer
UTILS_PATH=../utility
FLAGS=-Wall -Wextra -g
LIB=-L./$(LIBFT_PATH) -lft_printf -lft_core -lft_list -L./$(CB_PATH) -lcircular_buffer \
	-L./$(UTILS_PATH) -lutils
NAME=server
INCLUDES=-I ../libft/includes -I ./includes -I ../includes -I ../circular_buffer/includes \
		 -I ../utility/includes


SRC=main.c \
	get_client.c \
	read_client.c \
	add_cmd.c \
	channel.c \
	send_msg_to_client.c \
	privmsg_construct.c \
	send_to_chan.c \
	signal_handler.c \
	send_success_login.c \
	const_global.c \
	errors/failure_exit.c \
	network/init_server.c \
	network/server.c \
	network/server2.c \
	network/check_select.c \
	msg_error/send_cannotsendchan.c \
	msg_error/send_err_cmd.c \
	msg_error/send_nosuchchannel.c \
	msg_error/send_cannotsendchan.c \
	msg/send_rpl_namereply.c \
	msg/send_rpl_endofname.c \
	msg/send_join_msg.c \
	fn/nick.c \
	fn/user.c \
	fn/join.c \
	fn/join_utils.c \
	fn/privmsg.c \
	fn/part.c \
	fn/names.c

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
