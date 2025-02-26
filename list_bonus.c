#include "pipex_bonus.h"

t_cmd	*create_cmd_list(int argc, char **argv)
{
	t_cmd	*head;
	t_cmd	*new;
	t_cmd	*current;
	int		i;

	head = NULL;
	i = 2;
	while (i < argc - 1)
	{
		new = (t_cmd *)malloc(sizeof(t_cmd));
		if (!new)
			handle_error("Error: Memory allocation failed");
		new->cmd = argv[i];
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			current = head;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		i++;
	}
	return (head);
}

void	free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	while (cmd_list)
	{
		tmp = cmd_list;
		cmd_list = cmd_list->next;
		free(tmp);
	}
}
