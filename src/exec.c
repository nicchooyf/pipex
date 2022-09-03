/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:09:36 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/03 15:29:40 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_process(int i, char **av, char **env)
{
	char **cmd;
	char *path;
	
	cmd = ft_split(av[i], ' ');
	path = get_right_path(env, cmd[0]);
	execve(path, cmd, env);
}