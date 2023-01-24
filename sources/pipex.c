/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:09:12 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/24 17:29:41 by jlaisne          ###   ########.fr       */
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
		display_error();
	join_slash(tab);
	return (tab);
}

int	main(int argc, char **argv, char *envp[])
{
	int		fd1;
	int		fd2;
	char	**env_cmd;
	
	if (argc == 5)
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
			return (ft_putstr_fd("Error fd 1.\n", 2), 1);
		fd2 = open(argv[4], O_WRONLY);
		if (fd2 == -1)
			return (ft_putstr_fd("Error fd 2.\n", 2), 2);
		env_cmd = get_path(envp);
		pipex(fd1, fd2, env_cmd, envp);
	}
	else
		return (ft_putstr_fd("Wrong number of arguments!\n", 2), 3);
	return (free_tab(env_cmd), 0);
}
