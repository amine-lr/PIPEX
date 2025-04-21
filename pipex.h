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
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "printf/libftprintf.h"

char	*get_command_path(char *cmd, char **envp);
void	free_split(char **split);
void	execute_command(char *cmd, char **envp);
void	handle_error(const char *msg);
void	create_pipe(int pipefd[2]);
void	create_process(int fd_in, int fd_out, char *cmd, char **envp);

/* New helper functions */
char	**get_paths(char **envp);
char	*check_access(char *path, char *cmd);

#endif
