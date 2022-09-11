/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:08 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/11 21:12:14 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *	For the 1st child, redirects the file1 fd
 *	into STDIN
 *
 *	Else, redirects the read portion of each pipe
 *	to STDIN
 */
void dup_stdin(int i, char **av, int **fd)
{
	int file;
	
	if (i == 0)
	{
		file = get_fd(1, 0, av);
		dup2(file, STDIN);
	}
	else
		dup2(fd[i - 1][0], STDIN);
}

/*
 *	For the last child, redirects the file2 fd
 *	into STDOUT
 *
 *	Else, redirects the write portion of each pipe
 *	to STDOUT
 */
void dup_stdout(int i, int ac, char **av, int **fd)
{
	int file;
	
	if (i == ac - 4) 
	{
		file = get_fd(2, ac, av);
		dup2(file, STDOUT);
	}
	else
		dup2(fd[i][1], STDOUT);
}

/*
 *	Forks a process that executes the command
 *
 *	As "execve" ends a process when successful,
 *	forking is necessary
 */
void do_child(t_data *data, char **av, int **fd, char **env)
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
	}
	return ;
}