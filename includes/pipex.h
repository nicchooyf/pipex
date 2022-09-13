/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:23 by nchoo             #+#    #+#             */
/*   Updated: 2022/09/12 21:25:57 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
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

t_data	*init_data(int ac);
int **make_pipes(int ac);
void close_pipes(int **fd);
void do_pipex(t_data *data, char **av, char **env);

void dup_stdin(t_data *data, char **av, int **fd);
void dup_stdout(t_data *data, char **av, int **fd);
void	run_process(int i, char **av, char **env);
void do_child(t_data *data, char **av, int **fd, char **env);

void exit_error(char *error);

int get_fd(t_data *data, char **av);
void write_here_doc(int file, char *limiter);
void here_doc(t_data *data, char **av);

#endif