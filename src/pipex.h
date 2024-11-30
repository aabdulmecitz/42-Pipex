/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:00:20 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/30 04:37:53 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
//# include "../libft/libft.h"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"


/* Mandatory functions */
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void    error_msg(char *msg);
void    args_error();
char    *find_path(char *argv, char **envp);
void    *free_arr(char **arr);
int		open_file(char *argv, int i);
void	usage(void);
char *path_creator(char *undone_path, char *code);


#endif