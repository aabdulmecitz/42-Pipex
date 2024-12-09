/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:32:38 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/08 00:40:41 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "./pipex.h"


void	execute(char *argv, char **envp)
{
    char **cmd;
    char *path;
    int res;
    cmd = ft_split(argv, ' ');
    if (!cmd)
        error_msg("command couldn't split!");
    path = find_valid_path(cmd[0], envp);

    if (!path)
        error_msg("command not found in PATH");
    res = execve(path, cmd, envp);
}

char    *find_valid_path(char *cmd, char **envp)
{
    char *the_path;
    char **paths;
    int i;
    char *tmp;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0 && envp[i])
        i++;
    tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
    paths = ft_split(envp[i], ':');
    if (!*paths || !paths)
        error_msg("Error on the creating path");
    free(tmp);
    i = 0;
    while (paths[i])
    {
        the_path = make_path(paths[i], cmd);
        if (the_path != NULL)
            break;
        i++;
    }

    free_arr(paths);
    return(the_path);
}

char    *make_path(char *uncomplated_path, char *cmd)
{
    char *tmp;
    char *path;

    tmp = ft_strjoin(uncomplated_path, "/");
    if (!tmp)
        error_msg("The path couldnt be done.");
    path = ft_strjoin(tmp, cmd);
    free(tmp);
    if (access(path, F_OK) < 0)
        return NULL;
    return path;
}

void    free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i++])
        free(arr[i]);
    free(arr);
}