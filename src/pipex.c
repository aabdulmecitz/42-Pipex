/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:59:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/30 04:40:54 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include "../lib/libft/libft.h"

void child_process(char **argv, char **envp, int *fd)
{
    int input_fd;

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1)
    {
        perror("open");
        error_msg("Unavailable file.");
    }
    dup2(input_fd, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(input_fd);
    execute(argv[2], envp);
}

void parent_process(char **argv, char **envp, int *fd)
{
    int output_fd;
    
    output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1)
    {
        perror("open");
        error_msg("Unavailable file.");
    }
    dup2(fd[0], STDIN_FILENO);
    dup2(output_fd, STDOUT_FILENO);
    close(fd[1]);
    close(output_fd);
    execute(argv[3], envp);
}

int main(int argc, char *argv[], char *envp[])
{
    int     fd[2];
    pid_t   pid;

    if (argc != 5)
        args_error();

    if (pipe(fd) == -1)
        error_msg("Something has gone wrong about pipe...");

    pid = fork();

    if (pid == -1)
    {
        error_msg("fork error");
        return 1;
    }
    else if (pid == 0)
        child_process(argv, envp, fd);
    else if (pid > 0)
    {
        close(fd[1]);
        parent_process(argv, envp, fd);
    }
        waitpid(-1, NULL, 0);

    return 0;
}



// int main() {
//     int file_fd;
//     int result;

//     // Dosyayı açma veya oluşturma
//     file_fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);


//     // Dosya tanıtıcısını stdout'a yönlendirme
//     result = dup2(file_fd, STDOUT_FILENO);


//     // Orijinal dosya tanıtıcısını kapatma
//     close(file_fd);
//     // Test çıktısı
//     printf("FD: %d Bu çıktı, output.txt dosyasına yazılacak\n", file_fd);
//     write(3, "3. file descriptiordan geldi.\n", 30);
//     // Başarılı bir şekilde tamamlandı
//     return 0;
// }


