/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/23 18:00:02 by bvalette         ###   ########.fr       */
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
	printf("min_w = |%d|\n", format->min_w);
	printf("pre = |%d|\n", format->pre);
	printf("conv = |%c|\n", format->conv);
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
	new_format->min_w = -1;
	new_format->pre = -1;
	new_format->conv = '\0';
	return (new_format);

// remove
(void)print_format((void *)0);

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

static char		*ft_zero_padding(t_format *format, char *str_buffer, int nb)
{
	char		*padded_ret;	
	size_t		len;

	len = ft_strlen(str_buffer)	;
	if (format->pre > (int)len)
	{
		if (nb < 0)
		{
			str_buffer[0] = '0';
			len += 1;
			format->pre += 2;
		}
		padded_ret = (char *)ft_calloc(len + format->pre + 1, sizeof(char));
		if (nb < 0)
		{		
			ft_memset(padded_ret, '-', 1);
			ft_memset(padded_ret + 1, '0', format->pre - len);
			ft_strlcpy(padded_ret + (format->pre - len), str_buffer, len + 1);
		}
		else
		{
			ft_memset(padded_ret, '0', format->pre - len);
			ft_strlcpy(padded_ret + (format->pre - len), str_buffer, len + 1);
		}
		free(str_buffer);	
		return (padded_ret);
	}
	return (str_buffer);
}

static int		ft_putnum(t_format *format, char *padded_buff, char *output_str)
{
	size_t		output_len;
	size_t		len;

	output_len = ft_strlen(output_str);
	len = ft_strlen(padded_buff);
	if (ft_atoi(padded_buff) == 0 && format->min_w == -1 && format->pre == 0)
	{	
		ft_putchar('\0');
		output_len = 0;
	}
	else if (ft_atoi(padded_buff) == 0 && format->pre == 0 && output_len > len)
	{
		ft_memset(output_str, ' ', output_len);
		ft_putstr(output_str);
	}
	else
		ft_putstr(output_str);
	free(output_str);
	free(padded_buff);
	return (output_len);
}

static int		ft_printer_nbr(t_format *format, char *str_buffer)
{
	size_t		len;
	size_t		output_len;
	char		*padded_buff;
	char		*output_str;

	if (str_buffer == NULL)
		return (0);
	padded_buff = ft_zero_padding(format, str_buffer, ft_atoi(str_buffer));
	len = ft_strlen(padded_buff);
	output_len = len;
	if (format->min_w > (int)len)
		output_len = format->min_w;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	if (ft_strnstr(format->flag, "-", 5) != 0)
	{
		ft_strlcpy(output_str, padded_buff, len + 1);
		ft_memset(output_str + len, ' ', output_len - len);
	}	
	else
	{
		ft_memset(output_str, ' ', output_len - len);
		ft_strlcpy(output_str + output_len - len, padded_buff, output_len + 1);
	}
	return (ft_putnum(format, padded_buff, output_str));	
}

static int		ft_printer_str(t_format *format, char *str_buffer)
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
	if (format->min_w > len)
	{
		output_str = (char *)ft_calloc(format->min_w + 1, sizeof(char));
		output_len = format->min_w;
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
	if (format->min_w == -1 || format->min_w < len)
	{
		ft_strlcpy(output_str, str_buffer, len + 1);
	}
	ft_putstr(output_str);
	free(output_str);
return (output_len);
}

static int		ft_hex_conv(va_list ap, t_format *format)
{
	int			ret;

	ret = 0;
	if (format->conv == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(va_arg(ap, unsigned long long int), "0123456789abcdef");
	}
	else if (format->conv == 'x')
		ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (format->conv == 'X')
		ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	return (ret);
}

static int		ft_num_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*str_buffer;
	int			int_buffer;

	ret = 0;
	if (format->conv == 'u')
	{		
		int_buffer = va_arg(ap, int);
		if (int_buffer < 0)
			int_buffer = int_buffer * -1;
		ft_putnbr(int_buffer);
	}
	else if (ft_isset(format->conv, "di"))
	{
		str_buffer = ft_itoa(va_arg(ap, int));
		ret = ft_printer_nbr(format, str_buffer);
	}
		return (ret);
}

static int		ft_alpha_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*str_buffer;

	ret = 1;
	if (format->conv == '%')
		ft_putchar('%');
	else if (format->conv == 'c')
	{
		str_buffer = (char *)ft_calloc(2, sizeof(char));
		str_buffer[0] = (char)va_arg(ap, int);
		ret = ft_printer_str(format, str_buffer);
	}
	else if (format->conv == 's')
	{
		str_buffer = ft_strdup(va_arg(ap, char*));
		ret = ft_printer_str(format, str_buffer);
	}
	return (ret);
}

static int		ft_next_arg(va_list ap, t_format *format)
{
	int			ret;
	
	ret = 0;
	if (ft_isset(format->conv, "sc%") != 0)
		ret = ft_alpha_conv(ap, format);
	else if (ft_isset(format->conv, "diu") != 0)
		ret = ft_num_conv(ap, format);
	else if (ft_isset(format->conv, "pxX") != 0)
		ret = ft_hex_conv(ap, format);
	free(format->flag);
	free(format);
	return(ret);
}

static t_format	*ft_format_parser(va_list ap, const char *first_arg)
{
	int			y;
	t_format	*format;
	char		conv;

	y = 0;
	format = ft_format_init();
	if (format == NULL)
		return (NULL);
	while (first_arg[y] != '\0' && format->conv == 0)
	{
		if (y <= 5 && ft_isset(first_arg[y], "-+'#0 ") != 0 &&
format->min_w == -1 && format->pre == -1)
			ft_fill_flag(format, first_arg[y]);
		else if (ft_isset(first_arg[y], "0123456789*") != 0 &&
 format->min_w == -1 && format->pre == -1)
		{
			if (first_arg[y] != '*')
				format->min_w = ft_atoi(first_arg + y);
			else
				format->min_w = va_arg(ap, int);
		}
		else if (first_arg[y] == '.')
		{
			y++;
			if (first_arg[y] != '*')
				format->pre = ft_atoi(first_arg + y);
			else
				format->pre = va_arg(ap, int);
		}
		else if ((conv = ft_isset(first_arg[y], "cspdiuxX%")) != 0)
			format->conv = conv;
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
			ret += ft_next_arg(ap, format);
			while (first_arg[i] != '\0' && ft_isset(first_arg[i], "cspdiuxX%") == 0)
				i++;
		}
		i++;
	}
	return (ret);
}

int				ft_printf(const char *first_arg, ...)
{
	int 		ret;
	va_list 	ap;

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

