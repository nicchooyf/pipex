/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:11 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/02 16:06:22 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	if (ac != 5)
		return (0);
	int fd[2];
	if (pipe(fd) == -1) return (1);

	int pid = fork();
	int pid2 = fork();
	if (pid == -1) return (2);
	if (pid2 == -1) return (3);

	if (pid == 0) //child
	{
		close(fd[READ]);
		dup2(open(av[1], O_RDONLY), STDIN);
		dup2(fd[WRITE], STDOUT);
		close(fd[WRITE]);
		run_process(2, av, envp);
	}
	else if (pid2 == 0)
	{
		int status;
		waitpid(pid, &status, -1);
		close(fd[WRITE]);
		dup2(fd[READ], STDIN);
		dup2(open(av[4], O_WRONLY), STDOUT);
		close(fd[READ]);
		run_process(3, av, envp);
	}
	ft_printf("Made it to the end!\n");
	return (0);
}