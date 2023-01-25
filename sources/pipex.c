/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:09:12 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/25 17:40:12 by jlaisne          ###   ########.fr       */
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
			path = ft_strdup(ft_strnstr_path(envp[i], "PATH=", ft_strlen(envp[i])));
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

int	main(int argc, char **argv, char *envp[])
{
	int		file[2];
	int		id;
	char	**cmd;
	char	**env_cmd;
	int		fd1;
	int		fd2;
	int status;
	
	id = fork();
	pipe(file);
	if (argc == 5)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[4], O_WRONLY);
		env_cmd = get_path(envp);
		if (id == 0)
		{
			cmd = get_command(argv[2]);
			close(file[0]);
			dup2(fd1, STDIN_FILENO);
			dup2(file[1], STDOUT_FILENO);
			close(fd1);
			exec_command(env_cmd, cmd, envp);
			close(file[1]);
			close(fd2);
		}
		else
		{
			waitpid(-1, &status, 0);
			close(file[1]);
			dup2(file[0], STDIN_FILENO);
			dup2(fd2, STDOUT_FILENO);
			close(fd2);
			cmd = get_command(argv[3]);
			exec_command(env_cmd, cmd, envp);
			close(file[0]);
			close(fd1);
		}
	}
	else
		return (ft_putstr_fd("Wrong number of arguments!\n", 2), 3);
	return (free_tab(env_cmd), 0);
}
