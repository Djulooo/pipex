/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:08:21 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/27 13:39:29 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_which_convers(char conv, va_list args, int *count)
{
	if (conv == 'c')
		ft_convert_char(args, count);
	else if (conv == 's')
		ft_convert_str(args, count);
	else if (conv == 'p')
		ft_convert_hex_pointer(args, count);
	else if (conv == 'd')
		ft_convert_dec_int(args, count);
	else if (conv == 'i')
		ft_convert_integer_dec(args, count);
	else if (conv == 'u')
		ft_convert_uns_int(args, count);
	else if (conv == 'x')
		ft_convert_hex_small(args, count);
	else if (conv == 'X')
		ft_convert_hex_caps(args, count);
	else
	{
		ft_putchar_fd(conv, 2);
		*count += 1;
	}
}

static void	write_nonflags(char *str, int *count, int *i)
{
	if ((str[(*i)] == '%' && str[(*i + 1)] == '\0'))
	{
		*count -= 1;
		(*i)++;
	}
	else
	{
		ft_putchar_fd(str[(*i)], 2);
		(*i)++;
	}
}

static int	ft_printf_str(char *str, va_list args)
{
	int	i;
	int	count;
	int	y;

	i = 0;
	count = 0;
	y = write(1, 0, 0);
	if (y < 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_which_convers(str[i + 1], args, &count);
			i += 2;
			count -= 2;
		}
		else
			write_nonflags(str, &count, &i);
	}
	return (count += i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		x;

	va_start(args, str);
	x = ft_printf_str((char *)str, args);
	va_end(args);
	return (x);
}
