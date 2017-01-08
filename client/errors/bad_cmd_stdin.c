#include "errors/bad_cmd_stdin.h"

void	bad_cmd_stdin(const char *msg)
{
	ft_printf("Unrecognize cmd: %s\n", msg);
}
