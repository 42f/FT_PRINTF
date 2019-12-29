/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/29 17:40:10 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>

int		ft_next_arg(va_list ap, t_format *format)
{
	int			ret;

	ret = 0;
	if (ft_char_set(format->conv, "sc%") != 0)
		ret = ft_alpha_conv(ap, format);
	else if (ft_char_set(format->conv, "di") != 0)
		ret = ft_num_conv(ap, format);
	else if (ft_char_set(format->conv, "u") != 0)
		ret = ft_unsigned_conv(ap, format);
	else if (ft_char_set(format->conv, "pxX") != 0)
		ret = ft_hex_conv(ap, format);
	free(format->flag);
	free(format);
	return(ret);
}

/*
int			ft_next_parser(va_list ap, const char *arg, t_format *format)
{
	int			y;

	y = 0;
	while (arg[y] != '\0' && format->conv == '\0' && ft_char_set(arg[y], "+-0 .ncspduixX%") != 0)
	{
		if (arg[y] == '.')
		{
			format->pre = ft_atoi(arg + y + 1);
			if (arg[y + 1] == '*')
				format->pre = va_arg(ap, int);
		}
		else if (ft_char_set(arg[y], "lh") != 0)
			ft_fill_spec(format, arg[y]);
		else if (ft_char_set(arg[y], "ncspdiuxX%") != 0)
			format->conv = arg[y];
		y++;
	}
	return (0);
}

t_format	*ft_format_parser(va_list ap, const char *arg, t_format *format)
{
	int			y;
	int			output;

	y = 0;
	format = ft_format_init();
	if (format == NULL)
		return (NULL);
	while (arg[y] != '\0' && format->conv == '\0' && ft_char_set(arg[y], "+-0 .ncspduixX%") != 0)
//	while (arg[y] != '\0' && format->conv == '\0' )
	{
		if (ft_char_set(arg[y], "-+'#0 ") != 0 &&
format->min_w == -1 && format->pre == -1)
			ft_fill_flag(format, arg[y]);
		else if (ft_char_set(arg[y], "0123456789*") != 0 &&
 format->min_w == -1 && format->pre == -1)
		{
			format->min_w = ft_atoi(arg + y);
			if (arg[y] == '*')
				format->min_w = va_arg(ap, int);
		}
		else
			output = ft_next_parser(ap, arg + y, format);
		y++;
	}
	if(format->conv == '\0')
		return (NULL);	
	return (format);
}
*/


t_format	*ft_format_parser(va_list ap, char *arg, t_format *format)
{
	char 		*precision;
	char 		*min_width;
	
	format = ft_format_init();
	if (format == NULL)
		return (NULL);
	
	min_width = ft_str_set(arg, "123456789*");
	if (min_width != NULL && *min_width != '*')
		format->min_w = ft_atoi(min_width);
	if (min_width != NULL && *min_width == '*')
		format->min_w = va_arg(ap, int);
	precision = ft_str_set(arg, ".");
	if (precision != NULL && precision[1] != '*')
		format->pre = ft_atoi(precision + 1);
	if (precision != NULL && precision[1] == '*')
		format->pre = va_arg(ap, int);
	while (*arg != '\0' && ft_char_set(*arg,"0-+ ") != 0)
	{
		ft_fill_flag(format, *arg);
		arg++;
	}
	while (*arg != '\0' && format->conv == '\0')
	{
		if (ft_char_set(*arg, "ncspdiuxX%") != 0)
			format->conv = *arg;
		arg++;
	}
//print_format(format);
	return (format);	
}


void	ft_n_conv(va_list ap, int ret)
{
	int		*int_arg;

	int_arg = va_arg(ap, int *);
	*int_arg = ret;
}


int		ft_arg_manager(va_list ap, const char *arg, t_format *format)
{
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '%')
		{
			i++;
			format = ft_format_parser(ap, (char *)arg + i, format);
			if (format == NULL)
				return (-1);
			if (format->conv != 'n')
				ret += ft_next_arg(ap, format); 
			else
				ft_n_conv(ap, ret);
		while (arg[i] != '\0' && ft_char_set(arg[i], "ncspdiuxX%") == 0)
				i++;
		}
		else
			ret += ft_putchar(arg[i]);
		i++;
	}
	return (ret);
}

int				ft_printf(const char *arg, ...)
{
	int 		ret;
	va_list 	ap;
	t_format	*format;

	ret = 0;
	format = NULL;
	if (arg == NULL)
		return (0);
	if (ft_strchr(arg, '%') == NULL)
	{
		ft_putstr((char *)arg);
		return(ft_strlen(arg));
	}
	va_start(ap, arg);
	ret = ft_arg_manager(ap, arg, format);
	va_end(ap);
	return (ret);
}

