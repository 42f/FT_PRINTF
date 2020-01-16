/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:35:18 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 08:01:52 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>


static char	*ft_zero_padding(t_format *format, char *buffer)
{
	char		*padded_ret;
	size_t		buffer_len;
	size_t		padded_len;

	buffer_len = ft_strlen(buffer);
	padded_len = buffer_len;
	if (format->pre > (int)buffer_len)
		padded_len = format->pre;
	padded_ret = (char *)ft_calloc(padded_len + 1, sizeof(char));
	if (padded_ret == NULL)
		return (NULL);
	if (format->pre > (int)buffer_len)
	{
		ft_memset(padded_ret, '0', padded_len);
		ft_memcpy(padded_ret + (padded_len - buffer_len), buffer, buffer_len);
	}
	else
		ft_memcpy(padded_ret, buffer, buffer_len);
	free(buffer);
	return (padded_ret);
}

static int		ft_printer_nbr(t_format *format, char *padded_buff)
{
	size_t		buff_len;
	size_t		output_len;
	char		*output_str;
	char		c_fill;

	buff_len = ft_strlen(padded_buff);
	output_len = buff_len;
	if (format->min_w > (int)buff_len)
		output_len = format->min_w;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	if (output_str == NULL)
		return (-1);
	c_fill = ' ';
	if (ft_str_set(format->flag, "0") != 0)
		c_fill = '0';
	if (format->pre != -1 && format->pre < format->min_w)
		c_fill = ' ';
	ft_memset(output_str, c_fill, output_len);
	if (ft_str_set(format->flag, "-") != 0)
		ft_memcpy(output_str, padded_buff, buff_len);
	else
		ft_memcpy(output_str + (output_len - buff_len), padded_buff, buff_len);
	ft_putstr(output_str);
	free(output_str);
	return (output_len);
}

int		ft_unsigned_conv(va_list ap, t_format *format)
{
	int				ret;
	char			*buffer;
	unsigned long long int	nb;

	buffer = NULL;
	ret = 0;
	if (ft_str_set(format->spec, "lzj") != 0)
		nb = va_arg(ap, unsigned long long int);
	else if (ft_strncmp(format->spec, "hh", 2) == 0)
		nb = (unsigned char)va_arg(ap, int);
	else if (ft_strncmp(format->spec, "h", 1) == 0)
		nb = (unsigned short)va_arg(ap, int);
	else
		nb = va_arg(ap, unsigned int);
	buffer = ft_itoa_ulong(nb);
	if (buffer == NULL)
		return (-1);
	if (nb == 0 && format->pre == 0)
		buffer[0] = '\0';
	buffer = ft_zero_padding(format, buffer);
	if (buffer == NULL)
		return (-1);
	ret = ft_printer_nbr(format, buffer);
	free(buffer);
	return (ret);
}

