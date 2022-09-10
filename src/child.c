/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:08 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/10 20:22:55 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void dup_stdin(int i, char **av, int **fd)
{
	if (i == 0)
		dup2(open(av[1], O_RDONLY), STDIN);
	else
	{
		dup2(fd[i][0], STDIN);
	}
}

void dup_stdout(int i, int ac, char **av, int **fd)
{
	if (i == ac - 4) 
		dup2(open(av[ac - 1], O_WRONLY | O_CREAT), STDOUT);
	else
	{
		dup2(fd[i][1], STDOUT);
	}
}

void make_child(t_data *data, char **av, int **fd, char **env)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		ft_printf("pid:%d\n", pid);
		dup_stdin(data->i, av, fd);
		dup_stdout(data->i, data->ac, av, fd);
		run_process(data->i + 2, av, env);
	}
	else
	{
		int status;
		waitpid(pid, &status, -1);
		ft_printf("pid:%d\n", pid);
	}
	return ;
}