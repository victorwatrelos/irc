#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "../bool.h"
# include <libft.h>

int			jump_end_of_space(const char *str, int pos);
int			jump_to_space(const char *str, int pos);
void		to_upper_rfc(char *str);
const char	*next_param(const char *str, int *size, const char **next);
char		*ft_strndup(const char *str, size_t size);

#endif
