/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:11 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/11 21:46:13 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	if (ac < 5)
		ft_putstr_fd("Not enough arguments given\n", 2);
	else
		do_pipex(ac, av, env);
	// system("leaks pipex");
}