#include "parser/user_cmd.h"

static char *get_cmd(const char *str, char **start_params)
{
	int		end;
	char	*cmd;
	size_t	size;

	str++;
	end = jump_to_space(str, 0);
	if ((cmd = malloc(end + 1)) == NULL)
		return (NULL);
	ft_strncpy(cmd, str, end);
	cmd[end] = '\0';
	end = jump_end_of_space(str, end);
	if ((*start_params = ft_strdup(str + end)) == NULL)
		return (NULL);
	size = ft_strlen(*start_params);
	if (size < 1)
		return (cmd);
	if ((*start_params)[size - 1] == '\n')
		(*start_params)[size - 1] = '\0';
	return (cmd);
}

static void	execute_cmd(const char *cmd, const char *params, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < g_str_to_enum_stdin_size)
	{
		if (ft_strcmp(cmd, g_str_to_enum_stdin[i].cmd_str) != 0)
		{
			++i;
			continue ;
		}
		if (g_str_to_enum_stdin[i].need_connect && data->is_connected == FALSE)
		{
			disp_need_connect(data);
			return ;
		}
		if (g_str_to_enum_stdin[i].need_nick && data->is_logged == FALSE)
		{
			disp_need_nick(data);
			return ;
		}
		g_str_to_enum_stdin[i].cmd_fn(params, data);
		return ;
	}
}

void		parse_cmd(t_data *data, const char *full_cmd)
{
	char		*cmd;
	char		*start_params;
	size_t		size;

	size = ft_strlen(full_cmd);
	if (size <= 0 || full_cmd[0] != '/')
	{
		bad_cmd_stdin(full_cmd);
		return ;
	}
	if ((cmd = get_cmd(full_cmd, &start_params)) == NULL)
		return ;
	execute_cmd(cmd, start_params, data);
	free(cmd);
	free(start_params);
}
