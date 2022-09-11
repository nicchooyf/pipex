/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:23 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/11 21:49:30 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define STDIN 0
# define STDOUT 1

typedef struct s_data
{
int i;
int ac;
int n_commands;
int hd;
} t_data;

char **get_envp_path(char **envp);
char **get_paths(char *envp_path);
char *get_right_path(char **envp, char *cmd);

void	run_process(int i, char **av, char **env);

t_data	*init_data(int ac);
int **make_pipes(int ac);
void close_pipes(int **fd);
void do_pipex(int ac, char **av, char **env);

void dup_stdin(int i, char **av, int **fd);
void dup_stdout(int i, int ac, char **av, int **fd);
void do_child(t_data *data, char **av, int **fd, char **env);

void exit_error(void);

int get_fd(int i, int ac, char **av);

#endif