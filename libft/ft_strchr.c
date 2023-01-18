/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:29:27 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/09 09:53:12 by jlaisne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			b;
	char			*str;

	i = 0;
	b = c;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == b)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && b == '\0')
		return (&str[i]);
	else
		return (NULL);
}
