#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft.h"
#include "ft_printf.h"

char	*get_command_path(char *cmd, char **envp);
void	free_split(char **split);
void	execute_command(char *cmd, char **envp);
void	handle_error(const char *msg);
void	create_pipe(int pipefd[2]);
void	create_process(int fd_in, int fd_out, char *cmd, char **envp);

#endif
