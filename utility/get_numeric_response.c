#include "get_numeric_response.h"

char	*get_numeric_response_custom(const char *data[], t_bool add_point)
{
	size_t		final_size;
	char		*res;

	final_size = ft_strlen(data[HOSTNAME]) + ft_strlen(data[CODE]) + ft_strlen(data[NICKNAME]) + ft_strlen(data[MSG]) + 16;
	res = malloc(final_size * sizeof(char));
	ft_bzero(res, final_size);
	res[0] = ':';
	ft_strcat(res, data[HOSTNAME]);
	ft_strcat(res, " ");
	ft_strcat(res, data[CODE]);
	ft_strcat(res, " ");
	ft_strcat(res, data[NICKNAME]);
	if (add_point)
		ft_strcat(res, " :");
	ft_strcat(res, data[MSG]);
	ft_strcat(res, "\x0D\x0A");
	return (res);
}

char	*get_numeric_response(const char *hostname, const char *code,
		const char *nickname, const char *msg)
{
	const char	*data[4];

	data[HOSTNAME] = hostname;
	data[CODE] = code;
	data[NICKNAME] = nickname;
	data[MSG] = msg;
	return (get_numeric_response_custom(data, TRUE));
}
