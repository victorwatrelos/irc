#ifndef STRUCT_GLOBAL_H
# define STRUCT_GLOBAL_H

# include <global.h>

/**
 * First param: t_callback_cat_cmd
 * Second param: param_callback (payload)
 */
typedef int (*t_callback_cat_cmd)(void *, void *);

typedef struct			s_cat_cmd
{
	int					size_current_msg;
	char				curr_cmd[MAX_CMD_SIZE + 1];
	t_callback_cat_cmd	callback;
	void				*param_callback;
}						t_cat_cmd;


#endif
