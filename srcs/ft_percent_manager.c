/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:45:58 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/15 08:45:19 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

int		ft_percent_conv(t_format *format)
{
	int			ret;

	ret = 1;
		
	if (format->pre == -1 && format->min_w == -1)
		ft_putchar('%');
	else
		ret = ft_printer_char(format, '%');
	return (ret);
}


