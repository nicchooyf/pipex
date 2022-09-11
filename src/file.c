/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:41:41 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/11 18:51:22 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int get_fd(int i, int ac, char **av)
{
	int fd;

	if (i == 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = open(av[ac -1], O_CREAT | O_WRONLY | O_TRUNC);
	if (fd == -1)
		exit_error();
	return (fd);
}