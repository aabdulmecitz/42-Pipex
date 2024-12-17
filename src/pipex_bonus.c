/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:17:11 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/17 20:41:09 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void child_process(char *argv, char **envp)
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
		close(fd[1]);
		execute(argv, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void here_doc(char **argv)
{
	int fd;
	char *line;

	fd = open("./.here_doc", O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		error_msg("here_doc temp file error!");
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
	if (fd == -1)
		error_msg("here_doc temp file read error!");
	dup2(fd, STDIN_FILENO);
	close(fd);
}

int main(int argc, char **argv, char **envp)
{
	int arg_index;
	int in_file;
	int out_file;

	if (argc < 5)
		args_error();
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		arg_index = 3;
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		here_doc(argv);
	}
	else
	{
		arg_index = 2;
		in_file = open(argv[1], O_RDONLY);
		dup2(in_file, STDIN_FILENO);
		close(in_file);
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	while (arg_index < argc - 2)
		child_process(argv[arg_index++], envp);
	dup2(out_file, STDOUT_FILENO);
	close(out_file);
	return (execute(argv[arg_index], envp), 0);
}
