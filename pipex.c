/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:15:01 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/05 16:55:15 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
		handle_error("Error: Failed to split command");
	path = get_command_path(args[0], envp);
	if (!path)
	{
		ft_printf("Error: Command not found: %s\n", args[0]);
		free_split(args);
		exit(1);
	}
	execve(path, args, envp);
	handle_error("Error: Execve failed");
	free(path);
	free_split(args);
	exit(1);
}

void	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		handle_error("Error: Pipe failed");
}

void	create_process(int fd_in, int fd_out, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		handle_error("Error: Fork failed");
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execute_command(cmd, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd1;
	int		fd2;
	int		pipefd[2];

	if (argc != 5)
		handle_error("Usage: ./pipex file1 cmd1 cmd2 file2");
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		handle_error("Error: Failed to open files");
	create_pipe(pipefd);
	create_process(fd1, pipefd[1], argv[2], envp);
	create_process(pipefd[0], fd2, argv[3], envp);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd1);
	close(fd2);
	wait(NULL);
	wait(NULL);
	return (0);
}
