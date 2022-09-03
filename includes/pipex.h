/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:23 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/03 15:29:46 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "../libft/includes/libft.h"

# define READ 0
# define WRITE 1
# define STDIN 0
# define STDOUT 1

char **get_envp_path(char **envp);
char **get_paths(char *envp_path);
char *get_right_path(char **envp, char *cmd);

void	run_process(int i, char **av, char **env);

#endif