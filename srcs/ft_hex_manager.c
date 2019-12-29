/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:46:56 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/28 13:52:12 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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


