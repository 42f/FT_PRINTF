/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/12 11:25:57 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>

int		ft_next_arg(va_list ap, t_format *format, int main_ret)
{
	int			ret;

	ret = 0;
	if (ft_char_set(format->conv, "%") != 0)
		ret = ft_percent_conv(format);
	else if (ft_char_set(format->conv, "sc") != 0)
		ret = ft_alpha_conv(ap, format);
	else if (ft_char_set(format->conv, "Ddi") != 0)
		ret = ft_num_conv(ap, format);
	else if (ft_char_set(format->conv, "Uu") != 0)
		ret = ft_unsigned_conv(ap, format);
	else if (ft_char_set(format->conv, "pxX") != 0)
		ret = ft_hex_conv(ap, format);
	else if (format->conv == 'n')
		ret = ft_n_conv(ap, main_ret);
	free(format);
	return(ret);
}

void		ft_spec_parser(char *arg, t_format *format)
{
	while (*arg != '\0' && format->conv == '\0')
	{
		if (ft_char_set(*arg, "lhzj") != 0)
			ft_fill_spec(format, *arg);
		arg++;
	}
}

void		ft_conv_parser(char *arg, t_format *format)
{
	while (*arg != '\0' && format->conv == '\0')
	{
		if (ft_char_set(*arg, "UDncspdiuxX%") != 0)
			format->conv = *arg;
		arg++;
	}
}

void		ft_flag_parser(char *arg, t_format *format)
{
	while (*arg != '\0' && ft_char_set(*arg,"0-+ #") != 0)
	{
		ft_fill_flag(format, *arg);
		arg++;
	}
}

int			ft_arg_trim(char *arg)
{
	int			i;
	int 		ret;

	i = 0;
	ret = -1;
	while (arg[i] != '\0')
	{
		if ((ft_isalpha(arg[i]) == 1 || arg[i] == '%') 
			&& ft_char_set(arg[i], "hlzj") == 0)
		{
			arg[i + 1] = '\0';
			ret = 1;
			break;
		}
		i++;
	}
	if (ft_char_set(arg[i], "UDncspdiuxX%") == 0)
	{
		ret = -1;
		free(arg);
	}
	return (ret);
}

static void	ft_wildcard_arg(va_list ap, t_format *format, int type)
{
	int			wildcard_arg;

	wildcard_arg = 0;
	if (type == 1)
	{
		wildcard_arg = va_arg(ap, int);
		if (wildcard_arg < 0)
		{
			wildcard_arg = -wildcard_arg;
			ft_fill_flag(format, '-');
		}
		format->min_w = wildcard_arg;
	}
	else if (type == 2)
	{
		wildcard_arg = va_arg(ap, int);
		if (wildcard_arg < 0)
			wildcard_arg = -wildcard_arg;
		format->pre = wildcard_arg;
	}
}

int		ft_format_parser(va_list ap, char *arg, t_format *format)
{
	char 		*precision_ptr;
	char 		*min_width;

	if (ft_arg_trim(arg) == -1)
		return (-1);	
	min_width = ft_str_set(arg, "123456789*.");
	if (min_width != NULL && *min_width != '*' && *min_width != '.')
		format->min_w = ft_atoi(min_width);
	else if (min_width != NULL && *min_width == '*' && *min_width != '.')
		ft_wildcard_arg(ap, format, 1);
	precision_ptr = ft_str_set(arg, ".");
	if (precision_ptr != NULL && precision_ptr[1] != '*')
		format->pre = ft_atoi(precision_ptr + 1);
	else if(precision_ptr != NULL && precision_ptr[1] == '*')
		ft_wildcard_arg(ap, format, 2);
	ft_flag_parser(arg, format);
	ft_spec_parser(arg, format);
	ft_conv_parser(arg, format);
	free(arg);
	return (0);
}


int		ft_arg_manager(va_list ap, char *arg, t_format *format)
{
	int			ret;

	ret = 0;
	while (*arg != '\0')
	{
		if (*arg == '%')
		{
			arg++;
			if (ft_char_set(*arg, "0123456789 -*+#'.UDncspdiuxX%lhzj") == 0)
				continue ;
			format = ft_format_init();
			if (format == NULL
			|| ft_format_parser(ap, ft_strdup(arg), format) == -1)
				return (-1);
			ret += ft_next_arg(ap, format, ret); 
			while (*arg != '\0' && ft_char_set(*arg, "UDncspdiuxX%") == 0)
				arg++;
		}
		else
			ret += ft_putchar(*arg);
		arg++;
	}
	return (ret);
}

int				ft_check_va(va_list ap)
{
	va_list ap_tmp;
	char	*str_tmp;
	int		ret;

	ret = 1;
	va_copy(ap_tmp, ap);
	str_tmp = va_arg(ap_tmp, char*);
	if (str_tmp == NULL)
	{
		va_arg(ap, char*);
		ret = -1;
	}
	va_end(ap_tmp);
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
	ret = ft_arg_manager(ap, (char *)arg, format);
	va_end(ap);
	return (ret);
}

