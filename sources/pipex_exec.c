/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:15:40 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/24 18:12:06 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(char **env, char **cmd, char *envp[])
{
	int		i;
	char	*exe;

	i = 0;
	while (env[i])
	{
		exe = ft_strjoin(env[i], cmd[0]);
		if (execve(exe, cmd, envp) == -1)
			perror("Error");
		free(exe);
		i++;
	}
	free_tab(env);
	free_tab(cmd);
	free_tab(envp);
	exit (EXIT_FAILURE);
}

void	pipex(int fd1, int fd2, char **env_cmd, char *envp[])
{
	int		file[2];
	int		parent;
	char	**cmd;

	pipe(file);
	parent = fork();
	if (parent == -1)
		return (perror("Fork: "));
	if (parent == 0)
	{
		child_proc();
	}
	else
	{
		parent_proc();
	}
}
