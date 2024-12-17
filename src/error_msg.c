/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:39:36 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/17 20:41:14 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    error_msg(char *msg)
{
	ft_printf(RED"ERROR:\n%s\n"RESET, msg);
	exit(EXIT_FAILURE);
}

void    args_error()
{
	printf(RED"%s"RESET, "************* ERROR **************\n");
	printf(RED"%s"RESET, "$ ./pipex infile cmd1 cmd2 outfile\n");
	printf(RED"%s"RESET, "               OR                 \n");
	printf(RED"%s"RESET, "$ ./pipex_bonus infile cmd1 cmd2 ... cmdn outfile\n");
	printf(RED"%s"RESET, "$ ./pipex_bonus here_doc LIMITER cmd1 cmd2 file\n");
	exit(EXIT_FAILURE);
}
