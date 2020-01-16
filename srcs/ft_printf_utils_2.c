/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 14:01:33 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

int		ft_check_va(va_list ap)
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

void	ft_spec_parser(char *arg, t_format *format)
{
	while (*arg != '\0' && format->conv == '\0')
	{
		if (ft_char_set(*arg, "lhzj") != 0)
			ft_fill_spec(format, *arg);
		arg++;
	}
}

void	ft_conv_parser(char *arg, t_format *format)
{
	while (*arg != '\0' && format->conv == '\0')
	{
		if (ft_char_set(*arg, "UDncspdiuxX%") != 0)
			format->conv = *arg;
		arg++;
	}
}

void	ft_flag_parser(char *arg, t_format *format)
{
	while (*arg != '\0' && ft_char_set(*arg, "0-+ #") != 0)
	{
		ft_fill_flag(format, *arg);
		arg++;
	}
}

void	ft_wildcard_arg(va_list ap, t_format *format, int type)
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
		if (wildcard_arg < 0 && ft_str_set(format->flag, "0") != 0)
			wildcard_arg = format->min_w;
		else if (wildcard_arg < 0)
			wildcard_arg = -1;
		format->pre = wildcard_arg;
	}
}
