/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:11 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/13 19:41:18 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	if (ac != 5)
		ft_putstr_fd("Needs exactly five arguments\n", 2);
	else
	{
		data = init_data(ac);
		do_pipex(data, av, envp);
		free(data);
	}
}
