#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}	t_cmd;

char	*get_command_path(char *cmd, char **envp);
void	free_split(char **split);
void	execute_command(char *cmd, char **envp);
void	handle_error(const char *msg);
void	create_pipe(int pipefd[2]);
void	create_process(int fd_in, int fd_out, char *cmd, char **envp);
void	handle_multiple_pipes(int argc, char **argv, char **envp);
t_cmd	*create_cmd_list(int argc, char **argv);
void	free_cmd_list(t_cmd *cmd_list);

#endif
