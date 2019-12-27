/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:51:42 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/27 18:33:12 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<time.h>
#include <stdlib.h>
#include <stdio.h>
/*
void *xmalloc(size_t size)
 {
	static int fail_after = 12;
	static int alloc_number = 0;

	if (fail_after > 0 && alloc_number >= fail_after)
 	{
 		alloc_number++;
 		printf("MALLOC FAIL @ the malloc number = [%d]\n", alloc_number);
 		return NULL;
 	}
 	alloc_number++;

 	return malloc(size);
 }
 #define malloc(y) xmalloc(y)
*/
#include "libftprintf.h"

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds); 
}
 
#include"basic_mixed_int.c"
#include"basic_test_01_char.c"
#include"basic_test_01_hex.c"
#include"basic_test_01_int.c"
#include"basic_test_01_u.c"
#include"basic_test_01_mixed_int.c"
#include"basic_test_01_pointer.c"
#include"basic_test_small_mix.c"




void basic_test_wildcard()
{
	printf("test libc = [%10.*s]\n", 15, "hello");
	ft_printf("test      = [%10.*s]\n", 15, "hello");
	printf("test libc = [%*.10s]\n", 20, "hello");
	ft_printf("test      = [%*.10s]\n", 20, "hello");
	printf("test libc = [%*.*s]\n", 15, 2, "hello");
	ft_printf("test      = [%*.*s]\n", 15, 2, "hello");
}

void sandbox()
{
	int c = 39;
	printf(" libc %u\n",c);
	ft_printf(" FT %u\n",c);

	printf(" libc %u\n",c);
	ft_printf(" FT %u\n\n\n\n",c);

	c = 42;
	printf("    %u\n",c);
	ft_printf(" FT %u\n\n\n\n",c);
	c = 0;
	printf("    %u\n",c);
	ft_printf(" FT %u\n\n\n\n",c);
	c = -7;
	printf("    %.u\n",c);
	ft_printf(" FT %.u\n\n\n\n",c);
	c = -421231;
	printf("    %u\n",c);
	ft_printf(" FT %u\n\n\n\n",c);
	c = -42547879;
	printf("    %u\n",c);
	ft_printf(" FT %u\n\n\n\n",c);
	
}

int	main(void)
{
	time_t t;
    time(&t);
	
	printf("\n================ [START] =================\n");
	printf("\t%s", ctime(&t));
	
//	basic_test_01_char();
//	basic_test_01_hex();
//	basic_test_01_int();
	basic_test_01_u();
//	basic_test_01_mixed_int();
//	basic_test_01_pointer();
//	basic_test_01_string();
//	basic_test_wildcard();
//	basic_mixed_int();
//	sandbox();
//	basic_test_small_mix();
//	system("leaks a.out");	

/*
	int test = -4422;
	printf("f[%05f] \n", test);
	printf("g[%05g] \n", test);
	printf("e[%05e] \n", test);
	printf("d[%0d] \n", test);
	ft_printf("[%05d] \n", &test);
	printf("i[%05p] \n", test);
	ft_printf("[%05p] \n", &test);
*/
	return(0);	

}

