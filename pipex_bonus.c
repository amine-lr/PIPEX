#include "pipex_bonus.h"

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

void	handle_multiple_pipes(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		fd_in;
	int		fd_out;
	t_cmd	*cmd_list;
	t_cmd	*current;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		handle_error("Error: Failed to open input file");
	cmd_list = create_cmd_list(argc, argv);
	current = cmd_list;
	while (current->next)
	{
		create_pipe(pipefd);
		create_process(fd_in, pipefd[1], current->cmd, envp);
		close(pipefd[1]);
		fd_in = pipefd[0];
		current = current->next;
	}
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		handle_error("Error: Failed to open output file");
	create_process(fd_in, fd_out, current->cmd, envp);
	close(fd_in);
	close(fd_out);
	while (cmd_list)
	{
		wait(NULL);
		cmd_list = cmd_list->next;
	}
	free_cmd_list(cmd_list);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		handle_error("Usage: ./pipex_bonus file1 cmd1 cmd2 ... cmdn file2");
	handle_multiple_pipes(argc, argv, envp);
	return (0);
}
