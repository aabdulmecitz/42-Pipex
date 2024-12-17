/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:38:17 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/17 22:49:22 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

void	error_msg(char *msg);
void	args_error(void);
void	free_arr(char **arr);
void	child_process(char **argv, char **envp, int *fd);
void	free_array(char **array);
void	execute(char *argv, char **envp);
char	*find_valid_path(char *cmd, char **envp);
char	*make_path(char *uncompleted_path, char *cmd);

#endif