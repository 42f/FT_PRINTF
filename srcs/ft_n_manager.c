/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:26:14 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 13:47:17 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>

void	ft_n_conv(va_list ap, int ret, t_format *format)
{
	if (ft_strncmp(format->spec, "hh", 2) == 0)
		ft_n_hhint(ap, ret);
	else if (ft_strncmp(format->spec, "h", 1) == 0)
		ft_n_hint(ap, ret);
	else if (ft_strncmp(format->spec, "ll", 2) == 0)
		ft_n_llint(ap, ret);
	else if (ft_strncmp(format->spec, "l", 1) == 0)
		ft_n_lint(ap, ret);
	else
		ft_n_int(ap, ret);
}
