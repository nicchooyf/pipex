/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:11 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/05 14:19:47 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe *initialize(t_pipe *data, int ac)
{
	data = malloc(sizeof data);
	if (!data)
		exit_error();
	data->ac = ac;
	data->i = 0;
	data->n = -1;
	return (data);	
}

int main(int ac, char **av, char **env)
{
	t_pipe *data;
	
	if (ac >= 5)
	{
		data = initialize(data, ac);
		do_pipex(data, av, env);
	}
}