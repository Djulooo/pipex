/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:53:29 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/15 10:00:58 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;
	int	div;

	i = 1;
	div = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_negstr(int ind, long n, char *s)
{
	s[ind--] = '\0';
	while (ind > 0)
	{
		s[ind--] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}

static char	*ft_posstr(int ind, long n, char *s)
{
	s[ind--] = '\0';
	while (ind >= 0)
	{
		s[ind--] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		x;
	char	*str;
	long	i;

	i = n;
	if (i < 0)
	{
		x = ft_numlen(i) + sizeof(char) * 2;
		str = malloc(sizeof(char) * x);
		if (!str)
			return (NULL);
		str[0] = '-';
		i *= -1;
		str = ft_negstr(x - 1, i, str);
	}
	else
	{
		x = ft_numlen(i) + sizeof(char) * 1;
		str = malloc(sizeof(char) * x);
		if (!str)
			return (NULL);
		str = ft_posstr(x - 1, i, str);
	}
	return (str);
}
