/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:17:11 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/15 03:22:36 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "./pipex_bonus.h"

void child_process (char *argv, char **envp)
{
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1)
        error_msg("Pipe error!");
    pid = fork();
    if (pid == -1)
        error_msg("Fork error!");
    else if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execute(argv, envp);
    }
    else if (pid != 0)    
    {
        waitpid(-1, NULL, 0);
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
    }    
}

void    here_doc(char **argv)
{
    int fd;
    char *line;
    
    fd = open("./.here_doc", O_WRONLY | O_CREAT | O_APPEND, 0777);
    while (1)
    {
        line = get_next_line(0);
        if (!line)
            break;        
        if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
        {
            free(line);
            break;
        }
        ft_putstr_fd(line, fd);
        free(line);
    }
    close(fd);
    fd = open("./.here_doc", O_RDONLY);
    dup2(fd, STDIN_FILENO);    
}

int main(int argc, char **argv, char **envp)
{
    int arg_index;
    int in_file;
    int out_file;
    
    arg_index = 0;
    if (argc < 5)
        args_error();
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        arg_index = 3;
        out_file = open(argv[argc - 1], O_RDONLY | O_APPEND | O_CREAT, 0777);
        here_doc(argv);
    }
    else
    {
        arg_index = 2;
        out_file = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
        in_file = open(argv[1], O_RDONLY);
        dup2(out_file, STDIN_FILENO);
    }
    while (arg_index < argc - 2)
    {
        child_process(argv[arg_index], envp);
        arg_index++;
    }
    dup2(out_file, STDOUT_FILENO);
    execute(argv[arg_index - 2], envp);
    return (0);
}
