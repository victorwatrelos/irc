#include "get_numeric_response.h"

char	*get_numeric_response(const char *hostname, const char *code,
		const char *nickname, const char *msg)
{
	size_t		final_size;
	char		*res;

	final_size = ft_strlen(hostname) + ft_strlen(code) + ft_strlen(nickname) + ft_strlen(msg) + 16;
	res = malloc(final_size * sizeof(char));
	ft_bzero(res, final_size);
	res[0] = ':';
	ft_strcat(res, hostname);
	ft_strcat(res, " ");
	ft_strcat(res, code);
	ft_strcat(res, " ");
	ft_strcat(res, nickname);
	ft_strcat(res, " :");
	ft_strcat(res, msg);
	ft_strcat(res, "\x0D\x0A");
	return (res);
}
