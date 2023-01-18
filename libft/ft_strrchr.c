/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:54:22 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/14 10:22:04 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	if (s != 0)
	{
		i = ft_strlen(s) - 1;
		while (i >= 0)
		{
			if (s[i] == b)
				return ((char *)&s[i]);
			i--;
		}
	}
	if (b == '\0')
		return ((char *)&s[ft_strlen(s)]);
	else
		return (NULL);
}
