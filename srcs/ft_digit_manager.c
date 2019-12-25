/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:35:18 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/25 16:25:16 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>


char		*ft_zero_padding(t_format *format, char *str_buffer, int nb)
{
	char		*padded_ret;	
	int			len;
	int			offset;
	int			precision;

	len = ft_strlen(str_buffer);
	precision = format->pre;
	offset = 0;
	if (nb < 0 || ft_str_set(format->flag, "+ 0") != 0) 
	{
	printf("PADDED RETURN = |%s|", str_buffer);
		if (nb < 0 && precision > len)
			str_buffer[0] = '0';
		len += 1;
		precision += 2;
		offset = 1;
	}
	printf("PADDED RETURN = |%s|", str_buffer);
	if (ft_str_set(format->flag, "0") != 0)
		precision = format->min_w;	
	padded_ret = (char *)ft_calloc(len + precision + offset, sizeof(char));
	if (nb < 0 && precision > len)
		ft_memset(padded_ret, '-', 1);
	else if (nb >= 0 && ft_str_set(format->flag, "+") != 0)
		ft_memset(padded_ret, '+', 1);
	else if (nb >= 0 && ft_str_set(format->flag, " ") != 0)
		ft_memset(padded_ret, ' ', 1);
	else
		offset = 0;	
	if (precision > len)
	{
		ft_memset(padded_ret + offset, '0', precision - len + offset);
		ft_strlcpy(padded_ret + (precision - len), str_buffer, len + 1);
	}
	else
		ft_strlcpy(padded_ret + offset, str_buffer, len + 1);
	printf("PADDED RETURN = |%s|", padded_ret);
	free(str_buffer);
	return (padded_ret);
}

int		ft_putnum(t_format *format, char *padded_buff, char *output_str)
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
	if (nb == 0 && format->pre == 0 && output_len > len)
		ft_memset(output_str, ' ', output_len);
	else if (nb == 0 && format->min_w == -1 && format->pre == 0)
	{	
		ft_memset(output_str + offset, '\0', 1);
		output_len = offset;
	}
	ft_putstr(output_str);
	free(output_str);
	free(padded_buff);
	return (output_len);
}

int		ft_printer_nbr(t_format *format, char *str_buffer)
{
	size_t		len;
	size_t		output_len;
	char		*padded_buff;
	char		*output_str;

	if (str_buffer == NULL)
		return (0);
	padded_buff = ft_zero_padding(format, str_buffer, ft_atoi(str_buffer));
	if (padded_buff == NULL)
		return (0);	
	len = ft_strlen(padded_buff);
	output_len = len;
	if (format->min_w > (int)len)
		output_len = format->min_w;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	ft_memset(output_str, ' ', output_len);
	if (ft_str_set(format->flag, "0") != 0)
		ft_memset(output_str, '0', output_len);
	if (ft_str_set(format->flag, "-") != 0 && output_str != NULL)
	{
		ft_strlcpy(output_str, padded_buff, len + 1);
		ft_memset(output_str + len, ' ', output_len - len);
	}	
	else if (output_str != NULL)
		ft_strlcpy(output_str + output_len - len, padded_buff, output_len + 1);
	return (ft_putnum(format, padded_buff, output_str));	
}

int		ft_num_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*str_buffer;
	int			int_buffer;

	ret = 0;
	int_buffer = va_arg(ap, int);
	if (format->conv == 'u' && int_buffer < 0)
		int_buffer = int_buffer * -1;
	str_buffer = ft_itoa(int_buffer);
	ret = ft_printer_nbr(format, str_buffer);
	return (ret);
}

