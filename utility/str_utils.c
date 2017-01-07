#include "str_utils.h"

int			jump_end_of_space(const char *str, int pos)
{
	while (str[pos] != '\0' && ft_strchr(LIST_SPACE_CHAR, str[pos]) != NULL)
		pos++;
	return (pos);
}

int			jump_to_space(const char *str, int pos)
{
	while (str[pos] != '\0' && ft_strchr(LIST_SPACE_CHAR, str[pos]) == NULL)
		pos++;
	return (pos);
}

const char	*next_param(const char *str, int *size, const char **next)
{
	const char	*start;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '\0')
		return (NULL);
	start = str;
	*size = 0;
	while (*str != ' ' && *str != '\t' && *str != '\0')
	{
		(*size)++;
		str++;
	}
	*next = str;
	return (start);
}

char		*ft_strndup(const char *str, size_t size)
{
	char	*res;

	res = malloc(size + 1);
	ft_strncpy(res, str, size);
	res[size] = '\0';
	return (res);
}

void		to_upper_rfc(char *str)
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
