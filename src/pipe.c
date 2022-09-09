/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:12:10 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/09 23:20:02 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *	./pipex file1 cmd1 ... cmd[i] file2
 *
 * 		
 *	i - index for av
 *	n - index for child
 */
void do_pipex(int ac, char **av, char **env)
{
	int i;
	int	n_commands;

	i = 0;
	n_commands = ac - 3;
	while (++i < n_commands)
	{
		get_right_path(env, av[i + 1]);
		make_child(i, av, env);
	}
}