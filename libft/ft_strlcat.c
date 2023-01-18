/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:09:34 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/16 10:21:29 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	j;

	if (dest == NULL && dsize == 0)
		return (0);
	j = 0;
	i = ft_strlen(dest);
	x = i + ft_strlen(src);
	if (dsize <= 0)
		return (ft_strlen(src));
	if (i > dsize)
		return (dsize + ft_strlen(src));
	while (src[j] && i < dsize - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (x);
}
