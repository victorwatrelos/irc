#ifndef GET_NUMERIC_RESPONSE_H
# define GET_NUMERIC_RESPONSE_H

# include <libft.h>

char	*get_numeric_response(const char *hostname, const char *code,
		const char *nickname, const char *msg);
char	*get_numeric_response_params(t_param_numeric_response *resp);


#endif
