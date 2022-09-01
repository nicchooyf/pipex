/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:11 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/01 21:23:19 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

int main(int ac, char **av, char **env)
{
	char *options[3] = {"ls", "-la", NULL};
	char *path;
	char *cmd = "ls";

	(void)ac;
	(void)av;
	path = get_right_path(env, cmd);

	execve(path, options, env);
	perror("error");
}