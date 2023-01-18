/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:49 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/16 16:03:17 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 != 0 && s2 != 0)
	{
		s3 = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!s3)
			return (NULL);
		while (s1[++i])
			s3[i] = s1[i];
		while (s2[j])
		{
			s3[i] = s2[j];
			i++;
			j++;
		}
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}
