/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_args_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:12:47 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/27 13:41:30 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	unsigned int	i;

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

static void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	div;

	fd = 2;
	div = 1;
	while (n / div >= 10)
		div *= 10;
	while (div != 0)
	{
		ft_putchar_fd((n / div % 10 + '0'), fd);
		div = div / 10;
	}
}

void	ft_convert_uns_int(va_list args, int *count)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	ft_putnbr_unsigned_fd(i, 2);
	*count += ft_numlen(i);
}
