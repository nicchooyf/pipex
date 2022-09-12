/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:08 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/12 22:18:32 by nchoo            ###   ########.fr       */
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
void dup_stdin(t_data *data, char **av, int **fd)
{
	int file;
	
	if (data->hd > 0)
		dup2(data->hd, STDIN);
	else if (data->i == 0)
	{
		file = get_fd(data, av);
		dup2(file, STDIN);
	}
	else
		dup2(fd[data->i - 1][0], STDIN);
}

/*
 *	For the last child, redirects the file2 fd
 *	into STDOUT
 *
 *	Else, redirects the write portion of each pipe
 *	to STDOUT
 */
void dup_stdout(t_data *data, char **av, int **fd)
{
	int file;
	
	if (data->i == data->ac - 4) 
	{
		file = get_fd(data, av);
		dup2(file, STDOUT);
	}
	else
		dup2(fd[data->i][1], STDOUT);
}

/*
 *	Finds the PATH where the command is located
 *	and executes it. Process ends when execve
 *	is successful
 */
void	run_process(int i, char **av, char **env)
{
	char **cmd;
	char *path;

	cmd = ft_split(av[i], ' ');
	path = get_right_path(env, cmd[0]);
	if (!path)
		exit_error(cmd[0]);
	execve(path, cmd, env);
}

/*
 *	Forks a process that executes the command
 *
 *	As "execve" ends the calling process when successful,
 *	forking is necessary
 */
void do_child(t_data *data, char **av, int **fd, char **env)
{
	int pid;
	
	pid = fork();
	if (pid == 0)
	{
		dup_stdin(data, av, fd);
		dup_stdout(data, av, fd);
		close_pipes(fd);
		run_process(data->i + 2, av, env);
	}
}