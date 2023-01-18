/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:42:52 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/16 16:01:43 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimright(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j] && i >= 0)
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static unsigned int	ft_trimleft(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	result;

	i = ft_strlen(s1) - 1;
	j = 0;
	result = 0;
	while (s1[i] && set[j] && i >= 0)
	{
		if (s1[i] == set[j])
		{
			result++;
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (result);
}

static void	*ft_memcpy2(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*s;
	char			*d;

	i = 0;
	s = (char *) src;
	d = (char *) dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	tright;
	unsigned int	tleft;
	char			*str;

	if (s1 == 0)
		return (NULL);
	tright = ft_trimright(s1, set);
	if (tright != ft_strlen(s1))
	{
		tleft = ft_trimleft(s1, set);
		str = malloc((sizeof(char) * (ft_strlen(s1) - (tright + tleft) + 1)));
		if (!str)
			return (NULL);
		str = ft_memcpy2(str, s1 + tright, ft_strlen(s1) - (tright + tleft));
		str[ft_strlen(s1) - (tright + tleft)] = '\0';
		return (str);
	}
	else
	{
		str = malloc((sizeof(char) * 1));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
}
