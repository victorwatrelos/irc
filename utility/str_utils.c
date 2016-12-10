#include "str_utils.h"

int		jump_end_of_space(const char *str, int pos)
{
	while (str[pos] == ' ' || str[pos] == '\t')
		pos++;
	return (pos);
}

int		jump_to_space(const char *str, int pos)
{
	while (str[pos] != ' ' && str[pos] != '\t' && str[pos] != '\0')
		pos++;
	return (pos);
}

void	to_upper_rfc(char *str)
{
	while (*str != '\0')
	{
		if (*str == '{')
			*str = '[';
		else if (*str == '}')
			*str = ']';
		else if (*str == '^')
			*str = '~';
		else if (*str == '|')
			*str = '\\';
		else
			*str = ft_toupper(*str);
		str++;
	}
}
