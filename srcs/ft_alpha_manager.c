/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:45:58 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/14 11:51:49 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int		ft_printer_str(t_format *format, char *str_buffer)
{
	int			len;
	int			output_len;
	char		*output_str;

	len = ft_strlen(str_buffer);
	output_str = NULL;
	if (format->pre != -1 && format->pre < len)
	{
		str_buffer[format->pre] = '\0';
		len = format->pre;
	}
	output_len = len;
	if (format->min_w > output_len)
		output_len = format->min_w;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	ft_memset(output_str, ' ', output_len);
	if (ft_str_set(format->flag, "-") != NULL)
		ft_memcpy(output_str, str_buffer, len);
	else
		ft_memcpy(output_str + (output_len - len), str_buffer, len);
	ft_putstr(output_str);
	free(output_str);
	return (output_len);
}

static	void ft_put_c(char *output_str, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		ft_putchar(output_str[i]);
		i++;
	}
}

int		ft_printer_char(t_format *format, wchar_t c)
{
	char		*output_str;
	int			len;
	char		fill;
	
	fill = ' ';
	if (ft_str_set(format->flag, "0") != 0 && ft_str_set(format->flag, "-") == 0)
		fill = '0';
	len = 1;
	if (format->min_w > 1)
		len = format->min_w;
	output_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (output_str == NULL)
		return (-1);
	ft_memset(output_str, fill, len);
	if (ft_str_set(format->flag, "-") != 0)
		output_str[0] = c;
	else
		output_str[len - 1] = c;
	ft_put_c(output_str, len);
	free(output_str);
	return (len);
}

int		ft_alpha_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*str_buffer;

	ret = 0;
	if (format->conv == 'c' && ft_str_set(format->spec, "l") == 0)
		ret = ft_printer_char(format, va_arg(ap, int));
	else if (format->conv == 'c' && ft_str_set(format->spec, "l") != 0)
		ret = ft_printer_char(format, va_arg(ap, wint_t));
	else if (format->conv == 's')
	{
		if (ft_check_va(ap) == -1)
			str_buffer = ft_strdup("(null)");
		else
			str_buffer = ft_strdup(va_arg(ap, char*));
		ret = ft_printer_str(format, str_buffer);
		free(str_buffer);
	}
	return (ret);
}

