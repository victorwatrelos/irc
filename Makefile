CC=clang

.PHONY: clean fclean all re server client lib
.SILENT:

client: lib
	make -C client

server: lib
	make -C server

lib:
	make -C libft
	make -C utility
	make -C circular_buffer

all: lib client server

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
