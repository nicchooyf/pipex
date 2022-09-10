/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:12:10 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/10 21:30:59 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*init_data(int ac)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->i = -1;
	data->ac = ac;
	data->n_commands = ac - 3;
	return (data);

}

int **make_pipes(int ac)
{
	int n;
	int i;
	int **fd;

	i = -1;
	n = ac - 4;
	fd = malloc(n * sizeof(int *));
	while (++i < n)
	{
		fd[i] = malloc(2 * sizeof(int));
		pipe(fd[i]);
	}
	return (fd);
}

/*
 *	./pipex file1 cmd1 ... cmd[i] file2
 *
 * 		
 *	i - index for av
 *	n - index for child
 */
void do_pipex(int ac, char **av, char **env)
{
	int **fd;
	t_data *data;

	fd = make_pipes(ac);
	data = init_data(ac);
	while (++data->i < data->n_commands)
	{
		make_child(data, av, fd, env);
	}
	data->i = -1;
	while (fd[++data->i])
	{
		free(fd[data->i]);
	}
	free(fd);
	free(data);
}