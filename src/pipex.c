/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:59:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/24 21:00:43 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include "../lib/libft/libft.h"

int child_process(char **argv, char **ergp, int *fd)
{
    
}

int parent_process(char **argv, char **ergp, int *fd)
{
    
}

int main(int argc, char *argv[], char *ergp[])
{
    int     fd[2];
    pid_t   pid;

    if (argc != 5)
        args_error();
    pid = fork();
    if (pid == -1)
    {
        error_msg("fork error");
        return 1;
    }
    else if (pid == 0)
        child_process(argv, ergp, fd);
    else if (pid > 0)
        parent_process(argv, ergp, fd);
    
    return 0;
}

