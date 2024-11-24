/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:59:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/24 20:43:42 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int child_process()
{
    
}

int parent_process()
{
    
}

int main(int argc, char *argv[], char *ergv[])
{
    
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        error_msg("fork error");
        return 1;
    }
    else if (pid == 0)
        child_process();
    else if (pid > 0)
        parent_process();
    
    return 0;
}

