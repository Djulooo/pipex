/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:44:27 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/07 11:45:53 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_convert_char(va_list args, int *count)
{
	char	c;

	c = va_arg(args, int);
	*count += 1;
	ft_putchar_fd(c, 1);
}

void	ft_convert_str(va_list args, int *count)
{
	char	*str;
	size_t	len;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		*count += 6;
		ft_putstr_fd("(null)", 1);
		return ;
	}
	else
	{
		len = ft_strlen(str);
		*count += len;
		ft_putstr_fd(str, 1);
	}
}

void	ft_convert_integer_dec(va_list args, int *count)
{
	int	i;

	i = va_arg(args, int);
	ft_putnbr_fd(i, 1);
	if (i < 0)
		*count += ft_numlen(i) + 1;
	else
		*count += ft_numlen(i);
}

void	ft_convert_dec_int(va_list args, int *count)
{
	int	i;

	i = va_arg(args, int);
	ft_putnbr_fd(i, 1);
	if (i < 0)
		*count += ft_numlen(i) + 1;
	else
		*count += ft_numlen(i);
}
