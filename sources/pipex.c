/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:09:12 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/27 13:26:00 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_struct(t_pipex *var, char **argv, char **envp)
{	
	var->arg = argv;
	var->fd1 = open(argv[1], O_RDONLY, 0777);
	if (var->fd1 == -1)
		display_error("Error, infile doesn't exist");
	var->fd2 = open(var->arg[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var->fd2 == -1)
		display_error("Error, outfile doesn't exist");
	var->env_cmd = get_path(envp);
	if (!var->env_cmd)
		display_error("Error in malloc\n");
	if (pipe(var->file) == -1)
		display_error("Pipe returned an error");
}

static void	child_process(t_pipex *var, char **envp)
{
	char	**cmd;

	close(var->fd2);
	close(var->file[0]);
	if (dup2(var->fd1, STDIN_FILENO) == -1)
		display_error("Error in duplication of fd1 as Stdin\n");
	if (dup2(var->file[1], STDOUT_FILENO) == -1)
		display_error("Error in duplication of file[1] as Stdout\n");
	cmd = get_command(var->arg[2]);
	if (!cmd)
		display_error("Command tab not properly allocated");
	exec_command(var->env_cmd, cmd, envp);
	exit(0);
}

static void	child_bis_process(t_pipex *var, char **envp)
{
	char	**cmd;

	close(var->fd1);
	close(var->file[1]);
	if (dup2(var->file[0], STDIN_FILENO) == -1)
		display_error("Error in duplication of file[0] as Stdin");
	if (dup2(var->fd2, STDOUT_FILENO) == -1)
		display_error("Error in duplication of fd2 as Stdout");
	cmd = get_command(var->arg[3]);
	if (!cmd)
		display_error("Command tab not properly allocated");
	exec_command(var->env_cmd, cmd, envp);
	exit(0);
}

static void	close_pipe(t_pipex *var)
{
	close(var->file[0]);
	close(var->file[1]);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
}

int	main(int argc, char **argv, char *envp[])
{
	int		id;
	int		id_2;
	t_pipex	var;

	if (argc == 5)
	{
		init_struct(&var, argv, envp);
		id = fork();
		if (id == -1)
			display_error("Forking unsuccessful");
		if (id == 0)
			child_process(&var, envp);
		id_2 = fork();
		if (id_2 == -1)
			display_error("Forking unsuccessful");
		if (id_2 == 0)
			child_bis_process(&var, envp);
		close_pipe(&var);
		waitpid(id, &var.status, 0);
		waitpid(id_2, &var.status, 0);
	}
	else
		return (ft_putstr_fd("Wrong number of arguments!\n", 2), 3);
	return (free_tab(var.env_cmd), 0);
}
