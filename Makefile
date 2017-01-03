CC=clang

.PHONY: clean fclean all re
.SILENT:

all:
	make -C libft
	make -C utility
	make -C circular_buffer
	make -C server
	make -C client

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
