/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:12:10 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/11 15:21:02 by nchoo            ###   ########.fr       */
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
	ft_printf("n:%d\n", n);
	fd = malloc(n * sizeof(int *));
	while (++i < n)
	{
		ft_printf("%d\n", i);
		fd[i] = malloc(2 * sizeof(int));
		pipe(fd[i]);
	}
	// i = 0;
	// while (fd[i])
	// 	printf("fd[%d]\n", i++);
	return (fd);
}

void close_pipes(int **fd)
{
	int i;

	i = -1;
	while (fd[++i])
	{
		printf("fd[%d]\n", i);
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
	}
	free(fd);
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
	// int pid;
	int **fd;
	t_data *data;

	fd = make_pipes(ac);
	data = init_data(ac);
	while (++data->i < data->n_commands)
	{
		make_child(data, av, fd, env);
	}
	// data->i = -1;
	// while (fd[++data->i])
	// {
	// 	free(fd[data->i]);
	// }
	// free(fd);
	// free(data);
}