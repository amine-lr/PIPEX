/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 06:20:33 by mlarioui          #+#    #+#             */
/*   Updated: 2025/05/09 06:21:56 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2(int fd1, int *pipefd, char **argv, char **envp)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		perror(argv[4]);
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1 || dup2(fd2, 1) == -1)
		handle_error("Error: Dup2 failed");
	if (fd1 >= 0)
		close(fd1);
	close(fd2);
	close(pipefd[0]);
	execute_command(argv[3], envp);
}

void	child1(int fd1, int *pipefd, char **argv, char **envp)
{
	if (fd1 < 0)
	{
		perror(argv[1]);
		close(pipefd[1]);
		close(pipefd[0]);
		exit(1);
	}
	close(pipefd[0]);
	if (dup2(fd1, 0) == -1 || dup2(pipefd[1], 1) == -1)
		handle_error("Error: Dup2 failed");
	close(fd1);
	close(pipefd[1]);
	execute_command(argv[2], envp);
}
