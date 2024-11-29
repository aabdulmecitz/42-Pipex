/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:59:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/29 22:32:52 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include "../lib/libft/libft.h"

int child_process(char **argv, char **envp, int *fd)
{
    int input_fd;

    input_fd = open(argv[1], O_RDONLY, 0655);
    if (input_fd == -1)
        error_msg("Unavailable file.");
    dup2(input_fd, STDOUT_FILENO);
    dup2(fd[1], STDIN_FILENO);
    close(fd[0]);
    execute(argv, envp);
}

int parent_process(char **argv, char **envp, int *fd)
{
    dup2(fd[0], STDOUT_FILENO);
    ft_printf("%s", argv[0]);
    close(fd[0]);
    execute(argv, envp);
    return 0;
}
int execute(char **argv, char **envp)
{
    return 0;
}
int main(int argc, char *argv[], char *envp[])
{
    int     fd[2];
    pid_t   pid;
    int     i;

    if (argc != 5)
        args_error();
    pid = fork();
    i = pipe(fd);
    if (i == -1)
        error_msg("Something has gone wrong about pipe...");
    if (pid == -1)
    {
        error_msg("fork error");
        return 1;
    }
    else if (pid == 0)
        child_process(argv, envp, fd);
    else if (pid > 0)
        parent_process(argv, envp, fd);
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    printf("selam bro naber\n");
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


