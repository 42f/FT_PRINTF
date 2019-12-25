/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/25 12:26:11 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>

int		ft_printer_str(t_format *format, char *str_buffer);

//toremove
//
/*
void *xmalloc(size_t n, size_t size)
 {
	int r = rand() % 200;      // Returns a pseudo-random integer between 0 and RAND_MAX.
	int alloc_number = 0;
	int fail_after = r;

	if (fail_after > 0 && r < 100)
 	{
 		printf("MALLOC FAIL @ the malloc number = [%d]{r = %d}\n", alloc_number, r);
		r = rand() % 30; 
		alloc_number++;
 		return NULL;
 	}
 	alloc_number++;

 	return ft_calloc(n, size);
 }
 #define ft_calloc(x, y) xmalloc(x, y)
*/
void	print_format(t_format *format)
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


t_format	*ft_format_init(void)
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

void		ft_fill_flag(t_format *format, char c)
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

char		ft_str_set(char* str, char *set)
{
	int			i;
	int			y;

	i = 0;
	y = 0;

	while (str[y] != '\0')
	{
		while (set[i] != '\0')
		{
			if (str[y] == set[i])
				return (str[y]);
			i++;
		}
		i = 0;
		y++;
	}
	return (0);
}

char		ft_char_set(char c, char *set)
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

char		*ft_zero_padding(t_format *format, char *str_buffer, int nb)
{
	char		*padded_ret;	
	size_t		len;
	int			i;
	int			precision;

	len = ft_strlen(str_buffer);
	precision = format->pre;
	i = 0;
	if (nb < 0 || ft_str_set(format->flag, "+ 0") != 0) 
	{
		if (nb < 0 && precision > (int)len)
			str_buffer[0] = '0';
		len += 1;
//		if (ft_str_set(format->flag, "0") != 0 && len < (size_t)format->min_w) 
//			len = format->min_w;
		precision += 2;
		i = 1;
	}
	if (ft_str_set(format->flag, "0") != 0)
		precision = format->min_w;	
	padded_ret = (char *)ft_calloc(len + precision + i, sizeof(char));
	if (nb < 0 && precision > (int)len)
		ft_memset(padded_ret, '-', 1);
	else if (nb >= 0 && ft_str_set(format->flag, "+") != 0)
		ft_memset(padded_ret, '+', 1);
	else if (nb >= 0 && ft_str_set(format->flag, " ") != 0)
		ft_memset(padded_ret, ' ', 1);
	else
		i = 0;	
	if (precision > (int)len)
	{
		ft_memset(padded_ret + i, '0', precision - len);
		ft_strlcpy(padded_ret + (precision - len), str_buffer, len + 1);
	}
	else
		ft_strlcpy(padded_ret + i, str_buffer, len + 1);
	free(str_buffer);
	return (padded_ret);
}

int		ft_putnum(t_format *format, char *padded_buff, char *output_str)
{
	size_t		output_len;
	size_t		len;
	int			nb;
	int			offset;

	nb = ft_atoi(padded_buff);
	if (output_str == NULL)
		return (0);
	output_len = ft_strlen(output_str);
	len = ft_strlen(padded_buff);
	offset = 0;
	if (ft_str_set(format->flag, "+ ") != 0)
		offset = 1;
	if (nb == 0 && format->pre == 0 && output_len > len)
		ft_memset(output_str, ' ', output_len);
	else if (nb == 0 && format->min_w == -1 && format->pre == 0)
	{	
		ft_memset(output_str + offset, '\0', 1);
		output_len = offset;
	}
	ft_putstr(output_str);
	free(output_str);
	free(padded_buff);
	return (output_len);
}

int		ft_printer_nbr(t_format *format, char *str_buffer)
{
	size_t		len;
	size_t		output_len;
	char		*padded_buff;
	char		*output_str;

	if (str_buffer == NULL)
		return (0);
	padded_buff = ft_zero_padding(format, str_buffer, ft_atoi(str_buffer));
	if (padded_buff == NULL)
		return (0);	
	len = ft_strlen(padded_buff);
	output_len = len;
	if (format->min_w > (int)len)
		output_len = format->min_w;
	output_str = (char *)ft_calloc(output_len + 1, sizeof(char));
	ft_memset(output_str, ' ', output_len);
	if (ft_str_set(format->flag, "0") != 0)
		ft_memset(output_str, '0', output_len);
	if (ft_str_set(format->flag, "-") != 0 && output_str != NULL)
	{
		ft_strlcpy(output_str, padded_buff, len + 1);
		ft_memset(output_str + len, ' ', output_len - len);
	}	
	else if (output_str != NULL)
		ft_strlcpy(output_str + output_len - len, padded_buff, output_len + 1);
	return (ft_putnum(format, padded_buff, output_str));	
}

