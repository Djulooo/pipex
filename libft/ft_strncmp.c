/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:48:45 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/13 17:00:15 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (n);
	while ((s1[i] == s2[i]) && s1[i] && (i < n - 1))
		i++;
	if (s1[i] >= 0 && s2[i] >= 0)
		return ((s1[i] - s2[i]));
	else
		return ((-1 * (s1[i] - s2[i])));
}
