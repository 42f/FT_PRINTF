/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:44:34 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/18 16:11:23 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <libft.h>
#include <stdarg.h> 
#include <stdio.h> 

// REMOVE
/*
[flag][min width][precision][length modifier][conversion specifier]
flags 
 -      Left justify.
 0  	  Field is padded with 0's instead of blanks.

*/

typedef	struct	s_format
{
	char	*flag;
	int 	min_width;
	int		precision;
	char	converter;
	
}				t_format;


int		ft_printf(const char *, ...);

#endif
