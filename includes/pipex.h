/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:23 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/05 14:03:55 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "../libft/includes/libft.h"

# define STDIN 0
# define STDOUT 1

typedef struct s_pipe
{
	int		i;
	int		n;
	int		ac;
} t_pipe;

char **get_envp_path(char **envp);
char **get_paths(char *envp_path);
char *get_right_path(char **envp, char *cmd);

void	run_process(int i, char **av, char **env);

void exit_error(void);

#endif