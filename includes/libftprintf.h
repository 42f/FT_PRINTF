/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:44:34 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/27 18:00:49 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h> 
#include <stdio.h> 

typedef	struct	s_format
{
	char	*flag;
	int 	min_w;
	int		pre;
	char	conv;
	
}				t_format;

// TO REMOVE
void	print_format(t_format *format);
//TO REMOVE


int			ft_unsigned_conv(va_list ap, t_format *format);
char		*ft_itoa_base(long long int n, char *base);
int			ft_printf(const char *arg, ...);
//void		ft_padder(int pre, int len, int offset, char *padded, char *buffer);
//char		*ft_pre_padding(t_format *format, char *str_buffer, int nb);
//char		*ft_zero_padding(t_format *format, char *buffer, int nb, int pre);
char		ft_char_set(char c, char *set);
char		ft_str_set(char* str, char *set);
int			ft_alpha_conv(va_list ap, t_format *format);
int			ft_hex_conv(va_list ap, t_format *format);
int			ft_next_arg(va_list ap, t_format *format);
int			ft_num_conv(va_list ap, t_format *format);
int			ft_printer_char(t_format *format, unsigned char c);
//int			ft_printer_nbr(t_format *format, char *str_buffer, int nb);
int			ft_printer_str(t_format *format, char *str_buffer);;
//int			ft_putnum(t_format *format, char *padded_buff, char *output_str);
int			ft_str_manager(va_list ap, const char *arg);
t_format	*ft_format_init(void);
t_format	*ft_format_parser(va_list ap, const char *arg);
void		ft_fill_flag(t_format *format, char c);

/*
**  MEMORIES FUNCTIONS
*/

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);

/*
**  CHAR FUNCTIONS
*/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*
**  STRINGS FUNCTIONS
*/

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);

/*
**  EXTA FUNCTIONS
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				ft_putchar(char c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(long long int nbr, char *base);

#endif
