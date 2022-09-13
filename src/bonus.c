/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:24:34 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/13 21:22:55 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	if (ac < 5)
		ft_putstr_fd("Needs five or more arguments\n", 2);
	else
	{
		data = init_data(ac);
		here_doc(data, av);
		do_pipex(data, av, envp);
		free(data);
	}
}
