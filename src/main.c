/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:11 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/30 23:28:14 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	char *options[3] = {"ls", NULL, NULL};
	// char *path;
	// char *cmd = "ls";

	(void)ac;
	(void)av;
	// path = get_right_path(envp, cmd);
	

	// ft_printf("%s\n", path);


	execve("/usr/bin/ls", options, envp);
}