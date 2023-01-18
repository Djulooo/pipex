/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:40:12 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/16 10:20:45 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned int	i;
	char			b;

	i = 0;
	b = c;
	str = (void *)s;
	while (i < n)
	{
		if (str[i] == b)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
