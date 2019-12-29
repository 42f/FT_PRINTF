/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:45:58 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/29 16:07:29 by bvalette         ###   ########.fr       */
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
	if (format->pre != -1 && format->pre < len && format->conv != 'c') 
	{
		str_buffer[format->pre] = '\0';
		len = format->pre;
	}
	output_len = len;
	if (format->min_w > len)
	{
		output_str = (char *)ft_calloc(format->min_w + 1, sizeof(char));
		output_len = format->min_w;
	}
	else
		output_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (output_str == NULL)
		return (0);
	if (ft_strnstr(format->flag, "-", 5) != NULL)
	{
		ft_strlcpy(output_str, str_buffer, len + 1);
		ft_memset(output_str + len, ' ', output_len - len);
	}
	else 
	{
		ft_memset(output_str, ' ', output_len - len);
		ft_strlcpy(output_str + (output_len - len), str_buffer, len + 1);
	}
	ft_putstr(output_str);
	free(output_str);
	return (output_len);
}



int		ft_printer_char(t_format *format, unsigned char c)
{
	char		*output_str;
	int			len;
	char		fill;

	fill = ' ';
	if (ft_str_set(format->flag, "0") != 0 && ft_str_set(format->flag, "-") == 0)
		fill = '0';
	len = 1;
	if (format->min_w != -1)
		len = format->min_w;
	output_str = (char *)ft_calloc(len + 1, sizeof(char));
	output_str[0] = c;
	if (format->min_w != -1 && ft_str_set(format->flag, "-") != 0)
	{
		ft_memset(output_str, fill, len);
		if (c == '\0')
			output_str[len - 1] = c;
		else
			output_str[0] = c;
	}
	else if (format->min_w != -1 && ft_str_set(format->flag, "-") == 0)
	{
		ft_memset(output_str, fill, len);
		output_str[len - 1] = c;
	}	
	ft_putstr(output_str);
	free(output_str);
	return (len);
}

/*
** alpha manager is called if format conv is a 's' 'c' or '%'
*/

int		ft_alpha_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*str_buffer;

	ret = 1;
	if (format->conv == '%')
		ft_putchar('%');
	else if (format->conv == 'c')
		ret = ft_printer_char(format, va_arg(ap, int));
	else if (format->conv == 's')
	{
		str_buffer = ft_strdup(va_arg(ap, char*));
		if (str_buffer == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		ret = ft_printer_str(format, str_buffer);
		free(str_buffer);
	}
//print_format(format);
	return (ret);
}


