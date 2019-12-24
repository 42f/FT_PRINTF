/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:44:34 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/24 15:57:42 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft.h"
#include <stdarg.h> 
#include <stdio.h> 

typedef	struct	s_format
{
	char	*flag;
	int 	min_w;
	int		pre;
	char	conv;
	
}				t_format;

int			ft_printf(const char *arg, ...);
char		*ft_zero_padding(t_format *format, char *str_buffer, int nb);
char		ft_char_set(char c, char *set);
char		ft_str_set(char* str, char *set);
int			ft_alpha_conv(va_list ap, t_format *format);
int			ft_hex_conv(va_list ap, t_format *format);
int			ft_next_arg(va_list ap, t_format *format);
int			ft_num_conv(va_list ap, t_format *format);
int			ft_printer_char(t_format *format, unsigned char c);
int			ft_printer_nbr(t_format *format, char *str_buffer);
int			ft_printer_str(t_format *format, char *str_buffer);;
int			ft_putnum(t_format *format, char *padded_buff, char *output_str);
int			ft_str_manager(va_list ap, const char *arg);
t_format	*ft_format_init(void);
t_format	*ft_format_parser(va_list ap, const char *arg);
void		ft_fill_flag(t_format *format, char c);

#endif
