/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:41:41 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/12 16:24:58 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(t_data *data, char **av)
{
	int	fd;

	if (data->i == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit_error(av[1]);
	}
	else
	{
		if (data->hd > 0)
			fd = open(av[data->ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			fd = open(av[data->ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			exit_error(av[data->ac - 1]);
	}
	return (fd);
}

void	write_here_doc(int file, char *limiter)
{
	char	*text;

	text = get_next_line(0);
	while (text)
	{
		if (ft_strncmp(text, limiter, ft_strlen(text) - 1) == 0)
		{
			free(text);
			return ;
		}
		write(file, text, ft_strlen(text));
		free(text);
		text = get_next_line(0);
	}
}

void	here_doc(t_data *data, char **av)
{
	int	file;

	if (ft_strncmp("here_doc", av[1], 8) != 0)
		return ;
	file = open("here_doc.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	write_here_doc(file, av[2]);
	close(file);
	data->hd = open("here_doc.txt", O_RDONLY);
}
