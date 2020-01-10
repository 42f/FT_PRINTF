/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:35:18 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/10 12:25:41 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

//remove
#include <fcntl.h>
#include <unistd.h>
//remove

static void	ft_prefix(t_format *format, char *ret, char *buffer, int nb)
{
	size_t		ret_len;
	size_t		buffer_len;

	ret_len = ft_strlen(ret);
	buffer_len = ft_strlen(buffer);
	if (nb < 0)
		ft_memset(ret, '-', 1);
	else if (nb >= 0 && ft_str_set(format->flag, "+") != 0)
		ft_memset(ret, '+', 1);
	else if (nb >= 0 && ft_str_set(format->flag, " ") != 0)
		ft_memset(ret, ' ', 1);
	ft_memcpy(ret + (ret_len - buffer_len), buffer, buffer_len);
}

static char	*ft_pad_buffer(t_format *format, char *buffer, int nb)
{
	char 		*ret;
	size_t		ret_len;
	int			buffer_len;

	buffer_len = ft_strlen(buffer);
	ret_len = buffer_len;
	if (nb < 0 || ft_str_set(format->flag, "+ ") != 0)
	{
		if (nb < 0)
			ft_memmove(buffer, buffer + 1, buffer_len);
		if (nb >= 0)
			ret_len++;
		format->pre++;
	}
	if (ft_str_set(format->flag, "0") != 0 && format->min_w > buffer_len && ft_str_set(format->flag, "-") == 0 )
		ret_len = format->min_w;
	if (format->pre > buffer_len)
		ret_len = format->pre;
	ret = (char *)ft_calloc(ret_len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, '0', ret_len);
	ft_prefix(format, ret, buffer, nb);



ft_putstr("\n ");
ft_putstr(ret);
ft_putstr("\n[");


	free(buffer);
	return (ret);
}

static char	*ft_zero_padding(t_format *format, char *buffer, int nb)
{
	char			*padded_ret;
	size_t			buffer_len;
	size_t			padded_len;

	buffer = ft_pad_buffer(format, buffer, nb);
	buffer_len = ft_strlen(buffer);
	padded_len = buffer_len;
	if (format->min_w > (int)buffer_len)
		padded_len = format->min_w;
	padded_ret = (char *)ft_calloc(padded_len + 1, sizeof(char));
	if (padded_ret == NULL)
		return (NULL);
	ft_memset(padded_ret, ' ', padded_len);
	if (ft_str_set(format->flag, "-") != 0)
		ft_memcpy(padded_ret, buffer, buffer_len);
	else
		ft_memcpy(padded_ret + (padded_len - buffer_len), buffer, buffer_len + 1);
	free(buffer);
	return (padded_ret);
}

int		ft_num_conv(va_list ap, t_format *format)
{
	int				ret;
	char			*buffer;
	long int		nb;

	ret = 0;
	if (ft_str_set(format->spec, "l") != 0 || format->conv == 'D')
		nb = va_arg(ap, long int);
	else
		nb = va_arg(ap, int);
	buffer = ft_itoa(nb);
	if (buffer == NULL)
		return (-1);
	if (nb == 0 && (format->pre == 0 || format->min_w == -1))
	{
		ft_memset(buffer, '\0', ft_strlen(buffer));
		if ((format->pre == -1 && format->min_w == -1))
			buffer[0] = '0';
	}
	buffer = ft_zero_padding(format, buffer, nb);
	ft_putstr(buffer);
	ret = ft_strlen(buffer);
	return (ret);
}

