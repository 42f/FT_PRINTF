/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:35:18 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/27 20:28:17 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static char	*ft_zero_padding(t_format *format, char *buffer, int nb, int pre);

static char	*ft_pre_padding(t_format *format, char *buffer, int nb)
{
	int			pre;

	pre = 0;
	if (ft_str_set(format->flag, "0") != 0 &&
format->pre == -1 && ft_str_set(format->flag, "-") == 0)
		pre = format->min_w - 1;
	else if (format->pre != -1)
		pre = format->pre;
	return (ft_zero_padding(format, buffer, nb, pre));
}

static void	ft_padder(int pre, int len, int offset, char *padded_ret, char *buffer)
{ 
	if (pre > len)
	{
		ft_memset(padded_ret + offset, '0', pre - len + offset);
		ft_strlcpy(padded_ret + (pre - len), buffer, len + 1);
	}
	else
		ft_strlcpy(padded_ret + offset, buffer, len + 1);
}

static char	*ft_zero_padding(t_format *format, char *buffer, int nb, int pre)
{
	char		*padded_ret;
	int			len;
	int			offset;

	len = ft_strlen(buffer);
	offset = 0;
(void)format;
(void)nb;
	if (nb < 0 || ft_str_set(format->flag, "+ 0") != 0) 
	{
		if (nb < 0 && pre >= len)
			buffer[0] = '0';
		len += 1;
		pre += 2;
		offset = 1;
	}
	padded_ret = (char *)ft_calloc(len + pre + offset + 1, sizeof(char));
/*	if (nb < 0 && pre > len)
		ft_memset(padded_ret, '-', 1);
	else if (nb >= 0 && ft_str_set(format->flag, "+") != 0)
		ft_memset(padded_ret, '+', 1);
	else if (nb >= 0 && ft_str_set(format->flag, " ") != 0)
		ft_memset(padded_ret, ' ', 1);
	else
*/		offset = 0;	
	ft_padder(pre, len, offset, padded_ret, buffer);
	free(buffer);
	return (padded_ret);
}

/*
static int		ft_putnum(t_format *format, char *padded_buff, char *output_str)
{
	size_t		output_len;
	size_t		len;
	int			nb;
	int			offset;

	nb = ft_atoi(padded_buff);
	if (output_str == NULL)
		return (0);
	output_len = ft_strlen(output_str);
	len = ft_strlen(padded_buff);
	offset = 0;
	if (ft_str_set(format->flag, "+ ") != 0)
		offset = 1;
	ft_putstr(output_str);
	free(output_str);
	free(padded_buff);
	return (output_len);
}
*/
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

static char	*ft_conv(long int nb)
{
	int			i;
	long int	ret;
	char		*ret_str;

	i = 0;
	ret = 2;
	while (i < 32 - 1)
	{
		ret = ret * 2;
		i++;
	}
	nb = ret + nb;
	ret_str = (char *)ft_calloc(11, sizeof(char));
	ft_strlcpy(ret_str, ft_itoa(nb/10), 11);
	ret_str[9] = nb % 10 + 48;
	return (ret_str);
}

int		ft_unsigned_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*buffer;
	long int	nb;

	buffer = NULL;
	ret = 0;
	nb = va_arg(ap, int);
	if (nb != 0 && format->pre == 0)
		format->pre = -1;
	if (nb < 0)
	{
		buffer = ft_conv(nb);
		if (format->pre < 10)
			format->pre = -1;
		buffer = ft_pre_padding(format, buffer, nb);
		if (buffer != NULL)
			ret = ft_printer_str(format, buffer);
	}
	else
		buffer = ft_itoa(nb);
	if (buffer != NULL && nb == 0 && format->min_w == -1)
	//if (buffer != NULL && nb == 0 && (format->pre == 0 || format->min_w == -1))
	{
		buffer[0] = '0';
//		format->pre = 0;
		buffer = ft_pre_padding(format, buffer, nb);
		ret = ft_printer_str(format, buffer);
		return (ret);	
//		if (format->pre == -1 && format->min_w == -1)
//			buffer[0] = '0';
	}
	if (buffer != NULL && nb >= 0)
		buffer = ft_pre_padding(format, buffer, nb);
	if (buffer != NULL && nb >= 0)
		ret = ft_printer_nbr(format, buffer, nb);
	return (ret);
}

