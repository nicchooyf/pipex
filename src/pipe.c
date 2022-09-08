/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:12:10 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/05 14:07:03 by nchoo            ###   ########.fr       */
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
void do_pipex(t_pipe *data, char **av, char **env)
{
	while (++data->i < data->ac)
	{
		make_child(data, av, env);
	}
}