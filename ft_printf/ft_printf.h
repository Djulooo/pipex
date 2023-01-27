/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:28:39 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/27 13:39:01 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_convert_char(va_list args, int *count);
void	ft_convert_str(va_list args, int *count);
void	ft_convert_hex_pointer(va_list args, int *count);
void	ft_convert_dec_int(va_list args, int *count);
void	ft_convert_integer_dec(va_list args, int *count);
void	ft_convert_uns_int(va_list args, int *count);
void	ft_convert_hex_small(va_list args, int *count);
void	ft_convert_hex_caps(va_list args, int *count);

#endif