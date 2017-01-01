#ifndef CLIENT_UTILS_H
# define CLIENT_UTILS_H

# include <str_utils.h>
# include <bool.h>
# include <list.h>
# include <struct.h>
# include <get_numeric_response.h>

t_bool		is_nick_valid(const char *nick);
t_bool		is_nick_free(t_list *client_lst, const char *nick);
t_bool		is_username_free(t_list *client_lst, const char *upper_username);

#endif
