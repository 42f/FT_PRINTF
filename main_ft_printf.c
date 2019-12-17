/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:36:25 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/17 18:02:19 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<time.h>


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

	ft_printf("%10.0s", "hello");
	ft_printf("*************************\n");
	ft_printf("%10.1s", "hello");
	ft_printf("*************************\n");
	ft_printf("%10.3s", "hello");
	ft_printf("*************************\n");
	ft_printf("%10.4s", "hello");
	ft_printf("*************************\n");

	ft_printf("%-10.0s", "hello");
	ft_printf("*************************\n");
	ft_printf("%-10.1s", "hello");
	ft_printf("*************************\n");
	ft_printf("%-10.3s", "hello");
	ft_printf("*************************\n");
	ft_printf("%-10.4s", "hello");
	ft_printf("*************************\n");
				
	ret_1 = ft_printf("test\n");
	ft_printf("%d\n", ret_0);

	ft_printf("\n\n=============  FIN  =================\n");
}


void		basic_test_02(void)
{

	int *p;
	int n = 6;

	p = &n;
	
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");

	printf("test %c\n", 'Y');	
	printf("test %s\n", "hello");	
	printf("test %d\n", 42);	
	printf("test %d\n", -42);	
	printf("test %%\n");	
	printf("test %c | %s\n", 'Y', "coucou libc");	

	printf("POINTER p = {%p}\n", p);
	printf("POINTER p = {%p}\n", &n);

	
	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");


	ft_printf("test %c\n", 'Y');	
	ft_printf("test %s\n", "hello");	
	ft_printf("test %d\n", 42);	
	ft_printf("test %d\n", -42);	
	ft_printf("test %%\n");	
	ft_printf("test %c | %s\n", 'Y', "coucou FT");	

	ft_printf("POINTER p = {%p}\n", p);
	ft_printf("POINTER p = {%p}\n", &n);

	printf("\n\n=============  FIN  =================\n");
}

void		basic_test_flags_03(void)
{

	int *p;
	int n = 6;

	p = &n;
	
	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("=  TEST FLAG  =\n");
	printf("===============\n\n");


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%-10.20d\n");	
	ft_printf("test %-10.20d\n", 42);	


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%-10d\n");	
	ft_printf("test %-10d\n", 42);	


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%-.20d\n");	
	ft_printf("test %-.20d\n", 42);	


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%-010.20d\n");	
	ft_printf("test %-010.20d\n", 42);	


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%-#10.20d\n");	
	ft_printf("test %-#10.20d\n", 42);	


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%+10.20d\n");	
	ft_printf("test %+10.20d\n", 42);	


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%-010.20d\n");	
	ft_printf("test %-010.20d\n", 42);	


	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> %%- 10.20d\n");	
	ft_printf("test %- 10.20d\n", 42);	

	printf("\n\n=============  FIN  =================\n");
}


int	main(void)
{
	time_t t;
    time(&t);
	
	int *p;
	int n = 6;

	p = &n;

	printf("\n================ [START] =================\n");
	printf("\t%s", ctime(&t));

//	basic_test_01();
//	basic_test_02();
	basic_test_flags_03();


	//ft_printf("{test 01} %45623d\n{test 02} %-4000002.0010i\n\t\t ===========FIN\n", -42, -42);	

	return(0);	

}
