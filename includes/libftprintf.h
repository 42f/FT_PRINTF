/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:44:34 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 07:44:46 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <wchar.h>

int				g_error;
typedef	struct	s_format
{
	char	flag[6];
	int 	min_w;
	int		pre;
	char	spec[3];
	char	conv;
}				t_format;

void		ft_n_int(va_list ap, int ret);
void		ft_n_lint(va_list ap, int ret);
void		ft_n_llint(va_list ap, int ret);
void		ft_n_hint(va_list ap, int ret);
void		ft_n_hhint(va_list ap, int ret);
int			ft_check_va(va_list ap);
void		ft_spec_parser(char *arg, t_format *format);
void		ft_conv_parser(char *arg, t_format *format);
void		ft_flag_parser(char *arg, t_format *format);
void		ft_wildcard_arg(va_list ap, t_format *format, int type);
char		*ft_x_pre_padding(t_format *format, char *hex_str);
char		*ft_p_pre_padding(t_format *format, char *hex_str);
void		ft_str_toupper(char *str);
char		ft_set_cfill(t_format *format);
void		ft_n_conv(va_list ap, int ret, t_format *format);
int			ft_unsigned_conv(va_list ap, t_format *format);
char		*ft_itoa_base(long long int n, char *base);
char		*ft_itoa_base_ptr(uintptr_t n, char *base);
int			ft_printf(const char *arg, ...);
char		ft_char_set(char c, char *set);
char		*ft_str_set(char* str, char *set);
int			ft_alpha_conv(va_list ap, t_format *format);
int			ft_percent_conv(t_format *format);
int			ft_hex_conv(va_list ap, t_format *format);
int			ft_num_conv(va_list ap, t_format *format);
int			ft_printer_char(t_format *format, wchar_t c);
int			ft_printer_str(t_format *format, char *str_buffer);
t_format	*ft_format_init(void);
void		ft_fill_spec(t_format *format, char c);
void		ft_fill_flag(t_format *format, char c);

#endif
