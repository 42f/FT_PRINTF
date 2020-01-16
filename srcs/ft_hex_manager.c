/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:46:56 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 13:44:45 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static int	ft_put_hex(t_format *format, char *hex_str, char c_fill)
{
	char	*output_str;
	size_t	out_len;
	size_t	in_len;

	if (hex_str == NULL)
		return (-1);
	in_len = ft_strlen(hex_str);
	out_len = in_len;
	if (format->min_w > (int)in_len)
		out_len = format->min_w;
	output_str = (char *)ft_calloc(out_len + 1, sizeof(char));
	if (output_str == NULL)
		return (-1);
	ft_memset(output_str, c_fill, out_len);
	if (ft_str_set(format->flag, "-") != 0)
		ft_memcpy(output_str, hex_str, in_len);
	else
		ft_memcpy(output_str + (out_len - in_len), hex_str, in_len + 1);
	if (format->conv == 'X')
		ft_str_toupper(output_str);
	ft_putstr(output_str);
	free(output_str);
	return (out_len);
}

static int	ft_p_conv(va_list ap, t_format *format, char *h_base)
{
	int			ret;
	char		*nb_str;
	char		c_fill;

	ret = 0;
	nb_str = ft_itoa_base_ptr(va_arg(ap, uintptr_t), h_base);
	nb_str = ft_p_pre_padding(format, nb_str);
	if (nb_str == NULL)
		return (-1);
	c_fill = ft_set_cfill(format);
	ret = ft_put_hex(format, nb_str, c_fill);
	free(nb_str);
	return (ret);
}

static int	ft_x_conv(va_list ap, t_format *format, char *h_b)
{
	int			ret;
	char		*nb_s;
	char		c_fill;

	ret = 0;
	if (ft_str_set(format->spec, "ljz") != 0)
		nb_s = ft_itoa_base_ptr(va_arg(ap, uintptr_t), h_b);
	else if (ft_strncmp(format->spec, "hh", 2) == 0)
		nb_s = ft_itoa_base_ptr((unsigned char)va_arg(ap, unsigned int), h_b);
	else if (ft_strncmp(format->spec, "h", 1) == 0)
		nb_s = ft_itoa_base_ptr((unsigned short)va_arg(ap, unsigned int), h_b);
	else
		nb_s = ft_itoa_base(va_arg(ap, unsigned int), h_b);
	nb_s = ft_x_pre_padding(format, nb_s);
	if (nb_s == NULL)
		return (-1);
	c_fill = ft_set_cfill(format);
	ret = ft_put_hex(format, nb_s, c_fill);
	free(nb_s);
	return (ret);
}

int			ft_hex_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*h_base;

	h_base = ft_strdup("0123456789abcdef");
	ret = 0;
	if (format->conv == 'p' != 0)
		ret = ft_p_conv(ap, format, h_base);
	else if (format->conv == 'x' != 0 || format->conv == 'X' != 0)
		ret = ft_x_conv(ap, format, h_base);
	free(h_base);
	return (ret);
}
