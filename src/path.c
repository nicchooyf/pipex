/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:13:01 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/12 21:23:34 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *	Function to get the "PATH=" line from envp
 */
char **get_envp_path(char **envp)
{
	char *envp_path;
	int i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	envp_path = ft_substr(envp[i], 6, ft_strlen(envp[i]) - 6);
	if (!envp_path)
		return (NULL);
	return (get_paths(envp_path));
}

/*
 *	Splits the "PATH=" line into individual
 *	strings of PATH names, ending with "/"
 */
char **get_paths(char *envp_path)
{
	char **paths;
	int	i;

	i = -1;
	paths = ft_split(envp_path, ':');
	if (!paths)
		return (NULL);
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	free(envp_path);
	return (paths);
}

/*
 *	Runs through each PATH to find the correct
 *	one
 */
char *get_right_path(char **envp, char *cmd)
{
	char **paths;
	char *cmd_path;
	int	i;

	i = -1;
	paths = get_envp_path(envp);
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}
