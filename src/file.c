/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:41:41 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/13 18:19:46 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *	Returns the file descriptor of the in- and outfiles
 *	while checking for valid access permissions
 *
 *	If here_doc is encountered, sets the outfile to APPEND.
 *	Otherwise, sets it to TRUNCATE.
 */
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

/*
 *	Reads from stdin using get_next_line and
 *	writes to the temporary file
 */
void	write_here_doc(t_data *data, int file, char *limiter)
{
	char	*text;
	int		i;

	i = 0;
	while (++i < data->n_commands - 1)
		write(1, "pipe ", 5);
	write(1, "heredoc> ", 9);
	text = get_next_line(0);
	while (text)
	{
		i = 0;
		if (ft_strncmp(text, limiter, ft_strlen(text) - 1) == 0)
		{
			free(text);
			return ;
		}
		write(file, text, ft_strlen(text));
		free(text);
		while (++i < data->n_commands - 1)
			write(1, "pipe ", 5);
		write(1, "heredoc> ", 9);
		text = get_next_line(0);
	}
}

/*
 *	Creates a temporary file to store what's 
 *	read from the stdin
 *
 *	Then, passes on the fd of the temporary file
 *	as the infile for later dup2 functions
 */
void	here_doc(t_data *data, char **av)
{
	int	file;

	if (ft_strncmp("here_doc", av[1], 9) != 0)
	{
		if (open(av[1], O_RDONLY) == -1)
			exit_error("infile");
		return ;
	}
	data->i++;
	file = open("here_doc.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	write_here_doc(data, file, av[2]);
	close(file);
	data->hd = open("here_doc.txt", O_RDONLY);
}
