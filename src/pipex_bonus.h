/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:37:58 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/17 22:38:00 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"


void    error_msg(char *msg);
void	args_error(void);
void    free_arr(char **arr);
void	child_process(char *argv, char **envp);
void	free_array(char **array);
void	execute(char *argv, char **envp);
char	*find_valid_path(char *cmd, char **envp);
char	*make_path(char *uncompleted_path, char *cmd);

#endif