/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:08 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/11 15:13:33 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void dup_stdin(int i, char **av, int **fd)
{
	// ft_printf("stdin i:%d\n", i);
	if (i == 0)
		dup2(open(av[1], O_RDONLY), STDIN);
	else
		dup2(fd[i - 1][0], STDIN);
}

void dup_stdout(int i, int ac, char **av, int **fd)
{
	// ft_printf("stdout i:%d\n", i);
	if (i == ac - 4) 
	{
		dup2(open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC), STDOUT);
	}
	else
		dup2(fd[i][1], STDOUT);

}

void make_child(t_data *data, char **av, int **fd, char **env)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		dup_stdin(data->i, av, fd);
		dup_stdout(data->i, data->ac, av, fd);
		close_pipes(fd);
		run_process(data->i + 2, av, env);
	}
	else
	{
		int status;
		waitpid(0, &status, -1);
		ft_printf("pid:%d\n", pid);
	}
	return ;
}