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

char	**get_paths(char **envp)
{
	while (*envp && ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}

char	*check_access(char *path, char *cmd)
{
	char	*full_path;
	char	*temp;

	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

static char	*get_command_path_loop(char **paths, char *cmd)
{
	int		i;
	char	*result;

	i = 0;
	while (paths[i])
	{
		if (paths[i][0] == '\0')
		{
			i++;
			continue ;
		}
		result = check_access(paths[i], cmd);
		if (result)
		{
			free_split(paths);
			return (result);
		}
		i++;
	}
	free_split(paths);
	return (NULL);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;

	if (!cmd || !*cmd)
		return (NULL);
	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	return (get_command_path_loop(paths, cmd));
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
