/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/17 13:29:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

// -0.*
// malloc, free, write, va_start, va_arg, va_copy, va_end


static t_format	*ft_format_init(void)
{
	t_format	*new_format;

	new_format= (t_format*)malloc(sizeof(t_format) * 1);
	if (new_format== NULL)
		return (NULL);
	new_format->flag = 0;
	new_format->min_width = -1;
	new_format->precision = -1;
	new_format->converter = 0;
	return (new_format);
}

static char		ft_is_converter(char first_arg)
{
	char		*set;
	int			i;

	set = "cspdiuxX%";
	i = 0;
	while (set[i] != '\0')
	{
		if (first_arg == set[i])
			return (first_arg);
		i++;
	}
	return (0);
}

static char		ft_format_parser(const char *first_arg)
{
	int			y;
	t_format	*format;
	char		converter;

	y = 0;
	format = ft_format_init();
	if (format == NULL)
		return (0);
	while (first_arg[y] != '\0')
	{
		if ((first_arg[y] == '-'  || first_arg[y] == '0') && y == 0)
			format->flag = first_arg[y];
		if (ft_isdigit(first_arg[y]) == 1 && format->min_width == -1)
			format->min_width = ft_atoi(first_arg + y);
		if (first_arg[y] == '.')
		{
			y++;
			format->precision = ft_atoi(first_arg + y);
		}
		converter = ft_is_converter(first_arg[y]);
		if (converter != 0)
		{
			format->converter = converter;
			break;
		}
		y++;
	}
	//remove
	printf("\n[converter = |%c|\nflag = |%c|\nmin_width = |%d|\nprecision = |%d|]\n", format->converter, format->flag, format->min_width, format->precision);
//	system ("leaks a.out");

	return (first_arg[y]);
}

static void			ft_fetch_next_arg(va_list ap, char id)
{
//	int		ret;
//	char	*buffer;
	return ;
	if (id == '%')
		ft_putchar('%');
	else if (id == 'c')
		ft_putchar(va_arg(ap, int));
	else if (id == 's')
		ft_putstr(va_arg(ap, char*));
//	else if (id == 'p')
//		next_arg = va_arg(ap, void*);
	else if (id == 'd' || id == 'i' || id == 'u')
		ft_putnbr(va_arg(ap, int));
//	else if (id == 'u')
//		next_arg = va_arg(ap, unsigned int);
//	else if (id == 'x' || id == 'X')
//		next_arg = va_arg(ap, char);
}

static int		ft_str_manager(va_list ap, const char *first_arg)
{
	int		ret;
	int		i;
	char	converter;
	i = 0;
	ret = 0;
	while (first_arg[i] != '\0')
	{
		if (first_arg[i] != '%')
		{
			ft_putchar(first_arg[i]);
			ret++;
		}
		else 
		{
			i++;
			converter = ft_format_parser(first_arg + i);
			ft_fetch_next_arg(ap, converter);
			while (first_arg[i] != '\0' && ft_is_converter(first_arg[i]) == 0)
				i++;
		}
		i++;
	}
	return (ret);
}

int	ft_printf(const char *first_arg, ...)
{
	int 	ret;
	va_list ap;

	ret = 0;
	if (first_arg == NULL)
		return (0);
	if (ft_strchr(first_arg, '%') == NULL)
	{
		ft_putstr((char *)first_arg);
		return(ft_strlen(first_arg));
	}
	va_start(ap, first_arg);
	ret = ft_str_manager(ap, first_arg);
	va_end(ap);
	return (ret);
}

