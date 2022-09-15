/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:02:53 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/15 15:07:48 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *	Force exits and prints the error
 *	associated with the errno
 */
void	exit_error(char *error)
{
	perror(error);
	exit(1);
}

/*
 *	Mimicks bash's here_doc
 */
void	print_here_doc(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->n_commands - 1)
		ft_printf("pipe ");
	ft_printf("heredoc> ");
}
