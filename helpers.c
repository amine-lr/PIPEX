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

static char	**get_paths(char **envp)
{
	while (*envp && ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}

static char	*check_access(char *path, char *cmd)
{
	char	*full_path;

	full_path = ft_strjoin(path, "/");
	if (!full_path)
		return (NULL);
	full_path = ft_strjoin_free(full_path, cmd);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*result;
	int		i;

	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
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
