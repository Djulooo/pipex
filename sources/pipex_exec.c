/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:15:40 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/26 14:06:09 by jlaisne          ###   ########.fr       */
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
		display_error("Error in malloc\n");
	join_slash(tab);
	return (tab);
}

void	exec_command(char **env, char **cmd, char *envp[])
{
	int		i;
	char	*exe;

	i = 0;
	while (env[i])
	{
		exe = ft_strjoin(env[i], cmd[0]);
		if (access(exe, 0) == -1)
		{
			if (!env[i + 1])
				display_error(ft_strjoin("command not found: ", cmd[0]));
			i++;
		}
		else
		{
			execve(exe, cmd, envp);
			free(exe);
			i++;
		}
	}
}
