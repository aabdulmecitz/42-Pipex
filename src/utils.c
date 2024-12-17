/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:32:38 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/17 18:01:13 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "./pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*path_part;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0 && envp[i])
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (path);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		result;
	int		i;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_msg("Command splitting failed");
	path = find_path(cmd[0], envp);
	if (!path)
	{
		i = -1;
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error_msg("Command not found in PATH");
	}
	i = -1;
	result = execve(path, cmd, envp);
	free(path);
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
	if (result == -1)
		error_msg("execve failed");
}