/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:59:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/24 19:36:25 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int child_process()
{
    
}

int parent_process()
{
    
}

int main(int argc, char *argv[], char *ergv[])
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork hatası");
        return 1;
    }

    if (pid == 0) {
        // Çocuk süreç
        printf("Çocuk sürecin PID'si: %d\n", getpid());
    } else {
        // Ebeveyn süreç
        printf("Ebeveyn sürecin PID'si: %d, Çocuğun PID'si: %d\n", getpid(), pid);
    }

    return 0;
}

