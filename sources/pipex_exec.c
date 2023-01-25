/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:15:40 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/25 17:26:03 by jlaisne          ###   ########.fr       */
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
