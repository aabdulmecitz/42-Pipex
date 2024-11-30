/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:54:53 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/30 05:28:12 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "pipex.h"

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		result;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_msg("command splitting failed");
	path = find_valid_path(cmd[0], envp);
	if (!path)
	{
		free_array(cmd);
		error_msg("command not found in PATH");
	}
	result = execve(path, cmd, envp);
	free(path);
	free_array(cmd);
	if (result == -1)
		error_msg("execve failed");
}

char	*find_valid_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*valid_path;
	char	*tmp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0 && envp[i])
		i++;
	tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	paths = ft_split(tmp, ':');
	if (!paths || !*paths)
		error_msg("An error occurred while creating the paths.");
	free(tmp);
	i = 0;
	while (paths[i])
	{
		valid_path = make_path(paths[i++], cmd);
		if (valid_path != NULL)
			break ;
	}
	free_array(paths);
	return (valid_path);
}

char	*make_path(char *uncompleted_path, char *cmd)
{
	char	*path_part;
	char	*valid_path;

	path_part = ft_strjoin(uncompleted_path, "/");
	if (!path_part)
		error_msg("An error occurred while creating the path_part.");
	valid_path = ft_strjoin(path_part, cmd);
	free(path_part);
	if (access(valid_path, F_OK) < 0)
		return (NULL);
	return (valid_path);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
