/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/17 18:03:27 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>



//toremove

static void	print_format(t_format *format)
{
	if (format == NULL)
		return ;
	printf("\n\n========= FORMAT =========\n");
	printf("flag 0 =    |%c|\n", format->flag[0]);
	printf("flag 1 =    |%c|\n", format->flag[1]);
	printf("flag 2 =    |%c|\n", format->flag[2]);
	printf("flag 3 =    |%c|\n", format->flag[3]);
	printf("flag 4 =    |%c|\n", format->flag[4]);
	printf("min_width = |%d|\n", format->min_width);
	printf("precision = |%d|\n", format->precision);
	printf("converter = |%c|\n", format->converter);
	//	system ("leaks a.out");
	printf("\n===== [END FORMAT] ======\n");

}




static t_format	*ft_format_init(void)
{
	t_format	*new_format;

	new_format = (t_format*)malloc(sizeof(t_format) * 1);
	if (new_format== NULL)
		return (NULL);
	new_format->flag = (char *)malloc(sizeof(char *) * 4);
	new_format->flag[0] = 0;
	new_format->flag[1] = 0;
	new_format->flag[2] = 0;
	new_format->flag[3] = 0;
	new_format->flag[4] = 0;
	new_format->min_width = -1;
	new_format->precision = -1;
	new_format->converter = 0;
	return (new_format);
}

static void		ft_fill_flag(t_format *format, char c)
{
	int			i;
	
	i = 0;
	while (i <= 4)
	{
		if (format->flag[i] == 0)
		{
			format->flag[i] = c;
			return ;
		}
		i++;
	}
}

static char		ft_is_set(char c, char *set)
{
	int			i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (c);
		i++;
	}
	return (0);
}

static t_format		*ft_format_parser(const char *first_arg)
{
	int			y;
	t_format	*format;
	char		converter;

	y = 0;
	format = ft_format_init();
	if (format == NULL)
		return (NULL);
	while (first_arg[y] != '\0' && format->converter == 0)
	{
		if (ft_is_set(first_arg[y], "-+#0 ") != 0 && y <= 4 && 
format->min_width == -1 && format->precision == -1)
			ft_fill_flag(format, first_arg[y]);
		if (ft_isdigit(first_arg[y]) == 1 && format->min_width == -1 && 
format->precision == -1)
			format->min_width = ft_atoi(first_arg + y);
		if (first_arg[y] == '.')
		{
			y++;
			format->precision = ft_atoi(first_arg + y);
		}
		converter = ft_is_set(first_arg[y], "cspdiuxX%");
		if (converter != 0)
			format->converter = converter;
		y++;
	}
	return (format);
}

static void			ft_fetch_next_arg(va_list ap, t_format *format)
{
//	int		ret;
//	char	*char_buffer;
	int		int_buffer;
	
	if (format->converter == '%')
		ft_putchar('%');
	else if (format->converter == 'c')
		ft_putchar(va_arg(ap, int));
	else if (format->converter == 's')
		ft_putstr(va_arg(ap, char*));
	else if (format->converter == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(va_arg(ap, unsigned long long int), "0123456789abcdef");
	}
	else if (format->converter == 'd' || format->converter == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (format->converter == 'u')
	{		
		int_buffer = va_arg(ap, int);
		if (int_buffer < 0)
			int_buffer = int_buffer * -1;
		ft_putnbr(int_buffer);
	}
	else if (format->converter == 'x')
		ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (format->converter == 'X')
		ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
//	free(format->flag);
//	free(format);
}

static int		ft_str_manager(va_list ap, const char *first_arg)
{
	int			ret;
	int			i;
	t_format	*format;

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
			format = ft_format_parser(first_arg + i);
			if (format == NULL)
				return (0);
			ft_fetch_next_arg(ap, format);
		while (first_arg[i] != '\0' && ft_is_set(first_arg[i], "cspdiuxX%") == 0)
				i++;
		}
		i++;
	}

	//remove
	print_format((void*)0);	
	print_format(format);
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

