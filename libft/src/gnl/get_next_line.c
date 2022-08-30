/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:18:26 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/08 15:37:15 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	Function to return the read line, and clears the static variable
 *	up to either the point of '\n' or EOF
 *
 *	When a '\n' is encountered, returns the string up to the '\n' and replaces
 *	the current static variable with what comes after the '\n'
 */
static char	*next_line(char **s)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s)[i] == '\n')
	{
		ret = ft_substr(*s, 0, i + 1);
		tmp = ft_strdup(*s + i + 1);
		free(*s);
		*s = tmp;
		if (!**s)
		{
			free(*s);
			*s = NULL;
		}
		return (ret);
	}
	ret = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (ret);
}

/*
 *	Function to read the file up to either the EOF or '\n'
 */
static void	read_file(int fd, char *buffer, char **s, int n)
{
	char	*tmp;

	while (n > 0)
	{
		buffer[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
}

/*
 *	Static char set as a double array to address multiple FDs
 *
 *	Continuously reads the buffer_size until either a '\n' or EOF
 *	Calls the function to return the read line
 */
char	*get_next_line(int fd)
{
	static char		*s[FD_SIZE];
	char			*buffer;
	ssize_t			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	read_file(fd, buffer, s, n);
	free(buffer);
	if (n < 0)
		return (NULL);
	if (!n && (!s[fd] || !*s[fd]))
		return (NULL);
	return (next_line(&s[fd]));
}
