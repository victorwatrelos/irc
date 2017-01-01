CC=clang

.PHONY: clean fclean all re
.SILENT:

all:
	make -C libft
	make -C utility
	make -C circular_buffer
	make -C server

clean:
	make clean -C libft
	make clean -C utility
	make clean -C circular_buffer
	make clean -C server

fclean:
	make fclean -C libft
	make fclean -C utility
	make fclean -C circular_buffer
	make fclean -C server

re: fclean all
