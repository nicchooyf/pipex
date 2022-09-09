/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:08 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/09 23:16:37 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void dup_stdin(int i, char **av, int *fd)
{
	i = 2 * i - 2;
	if (data->n == 0)
		dup2(open(av[1], O_RDONLY), STDIN);
	else
		dup2(fd[i], STDIN);
}

void dup_stdout(int i, char **av, int *fd)
{
	i = 2 * i + 1;
	if (data->n == data->ac - 3)
		dup2(open(av[data->ac - 1], O_WRONLY), STDOUT);
	else
		dup2(fd[i], STDOUT);
}

void make_child(int i, char **av, char **env)
{
	
}