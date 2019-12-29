/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:35:18 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/28 13:21:47 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static char	*ft_zero_padding(char *buffer, int pre);

static char	*ft_pre_padding(t_format *format, char *buffer)
{
	int			precision;

	precision = 0;
	if (ft_str_set(format->flag, "0") != 0 &&
format->pre == -1 && ft_str_set(format->flag, "-") == 0)
		precision = format->min_w;
	else if (format->pre != -1)
		precision = format->pre;
	return (ft_zero_padding(buffer, precision));
}

static void	ft_padder(int pre, int len, char *padded_ret, char *buffer)
{ 
	if (pre > len)
	{
		ft_memset(padded_ret, '0', pre - len);
		ft_strlcpy(padded_ret + (pre - len), buffer, len + 1);
	}
	else
		ft_strlcpy(padded_ret, buffer, len + 1);
}

static char	*ft_zero_padding(char *buffer, int pre)
{
	char		*padded_ret;
	int			len;

	len = ft_strlen(buffer);
	padded_ret = (char *)ft_calloc(len + pre + 1, sizeof(char));
	ft_padder(pre, len, padded_ret, buffer);
	free(buffer);
	return (padded_ret);
}

static int		ft_printer_nbr(t_format *format, char *padded_buff, int nb)
{
	size_t		len;
	size_t		output_len;
	char		*output_str;

	len = ft_strlen(padded_buff);
	output_len = len;
	if (format->min_w > (int)len)
		output_len = format->min_w;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	ft_memset(output_str, ' ', output_len);
	if (ft_str_set(format->flag, "0") != 0 && nb < 0)
		ft_memset(output_str , '0', output_len);
	if (ft_str_set(format->flag, "-") != 0 && output_str != NULL)
	{
		ft_strlcpy(output_str, padded_buff, len + 1);
		ft_memset(output_str + len, ' ', output_len - len);
	}	
	else if (output_str != NULL)
		ft_strlcpy(output_str + output_len - len, padded_buff, output_len + 1);
	return (ft_printer_str(format, padded_buff));	
}

static char	*ft_conv(unsigned int nb)
{
	int				i;
	unsigned int	ret;
	char			*ret_str;

	i = 0;
	ret = nb;
	ret_str = (char *)ft_calloc(11, sizeof(char));
	ft_strlcpy(ret_str, ft_itoa(nb/10), 11);
	i = ft_strlen(ret_str);
	ret_str[i] = nb % 10 + 48;
	return (ret_str);
}

int		ft_unsigned_conv(va_list ap, t_format *format)
{
	int				ret;
	char			*buffer;
	int				nb;

	buffer = NULL;
	ret = 0;
	nb = va_arg(ap, int);
	if (nb != 0 && format->pre == 0)
		format->pre = -1;
	if (nb < 0)
	{
		buffer = ft_conv(nb);
		buffer = ft_pre_padding(format, buffer);
		format->pre = -1;
		if (buffer != NULL)
			ret = ft_printer_str(format, buffer);
	}
	else
		buffer = ft_itoa(nb);
	if (format->pre <= (int)ft_strlen(buffer) && nb != 0)
		format->pre = -1;
	if (buffer != NULL && nb == 0 && format->min_w == -1)
	{
		buffer[0] = '0';
		buffer = ft_pre_padding(format, buffer);
		ret = ft_printer_str(format, buffer);
		return (ret);	
	}
	if (buffer != NULL && nb >= 0)
		buffer = ft_pre_padding(format, buffer);
	if (buffer != NULL && nb >= 0)
		ret = ft_printer_nbr(format, buffer, nb);
	return (ret);
}

