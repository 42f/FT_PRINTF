/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_manager_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:48:30 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:04 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

void		ft_str_toupper(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

char		ft_set_cfill(t_format *format)
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

static char	*ft_padding(t_format *format, char *hex_str, int pre, int offset)
{
	char		*padded_ret;
	size_t		padded_len;
	size_t		hex_len;

	hex_len = ft_strlen(hex_str);
	if (pre < 0)
		pre = 0;
	padded_len = hex_len + offset;
	if (format->pre > (int)hex_len)
		padded_len = pre + offset;
	else if (ft_str_set(format->flag, "0") != 0 && format->pre == -1
	&& format->min_w != -1 && format->min_w > (int)hex_len + offset)
		padded_len = format->min_w;
	padded_ret = (char *)ft_calloc(padded_len + 1, sizeof(char));
	if (padded_ret == NULL)
		return (NULL);
	ft_memset(padded_ret, ' ', padded_len);
	if (ft_str_set(format->flag, "0") != 0 || format->pre > (int)hex_len)
		ft_memset(padded_ret, '0', padded_len);
	if (offset == 2)
		ft_memcpy(padded_ret, "0x", 2);
	ft_memcpy(padded_ret + (padded_len - hex_len), hex_str, hex_len);
	free(hex_str);
	return (padded_ret);
}

char		*ft_p_pre_padding(t_format *format, char *hex_str)
{
	int			offset;
	char		*ret_str;

	offset = 2;
	if (hex_str[0] == '0' && format->pre == 0)
		ft_memset(hex_str, '\0', ft_strlen(hex_str));
	ret_str = ft_padding(format, hex_str, format->pre, offset);
	return (ret_str);
}

char		*ft_x_pre_padding(t_format *format, char *hex_str)
{
	int			offset;
	char		*ret_str;

	offset = 0;
	if (hex_str[0] == '0')
	{
		if (format->pre == 0)
			ft_memset(hex_str, '\0', ft_strlen(hex_str));
	}
	else if (ft_str_set(format->flag, "#") != 0)
		offset = 2;
	ret_str = ft_padding(format, hex_str, format->pre, offset);
	return (ret_str);
}
