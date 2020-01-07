/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:46:56 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/07 18:52:02 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static char	*ft_padding(t_format *format, char *hex_str, int pre, int offset)
{
	char		*padded_ret;
	size_t		hex_len;
	size_t		padded_len;

	hex_len = ft_strlen(hex_str);
	if (pre < 0)
		pre = 0;
	padded_len = hex_len + offset;
	if (format->pre > (int)hex_len) 
		padded_len = pre + offset;
	else if (ft_str_set(format->flag, "0") != 0 && format->pre != -1)
		padded_len = format->min_w;
	padded_ret = (char *)ft_calloc(padded_len + 1, sizeof(char));
	if (padded_ret == NULL)
		return (NULL);
	ft_memset(padded_ret, ' ', padded_len);
	if (ft_str_set(format->flag, "0") != 0 || format->pre > (int)hex_len)
		ft_memset(padded_ret, '0', padded_len);
	if (offset == 2 && format->conv == 'X')
		ft_memcpy(padded_ret, "0X", 2);
	else if (offset == 2)
		ft_memcpy(padded_ret, "0x", 2);
	ft_memcpy(padded_ret + (padded_len - hex_len), hex_str, hex_len);
	free(hex_str);
	return (padded_ret);
}

static char	*ft_p_pre_padding(t_format *format, char *hex_str)
{
	int			offset;

	offset = 2;
	if (hex_str[0] == '0' && format->pre == 0)
		ft_memset(hex_str, '\0', ft_strlen(hex_str));
	return (ft_padding(format, hex_str, format->pre, offset));
}

static char	*ft_x_pre_padding(t_format *format, char *hex_str)
{
	int			offset;

	offset = 0;
	if (ft_str_set(format->flag, "#") != 0)
		offset = 2;
	if (hex_str[0] == '0')
	{
		if (ft_str_set(format->flag, "#") != 0)
			ft_strlcpy(hex_str, "0", 2);
		if (format->pre == 0)
			ft_memset(hex_str, '\0', ft_strlen(hex_str));
		offset = 0;
	}
	return (ft_padding(format, hex_str, format->pre, offset));
}

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
	ft_putstr(output_str);
	free(output_str);
	return (out_len);
}

static char	*ft_set_base(t_format *format)
{
	if (format->conv < 'a')
		return (ft_strdup("0123456789ABCDEF"));
	else
		return (ft_strdup("0123456789abcdef"));
}

static char	ft_set_cfill(t_format *format)
{
	char	c_fill;
	
	c_fill = ' ';
	if (format->conv == 'p')
		return (c_fill);
	if (ft_str_set(format->flag, "0") != 0)
		c_fill = '0';
	if (ft_str_set(format->flag, "#") != 0)
		c_fill = ' ';
	if (format->pre != -1 && format->pre < format->min_w)
		c_fill = ' ';
	if (ft_str_set(format->flag, "-") != 0)
		c_fill = ' ';
	return (c_fill);
}

int			ft_hex_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*output_str;
	char		*base;
	char		c_fill;

	ret = 0;
	base = ft_set_base(format);
	if (format->conv == 'p' || ft_str_set(format->spec, "lzj") != 0)
		output_str = ft_itoa_base_pointer(va_arg(ap, uintptr_t), base);
	else if (ft_str_set(format->spec, "h") != 0)
	{
		output_str = ft_itoa_base_pointer(va_arg(ap, int), base);
		if (ft_strncmp(format->spec, "hh", 3) == 0 && ft_strlen(output_str) > 2)
			ft_memcpy(output_str, output_str + ft_strlen(output_str) - 2, 3);
		else if (ft_strncmp(format->spec, "h", 2) == 0 && ft_strlen(output_str) > 4)
			ft_memcpy(output_str, output_str + ft_strlen(output_str) - 4, 5);
	}
	else
		output_str = ft_itoa_base(va_arg(ap, unsigned int), base);
	if (format->conv == 'p')
		output_str = ft_p_pre_padding(format, output_str);
	else
		output_str = ft_x_pre_padding(format, output_str);
	c_fill = ft_set_cfill(format);
	ret = ft_put_hex(format, output_str, c_fill);
	free(output_str);
	free(base);
	return (ret);
}

