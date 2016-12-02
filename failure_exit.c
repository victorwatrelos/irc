#include "failure_exit.h"

void	failure_exit(char const *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}
