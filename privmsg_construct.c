#include "privmsg_construct.h"

char	*get_priv_msg(const char *msg, const char *target, t_client *src)
{
	//nick@hostname PRIVMSG target :msg
	size_t		final_size;
	char		*res;

	final_size = ft_strlen(src->nickname);
	final_size += ft_strlen(src->hostname);
	final_size += sizeof(PRIVMSG) + ft_strlen(target);
	final_size += ft_strlen(msg) + 4;
	if ((res = malloc(final_size)) == NULL)
		return (NULL);

	ft_strcpy(res, ":");
	ft_strcat(res, src->nickname);
	ft_strcat(res, "@");
	ft_strcat(res, src->hostname);
	ft_strcat(res, PRIVMSG);
	ft_strcat(res, target);
	ft_strcat(res, " ");
	ft_strcat(res, msg);
	return (res);
}
