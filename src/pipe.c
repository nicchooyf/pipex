/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:12:10 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/13 18:56:12 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *	Struct to pass int values
 *
 *	# of commands = ac - 3;
 */
t_data	*init_data(int ac)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->i = -1;
	data->ac = ac;
	data->n_commands = ac - 3;
	data->hd = 0;
	return (data);
}

/*
 *	Creates a pipe for each
 *	pair of commands
 */
int	**make_pipes(int ac)
{
	int	n;
	int	i;
	int	**fd;

	i = -1;
	n = ac - 4;
	fd = malloc((n + 1) * sizeof(int *));
	while (++i < n)
	{
		fd[i] = malloc(2 * sizeof(int));
		pipe(fd[i]);
	}
	fd[n] = NULL;
	return (fd);
}

/*
 *	Closes both ends of each pipe
 *	and frees the allocated fd
 */
void	close_pipes(int **fd)
{
	int	i;

	i = -1;
	while (fd[++i])
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
	}
	free(fd);
}

/*
 *	Creates pipes for each pair of commands,
 *	then calls forks for each command given
 *
 *	If here_doc was encountered, deletes and unlinks
 *	the temporary file
 */
void	do_pipex(t_data *data, char **av, char **env)
{
	int	**fd;

	fd = make_pipes(data->ac);
	while (++data->i < data->n_commands)
		do_child(data, av, fd, env);
	if (data->hd > 0)
		unlink("here_doc.txt");
	close_pipes(fd);
}
