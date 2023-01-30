/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:15:40 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/30 15:56:32 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char *envp[])
{
	char	*path;
	char	**tab;
	int		i;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		if (path)
		{
			path = ft_strdup(ft_strnstr_path(envp[i], \
				"PATH=", ft_strlen(envp[i])));
			break ;
		}
		free(path);
		i++;
	}
	tab = ft_split(path, ':');
	free(path);
	if (!tab)
		display_error("Error in malloc");
	join_slash(tab);
	return (tab);
}

static void	check_cmd(char **cmd, char **envp)
{
	if (access(cmd[0], X_OK) != -1)
		execve(cmd[0], cmd, envp);
	if (cmd[0] == '\0')
	{
		ft_printf("zsh: permission denied: %s\n", cmd[0]);
		exit(1);
	}	
	if (cmd[0][0] == '.' && cmd[0][1] == '/' && access(cmd[0], X_OK) == -1)
	{
		ft_printf("No such file or directory: %s\n", cmd[0]);
		exit(1);
	}	
}

void	exec_command(char **env, char **cmd, char *envp[])
{
	int		i;
	char	*exe;

	i = 0;
	check_cmd(cmd, envp);
	while (env[i])
	{
		exe = ft_strjoin(env[i], cmd[0]);
		if (!exe)
			display_error("execution line not properly allocated");
		if (access(exe, X_OK) == -1)
		{
			if (!env[i + 1])
			{
				ft_printf("Command not found: %s\n", cmd[0]);
				exit(1);
			}
			i++;
		}
		else
			execve(exe, cmd, envp);
	}
}
