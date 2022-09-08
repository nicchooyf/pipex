/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:08 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/05 14:28:15 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void dup_stdin(t_pipe *data, char **av, int *fd)
{
	int	i;
	
	i = 2 * data->i - 2;
	if (data->n == 0)
		dup2(open(av[1], O_RDONLY), STDIN);
	else
		dup2(fd[i], STDIN);
}

void dup_stdout(t_pipe *data, char **av, int *fd)
{
	int i;
	
	i = 2 * data->i + 1;
	if (data->n == data->ac - 3)
		dup2(open(av[data->ac - 1], O_WRONLY), STDOUT);
	else
		dup2(fd[i], STDOUT);
}

void make_child(t_pipe *data, char **av, char **env)
{
	
}