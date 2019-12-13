/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:36:25 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/13 14:43:02 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"

int	main(void)
{
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");

	printf("test");

	

	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");

	ft_printf("coucou ft_printf", "second_arg");
	
	printf("\n\n=============  FIN  =================\n");
	return (0);
}
