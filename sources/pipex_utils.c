/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:43:19 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/25 16:57:21 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr_path(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	if (len == 0 && haystack == NULL)
		return (NULL);
	while (haystack[i] != '\0' && i <= len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && (haystack[i + j] == needle[j])
				&& ((i + j) < len))
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i + j]);
		}
		i++;
	}
	return (NULL);
}

void	join_slash(char **env)
{
	int	i;
	char	*temp;

	i = 0;
	while (env[i])
	{
		temp = ft_strdup(env[i]);
		free(env[i]);
		env[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
}

char	**get_command(char *arg)
{
	char	**cmd;

	cmd = ft_split(arg, ' ');
	if (!cmd)
		display_error("Error in malloc\n");
	return (cmd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	display_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit (EXIT_FAILURE);
}
