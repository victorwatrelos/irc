#include "read_stdin.h"

t_bool		read_stdin(t_data *data, const char *line)
{
	if (line == NULL)
		return (FALSE);
	parse_cmd(data, line);
	return (TRUE);
}
