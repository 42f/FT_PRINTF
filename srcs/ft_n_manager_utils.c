/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_manager_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:26:14 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/15 08:43:37 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	ft_n_int(va_list ap, int ret)
{
	int				*ptr_int;
	
	ptr_int = va_arg(ap, int *);
	if (ptr_int == NULL)
		return ;
	*ptr_int = ret;
}

void	ft_n_lint(va_list ap, int ret)
{

	long int		*ptr_lint;

	ptr_lint = va_arg(ap, long int*);
	if (ptr_lint == NULL)
		return ;
	*ptr_lint = (long int)ret;
}

void	ft_n_llint(va_list ap, int ret)
{

	long long int	*ptr_llint;

	ptr_llint = va_arg(ap, long long int*);
	if (ptr_llint == NULL)
		return ;
	*ptr_llint = (long long int)ret;
}

void	ft_n_hint(va_list ap, int ret)
{

	short int		*ptr_h;

	ptr_h = va_arg(ap, short int*);
	if (ptr_h == NULL)
		return ;
	*ptr_h = (short int)ret;
}

void	ft_n_hhint(va_list ap, int ret)
{

	signed char		*ptr_hh;

	ptr_hh = va_arg(ap, signed char*);
	if (ptr_hh == NULL)
		return ;
	*ptr_hh = (signed char)ret;
}

