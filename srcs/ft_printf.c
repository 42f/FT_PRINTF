/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/21 17:45:04 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

//toremove
//
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
	printf("flag 5 =    |%c|\n", format->flag[5]);
	printf("min_width = |%d|\n", format->min_width);
	printf("precision = |%d|\n", format->precision);
	printf("converter = |%c|\n", format->converter);
	//	system ("leaks a.out");
	printf("\n===== [END FORMAT] ======\n");

}
//
// REMOVE ABOVE


static t_format	*ft_format_init(void)
{
	t_format	*new_format;

	new_format = (t_format*)malloc(sizeof(t_format) * 1);
	if (new_format== NULL)
		return (NULL);
	new_format->flag = (char *)malloc(sizeof(char *) * 5);
	new_format->flag[0] = '\0';
	new_format->flag[1] = '\0';
	new_format->flag[2] = '\0';
	new_format->flag[3] = '\0';
	new_format->flag[4] = '\0';
	new_format->flag[5] = '\0';
	new_format->min_width = -1;
	new_format->precision = -1;
	new_format->converter = '\0';
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

static char		ft_isset(char c, char *set)
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

static char			*ft_zero_padding(t_format *format, char *str_buffer)
{
	char		*padded_buffer;	
	size_t		len;
	int			nb;

	nb = ft_atoi(str_buffer);
	len = ft_strlen(str_buffer);
	if (format->precision != -1 && format->precision > (int)len)
	{
		padded_buffer = (char *)ft_calloc(len + 1, sizeof(char));	
		ft_memset(padded_buffer, '0', format->precision - len);
		ft_strlcpy(padded_buffer + (format->precision - len), str_buffer, len + 1);
		return (padded_buffer);
	}
	return (str_buffer);
}

static int			ft_printer_nbr(t_format *format, char *str_buffer)
{
	int			len;
	int			output_len;
	char		*padded_buffer;
	char		*output_str;

	if (str_buffer == NULL)
		return (0);
	padded_buffer = ft_zero_padding(format, str_buffer); 
	len = ft_strlen(padded_buffer);
	output_len = len;
	if (format->min_width > output_len)
		output_len = format->min_width;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	if (ft_strnstr(format->flag, "-", 5) != 0)
	{
		ft_strlcpy(output_str, padded_buffer, output_len + 1);
		if (output_len > len)
			ft_memset(output_str + len, ' ', output_len - len);
	}	
	else
	{
		if (output_len > len)
			ft_memset(output_str, ' ', output_len - len);
		ft_strlcpy(output_str + (output_len - len), padded_buffer, output_len + 1);
	}
	if (ft_atoi(str_buffer) == 0 && format->min_width == -1 && format->precision == 0)
	{	
		free(output_str);
		return (output_len);
	}
	else if (ft_atoi(str_buffer) == 0 && format->precision == 0 && output_len > len)
		ft_memset(output_str, ' ', output_len);
	ft_putstr(output_str);
	free(output_str);
	return (output_len);
}


static int			ft_printer_str(t_format *format, char *str_buffer)
{
	int			len;
	int			output_len;
	char		*output_str;

	len = ft_strlen(str_buffer);
	output_str = NULL;
	if (format->precision != -1 && format->precision < len) 
	{
		str_buffer[format->precision] = '\0';
		len = format->precision;
	}
	output_len = len;
	if (format->min_width > len)
	{
		output_str = (char *)ft_calloc(format->min_width + 1, sizeof(char));
		output_len = format->min_width;
	}
	else 
		output_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (output_str == NULL)
		return (0);
	if (ft_strnstr(format->flag, "-", 5) != 0)
	{
		ft_strlcpy(output_str, str_buffer, len + 1);
		ft_memset(output_str + len, ' ', output_len - len);
	}
	else 
	{
		ft_memset(output_str, ' ', output_len - len);
		ft_strlcpy(output_str + (output_len - len), str_buffer, len + 1);
	}
	if (format->min_width == -1 || format->min_width < len)
	{
		ft_strlcpy(output_str, str_buffer, len + 1);
	}
	ft_putstr(output_str);
	free(output_str);
	return (0);
}


static int			ft_fetch_next_arg(va_list ap, t_format *format)
{
	int		ret;
	char	*str_buffer;
	
	ret = 0;
	if (format->converter == '%')
		ft_putchar('%');
	else if (format->converter == 'c')
	{
		str_buffer = (char *)ft_calloc(2, sizeof(char));
		str_buffer[0] = (char)va_arg(ap, int);
		ft_printer_str(format, str_buffer);
	}
	else if (format->converter == 's')
	{
		str_buffer = ft_strdup(va_arg(ap, char*));
		ft_printer_str(format, str_buffer);
	}
	else if (format->converter == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(va_arg(ap, unsigned long long int), "0123456789abcdef");
	}
	else if (ft_isset(format->converter, "diu"))
	{
		str_buffer = ft_itoa(va_arg(ap, int));
		ft_printer_nbr(format, str_buffer);
	}
/*	else if (format->converter == 'u')
	{		
		int_buffer = va_arg(ap, int);
		if (int_buffer < 0)
			int_buffer = int_buffer * -1;
		ft_putnbr(int_buffer);
	}
*/
	else if (format->converter == 'x')
		ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (format->converter == 'X')
		ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	return(ret);
	free(str_buffer);
	free(format->flag);
	free(format);
}

static t_format		*ft_format_parser(va_list ap, const char *first_arg)
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
		if (y <= 5 && ft_isset(first_arg[y], "-+'#0 ") != 0 &&
format->min_width == -1 && format->precision == -1)
			ft_fill_flag(format, first_arg[y]);
		else if (ft_isset(first_arg[y], "0123456789*") != 0 && format->min_width == -1 && format->precision == -1)
		{
			if (first_arg[y] != '*')
				format->min_width = ft_atoi(first_arg + y);
			else
				format->min_width = va_arg(ap, int);
		}
		else if (first_arg[y] == '.')
		{
			y++;
			if (first_arg[y] != '*')
				format->precision = ft_atoi(first_arg + y);
			else
				format->precision = va_arg(ap, int);
		}
		else if ((converter = ft_isset(first_arg[y], "cspdiuxX%")) != 0)
			format->converter = converter;
		y++;
	}
	return (format);
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
			format = ft_format_parser(ap, first_arg + i);
			if (format == NULL)
				return (0);
			ret += ft_fetch_next_arg(ap, format);
			while (first_arg[i] != '\0' && ft_isset(first_arg[i], "cspdiuxX%") == 0)
				i++;
		}
		i++;
	}

	//remove
	print_format((void*)0);	
//  print_format(format);
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

