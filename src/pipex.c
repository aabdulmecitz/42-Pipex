/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:59:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/24 23:31:49 by aabdulmecit      ###   ########.fr       */
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

// int main(int argc, char *argv[], char *ergp[])
// {
//     // int     fd[2];
//     // pid_t   pid;

//     // if (argc != 5)
//     //     args_error();
//     // pid = fork();
//     // if (pid == -1)
//     // {
//     //     error_msg("fork error");
//     //     return 1;
//     // }
//     // else if (pid == 0)
//     //     child_process(argv, ergp, fd);
//     // else if (pid > 0)
//     //     parent_process(argv, ergp, fd);
//     int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     dup2(file_fd, STDIN_FILENO);
//     close(file_fd);
//     printf("selam bro naber\n");
//     return 0;
// }

int main() {
    int file_fd;
    int result;

    // Dosyayı açma veya oluşturma
    file_fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);


    // Dosya tanıtıcısını stdout'a yönlendirme
    result = dup2(file_fd, STDOUT_FILENO);


    // Orijinal dosya tanıtıcısını kapatma
    close(file_fd);
    // Test çıktısı
    printf("FD: %d Bu çıktı, output.txt dosyasına yazılacak\n", file_fd);
    write(3, "3. file descriptiordan geldi.\n", 30);
    // Başarılı bir şekilde tamamlandı
    return 0;
}


