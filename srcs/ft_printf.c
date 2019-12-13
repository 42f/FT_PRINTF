/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/13 14:42:55 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(const char *first_arg, ...)
{
	int 	ret;
	va_list ap;
	char 	*next_arg;

	ret = 0;
	va_start(ap, first_arg);
	printf("%s\n", first_arg);
	next_arg = va_arg(ap, char *);
	printf("%s\n", next_arg);

//	ft_putstr_fd(first_arg, 1);
	va_end(ap);
	return (0);
}

