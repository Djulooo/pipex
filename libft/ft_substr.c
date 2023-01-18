/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:58:33 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/21 10:50:01 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*src;
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = start;
	src = (char *)s;
	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	if (len > ft_strlen(s) || start >= ft_strlen(src) || s == 0 || len <= 0)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (j < start + len && src[i])
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