int		ft_printer_char(t_format *format, unsigned char c)
{
	char		*output_str;
	int			output;

	output_str = NULL;
	output = 0;
	if (format->min_w == -1)
	{
		if (ft_str_set(format->flag, "+- ") != 0)
			output = -1;	
		if (ft_strncmp(format->flag, "", 5) == 0)
			output = -1;	
	}
	if (output == -1)
	{
		ft_putchar(c);
		return (1);
	}
	output_str = (char *)ft_calloc(2, sizeof(char));
	output_str[0] = c;
	output = ft_printer_str(format, output_str);
	free(output_str);
	return (output);
}

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

int		ft_hex_conv(va_list ap, t_format *format)
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

int		ft_num_conv(va_list ap, t_format *format)
{
	int			ret;
	char		*str_buffer;
	int			int_buffer;

	ret = 0;
	int_buffer = va_arg(ap, int);
	if (format->conv == 'u' && int_buffer < 0)
		int_buffer = int_buffer * -1;
	str_buffer = ft_itoa(int_buffer);
	ret = ft_printer_nbr(format, str_buffer);
	return (ret);
}

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
		ret = ft_printer_str(format, str_buffer);
	}
	return (ret);
}

int		ft_next_arg(va_list ap, t_format *format)
{
	int			ret;
	
	ret = 0;
	if (ft_char_set(format->conv, "sc%") != 0)
		ret = ft_alpha_conv(ap, format);
	else if (ft_char_set(format->conv, "diu") != 0)
		ret = ft_num_conv(ap, format);
	else if (ft_char_set(format->conv, "pxX") != 0)
		ret = ft_hex_conv(ap, format);
	free(format->flag);
//print_format(format);
	free(format);
	return(ret);
}

t_format	*ft_format_parser(va_list ap, const char *arg)
{
	int			y;
	t_format	*format;
	char		conv;

	y = 0;
	format = ft_format_init();
	if (format == NULL)
		return (NULL);
	while (arg[y] != '\0' && format->conv == 0)
	{
		if (y <= 5 && ft_char_set(arg[y], "-+'#0 ") != 0 &&
format->min_w == -1 && format->pre == -1)
			ft_fill_flag(format, arg[y]);
		else if (ft_char_set(arg[y], "0123456789*") != 0 &&
 format->min_w == -1 && format->pre == -1)
		{
			if (arg[y] != '*')
				format->min_w = ft_atoi(arg + y);
			else
				format->min_w = va_arg(ap, int);
		}
		else if (arg[y] == '.')
		{
			if (arg[y + 1] == '*')
				format->pre = va_arg(ap, int);
			else if (ft_isdigit(arg[y + 1]) == 1)
				format->pre = ft_atoi(arg + y + 1);
			else if (ft_isalpha(arg[y + 1]) == 1)
				format->pre = 0;
		}
		else if ((conv = ft_char_set(arg[y], "cspdiuxX%")) != 0)
			format->conv = conv;
		y++;
	}
	return (format);
}

int		ft_str_manager(va_list ap, const char *arg)
{
	int			ret;
	int			i;
	t_format	*format;

	i = 0;
	ret = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '%')
		{
			i++;
			format = ft_format_parser(ap, arg + i);
			if (format == NULL)
				return (0);
			ret += ft_next_arg(ap, format);
			while (arg[i] != '\0' && ft_char_set(arg[i], "cspdiuxX%") == 0)
				i++;
		}
		else
		{
			ft_putchar(arg[i]);
			ret++;
		}
		i++;
	}
	return (ret);
}

int				ft_printf(const char *arg, ...)
{
	int 		ret;
	va_list 	ap;

	ret = 0;
	if (arg == NULL)
		return (0);
	if (ft_strchr(arg, '%') == NULL)
	{
		ft_putstr((char *)arg);
		return(ft_strlen(arg));
	}
	va_start(ap, arg);
	ret = ft_str_manager(ap, arg);
	va_end(ap);
	return (ret);
}

