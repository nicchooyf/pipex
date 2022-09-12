/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:06:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/02 16:06:27 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int run_process(int i, char **av, char **envp)
{
	char **options;
	char *path;

	options = ft_split(av[i], ' ');
	path = get_right_path(envp, options[0]);
	if (!path)
		return (-1);
	execve(path, options, envp);
	return (0);
}