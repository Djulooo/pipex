/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex_heX.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:00:02 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/27 13:39:36 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex_fd(unsigned int n, char *base)
{
	unsigned int	div;
	unsigned int	baselen;
	unsigned int	value;
	unsigned int	i;

	div = 1;
	baselen = ft_strlen(base);
	value = 0;
	i = 0;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', 2);
	}
	while (n / div >= baselen)
		div *= baselen;
	while (div != 0)
	{
		value = (n / div) % baselen;
		ft_putchar_fd(base[value], 2);
		i++;
		div = div / baselen;
	}
	return (i);
}

void	ft_convert_hex_small(va_list args, int *count)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	*count += ft_putnbr_hex_fd(i, "0123456789abcdef");
}

void	ft_convert_hex_caps(va_list args, int *count)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	*count += ft_putnbr_hex_fd(i, "0123456789ABCDEF");
}
