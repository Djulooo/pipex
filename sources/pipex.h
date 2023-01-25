/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:07:35 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/25 16:58:15 by jlaisne          ###   ########.fr       */
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

char	*ft_strnstr_path(const char *haystack, const char *needle, size_t len);
void	display_error(char *msg);
void	join_slash(char **env);
void	free_tab(char **tab);

char	**get_command(char *arg);
void	exec_command(char **env, char **cmd, char *envp[]);

#endif