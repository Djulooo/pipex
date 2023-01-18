/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:01:52 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/13 16:38:59 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char		*s;
	char			*d;
	unsigned int	i;

	s = (char *) src;
	d = (char *) dest;
	i = -1;
	if (dest != 0 || src != 0)
	{
		if (d < s)
		{
			while (++i < n)
				d[i] = s[i];
		}
		else
		{
			while (0 < n)
			{
				d[n - 1] = s[n - 1];
				n--;
			}
		}
	}
	return (dest);
}
