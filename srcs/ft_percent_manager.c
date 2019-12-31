/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:45:58 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/31 10:14:54 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

/*
** alpha manager is called if format conv is a 's' 'c' or '%'
*/

int		ft_percent_conv(t_format *format)
{
	int			ret;

	ret = 1;
	if (format->pre == -1 && format->min_w == -1)
		ft_putchar('%');
	else
		ret = ft_printer_char(format, '%');
//print_format(format);
	return (ret);
}


