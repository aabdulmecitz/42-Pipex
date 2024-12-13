/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:17:11 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/13 20:26:23 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "./pipex.h"

void child_process (char **argv, char **envp, int *fd)
{
    int input_fd;

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1)
        error_msg("Unavalilable input file");
    dup2(input_fd, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    execute(argv[2], envp);
}

void parent_process(char **argv, char **envp, int *fd)
{
    int out_fd;
    out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (out_fd == -1)
        error_msg("Unavalilable output file");
    dup2(fd[0], STDIN_FILENO);
    dup2(out_fd, STDOUT_FILENO);
    close(fd[1]);
    execute(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    pid_t pid;
    
    if (argc != 5)
        args_error();
    if (pipe(fd) == -1)
        error_msg("Pipe has not been started.");
    pid = fork();
    if (pid == 0)
        child_process(argv, envp, fd);
    if (pid == -1)
        error_msg("Fork Error!");
    if (pid != 0)
        parent_process(argv, envp, fd);
    return (0);
    
}