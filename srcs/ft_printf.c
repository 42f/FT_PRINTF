/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/16 11:21:46 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

// -0.*
// malloc, free, write, va_start, va_arg, va_copy, va_end

static char		ft_find_id(const char *first_arg)
{
	int i;
	int y;
	char *set;

	i = 0;
	y = 0;
	set = "cspdiuxX%";
	while (first_arg[y] != '\0')
	{
		while (set[i] != '\0')
		{
			if (first_arg[y] == set[i])
				return (first_arg[y]);
			i++;
		}
		i = 0;
		y++;
	}
	return (0);
}

void			ft_fetch_next_arg(va_list ap, char id)
{
	if (id == '%')
		ft_putchar('%');
	if (id == 'c')
		ft_putchar(va_arg(ap, int));
	if (id == 's')
		ft_putstr(va_arg(ap, char*));
//	if (id == 'p')
//		next_arg = va_arg(ap, void*);
	if (id == 'd' || id == 'i' || id == 'u')
		ft_putnbr(va_arg(ap, int));
//	if (id == 'u')
//		next_arg = va_arg(ap, unsigned int);
//	if (id == 'x' || id == 'X')
//		next_arg = va_arg(ap, char);
}

static int		ft_str_manager(va_list ap, const char *first_arg)
{
	int		ret;
	int		i;
	char	id;

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
			id = ft_find_id(first_arg + i);
			ft_fetch_next_arg(ap, id);
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

