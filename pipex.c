/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:15:01 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/05 16:55:15 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_cmd_not_found(char *cmd)
{
	write(2, "Error: Command not found: ", 26);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !*cmd)
	{
		write(2, "Error: Empty command\n", 21);
		exit(127);
	}
	args = ft_split(cmd, ' ');
	if (!args)
		handle_error("Error: Failed to split command");
	path = get_command_path(args[0], envp);
	if (!path)
	{
		print_cmd_not_found(args[0]);
		free_split(args);
		exit(127);
	}
	execve(path, args, envp);
	free(path);
	free_split(args);
	if (errno == EACCES)
		exit(126);
	handle_error("Error: Execve failed");
}

void	parent_wait(int fd1, int *pipefd, pid_t pid1, pid_t pid2)
{
	int	status;
	int	exit_status;

	exit_status = 0;
	if (fd1 >= 0)
		close(fd1);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	exit(exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd1;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		handle_error("Usage: ./pipex file1 cmd1 cmd2 file2");
	fd1 = open(argv[1], O_RDONLY);
	if (pipe(pipefd) == -1)
		handle_error("Error: Pipe failed");
	pid1 = fork();
	if (pid1 == 0)
		child1(fd1, pipefd, argv, envp);
	pid2 = fork();
	if (pid2 == 0)
		child2(fd1, pipefd, argv, envp);
	parent_wait(fd1, pipefd, pid1, pid2);
}
