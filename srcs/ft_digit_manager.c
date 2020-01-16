/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:35:18 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 14:01:05 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static void		ft_prefix(t_format *format, char *ret, char *buff, long long nb)
{
	size_t		ret_len;
	size_t		buff_len;

	ret_len = ft_strlen(ret);
	buff_len = ft_strlen(buff);
	if (nb < 0)
		ft_memset(ret, '-', 1);
	else if (nb >= 0 && ft_str_set(format->flag, "+") != 0)
		ft_memset(ret, '+', 1);
	else if (nb >= 0 && ft_str_set(format->flag, " ") != 0)
		ft_memset(ret, ' ', 1);
	ft_memcpy(ret + (ret_len - buff_len), buff, buff_len);
}

static size_t	ft_ret_len(t_format *format, int buffer_len)
{
	size_t		ret_len;

	ret_len = buffer_len;
	if (format->pre > buffer_len)
		ret_len = format->pre;
	else if (format->pre != -1 && format->pre <= buffer_len)
		ret_len = buffer_len;
	else if (ft_str_set(format->flag, "0") != 0
	&& format->min_w > buffer_len && ft_str_set(format->flag, "-") == 0)
		ret_len = format->min_w;
	return (ret_len);
}

static char		*ft_pad_buffer(t_format *format, char *buffer, long long nb)
{
	char		*ret;
	size_t		ret_len;
	int			buffer_len;

	buffer_len = ft_strlen(buffer);
	if (nb < 0 || ft_str_set(format->flag, "+ ") != 0)
	{
		if (nb < 0)
			ft_memmove(buffer, buffer + 1, buffer_len);
		if (nb >= 0)
			buffer_len++;
		if (format->pre != -1)
			format->pre++;
	}
	ret_len = ft_ret_len(format, buffer_len);
	ret = (char *)ft_calloc(ret_len + 1, sizeof(char));
	if (ret == NULL)
	{
		free(buffer);
		return (NULL);
	}
	ft_memset(ret, '0', ret_len);
	ft_prefix(format, ret, buffer, nb);
	free(buffer);
	return (ret);
}

static char		*ft_zero_padding(t_format *format, char *buffer, long long nb)
{
	char			*padded_ret;
	size_t			buff_len;
	size_t			padd_len;

	buffer = ft_pad_buffer(format, buffer, nb);
	if (buffer == NULL)
		return (NULL);
	buff_len = ft_strlen(buffer);
	padd_len = buff_len;
	if (format->min_w > (int)buff_len)
		padd_len = format->min_w;
	padded_ret = (char *)ft_calloc(padd_len + 1, sizeof(char));
	if (padded_ret == NULL || buffer == NULL)
		return (NULL);
	ft_memset(padded_ret, ' ', padd_len);
	if (ft_str_set(format->flag, "-") != 0)
		ft_memcpy(padded_ret, buffer, buff_len);
	else
		ft_memcpy(padded_ret + (padd_len - buff_len), buffer, buff_len + 1);
	free(buffer);
	return (padded_ret);
}

int				ft_num_conv(va_list ap, t_format *format)
{
	char			*buffer;
	long long int	nb;

	if (ft_str_set(format->spec, "lzj") != 0 || format->conv == 'D')
		nb = va_arg(ap, long long int);
	else if (ft_strncmp(format->spec, "hh", 2) == 0)
		nb = (signed char)va_arg(ap, int);
	else if (ft_strncmp(format->spec, "h", 1) == 0)
		nb = (short int)va_arg(ap, int);
	else
		nb = va_arg(ap, int);
	buffer = ft_itoa(nb);
	if (buffer == NULL)
		return (-1);
	if (nb == 0 && format->pre == 0)
		buffer[0] = '\0';
	buffer = ft_zero_padding(format, buffer, nb);
	if (buffer == NULL)
		return (-1);
	ft_putstr(buffer);
	free(buffer);
	return (ft_strlen(buffer));
}
