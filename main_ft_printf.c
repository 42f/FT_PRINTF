/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:36:25 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/16 11:29:19 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"

void	basic_test_01(void)
{
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");
	
	int	ret_0 = 0;

	printf("%10.0s", "hello");
	printf("*************************\n");
	printf("%10.1s", "hello");
	printf("*************************\n");
	printf("%10.3s", "hello");
	printf("*************************\n");
	printf("%10.4s", "hello");
	printf("*************************\n");

	printf("%-10.0s", "hello");
	printf("*************************\n");
	printf("%-10.1s", "hello");
	printf("*************************\n");
	printf("%-10.3s", "hello");
	printf("*************************\n");
	printf("%-10.4s", "hello");
	printf("*************************\n");
				
	ret_0 = printf("test\n");
	printf("%d\n", ret_0);

	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");
	
	int ret_1 = 0;

	ret_1 = ft_printf("test\n");
	printf("%d\n", ret_1);
	
	printf("\n\n=============  FIN  =================\n");
}


void		basic_test_02(void)
{

//	basic_test_01();
	
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");

	printf("test %c\n", 'Y');	
	printf("test %s\n", "hello");	
	printf("test %d\n", 42);	
	printf("test %d\n", -42);	
	printf("test %%\n");	
	printf("test %c | %s\n", 'Y', "coucou");	
	
	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");


	ft_printf("test %c\n", 'Y');	
	ft_printf("test %s\n", "hello");	
	ft_printf("test %d\n", 42);	
	ft_printf("test %d\n", -42);	
	ft_printf("test %%\n");	
	ft_printf("test %c | %s\n", 'Y', "coucou");	

	printf("\n\n=============  FIN  =================\n");
}


int	main(void)
{

//	basic_test_01();
	basic_test_02();
	
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");


	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");



	printf("\n\n=============  FIN  =================\n");
	return(0);	

}
