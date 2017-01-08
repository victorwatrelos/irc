CC=clang
LIB= libutils \
	 libft \
	 libcircular_buffer

BIN= server_bin \
	 client_bin


.PHONY: clean fclean all re server client lib libft libutils libcircular_buffer
.SILENT:


all: $(BIN)


lib: $(LIB)

libft:
	make -C libft

libutils:
	make -C utility


libcircular_buffer:
	make -C circular_buffer


client_bin: lib
	make -C client

server_bin: lib
	make -C server

clean:
	make clean -C libft
	make clean -C utility
	make clean -C circular_buffer
	make clean -C server
	make clean -C client

fclean:
	make fclean -C libft
	make fclean -C utility
	make fclean -C circular_buffer
	make fclean -C server
	make fclean -C client

re: fclean all
