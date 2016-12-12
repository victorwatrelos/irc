#include "error_manager.h"



void		add_error(t_err *err, char *msg, char *code)
{
	if (err->size >= MAX_ERR)
		return ;
	err->err_str[err->size] = msg;
	err->code[err->size] = code;
	err->size++;
}
