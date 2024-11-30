/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:54:53 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/30 04:38:13 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "pipex.h"



void execute(char *argv, char **envp)
{
    char *temp;
    char *path;
    char **arr;
    arr = ft_split(argv, ' ');
    if (!arr)
        error_msg("Analysis couldn't done.");
    path = find_path(argv, envp);
    if (!path)
    {
        free_arr(arr);
        error_msg("Finding path gone wrong!");
    }
    
    execve(path, arr, envp);
}
char *find_path(char *argv, char **envp)
{
    int i;
    char **paths;
    char *temp;
    char *valid_path;

    i = 0;
    while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0);
        i++;
    temp = ft_substr(envp[i], 5, (ft_strlen(envp[i]) - 5));
    paths = ft_split(temp, ':');
    if (!paths || !*paths)
        return(error_msg("paths cant split"), NULL);
    i = 0;
    free (temp);
    while (paths[i])
    {
        valid_path = path_creator(paths[i++], argv);
        if (!valid_path)
            break;
    }
    free_arr(paths);
    return(valid_path);
}

char *path_creator(char *undone_path, char *code)
{
    char *tmp;
    char *valid_path;

    tmp = ft_strjoin(undone_path, "/");
    if (!tmp)
        return(error_msg("joining / process gone wrong"), NULL);
    valid_path = ft_strjoin(tmp, code);
    free (tmp);
    if (!valid_path)
        return(error_msg("joining code process gone wrong"), NULL);
    if ((access(valid_path, F_OK) < 0))
        return (error_msg("that is not valid path"), NULL);
    return (valid_path);
}

void *free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}