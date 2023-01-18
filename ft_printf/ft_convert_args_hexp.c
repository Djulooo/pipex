/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_args_hexp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:52:04 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/07 11:45:58 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned_hex_fd(unsigned long int n, char *base)
{
	unsigned long int	div;
	unsigned long int	value;
	int					x;

	div = 1;
	value = 0;
	x = 0;
	while (n / div >= 16)
		div *= 16;
	while (div != 0)
	{
		value = (n / div) % 16;
		ft_putchar_fd(base[value], 1);
		x++;
		div = div / 16;
	}
	return (x);
}

void	ft_convert_hex_pointer(va_list args, int *count)
{
	long int	temp;

	temp = va_arg(args, long);
	if (temp == 0)
	{
		ft_putstr_fd("0x0", 1);
		*count += 3;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		*count += ft_putnbr_unsigned_hex_fd(temp, "0123456789abcdef") + 2;
	}
}
