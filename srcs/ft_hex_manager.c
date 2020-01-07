/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:46:56 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/07 09:31:25 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static char	*ft_zero_padding(t_format *format, char *hex_str)
{
	char		*padded_ret;

	if (format->conv == 'p' || ft_str_set(format->flag, "#") != 0)
		padded_ret = ft_strjoin("0x", hex_str);
	else if (ft_strncmp(hex_str, "0", 2) == 0 && format->pre == 0)
		padded_ret = ft_strdup("");
	else 
		return (hex_str);
	free(hex_str);
	if (padded_ret == NULL)
		return (NULL);
	return (padded_ret);
}

static int	ft_put_hex(t_format *format, char *hex_str)
{
	char	*output_str;
	size_t	output_len;
	size_t	input_len;

	if (hex_str == NULL)
		return (-1);
	input_len = ft_strlen(hex_str);
	output_len = input_len;
	if (format->min_w > (int)input_len)
		output_len = format->min_w;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	if (output_str == NULL)
		return (-1);
	ft_memset(output_str, ' ', output_len);
	if (ft_str_set(format->flag, "-") != 0)
		ft_memcpy(output_str, hex_str, input_len);
	else
		ft_memcpy(output_str + (output_len - input_len), hex_str, input_len + 1);
	ft_putstr(output_str);
	free(output_str);
	return (output_len);
}

static char	*ft_set_base(t_format *format)
{
	if (format->conv < 'a')
		return (ft_strdup("0123456789ABCDEF"));
	else
		return (ft_strdup("0123456789abcdef"));
}

int			ft_hex_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*output_str;
	char		*base;

	ret = 0;
	base = ft_set_base(format);
	if (format->conv == 'p')
		output_str = ft_itoa_base(va_arg(ap, unsigned long long int), base);
	else
		output_str = ft_itoa_base(va_arg(ap, unsigned int), base);
	output_str = ft_zero_padding(format, output_str);
	ret = ft_put_hex(format, output_str);
	free(output_str);
	free(base);
	return (ret);
}

