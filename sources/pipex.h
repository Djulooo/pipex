/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:07:35 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/26 16:23:06 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pipe
{
	char	**env_cmd;
	char	**arg;
	int		fd1;
	int		fd2;
}	t_pipex;

char	*ft_strnstr_path(const char *haystack, const char *needle, size_t len);
void	display_error(char *msg);
void	join_slash(char **env);
void	free_tab(char **tab);

char	**get_command(char *arg);
void	exec_command(char **env, char **cmd, char *envp[]);
char	**get_path(char *envp[]);
#endif