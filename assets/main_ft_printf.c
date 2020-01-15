/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:51:42 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/15 09:53:09 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

//toremove
//
/*
void	print_format(t_format *format)
{
	if (format == NULL)
		return ;
	printf("\n\n========= FORMAT =========\n");
	printf("flag  = |%s|\n", format->flag);
	printf("min_w = |%d|\n", format->min_w);
	printf("pre   = |%d|\n", format->pre);
	printf("spec  = |%s|\n", format->spec);
	printf("conv  = |%c|\n", format->conv);
	//	system ("leaks a.out");
	printf("\n===== [END FORMAT] ======\n");

}
//
// REMOVE ABOVE


*/


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
/*    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds); 
*/
(void)number_of_seconds;
}

#include"basic_mixed_int.c"
#include"basic_test_01_char.c"
#include"basic_test_01_string.c"
#include"basic_test_01_hex.c"
#include"basic_test_01_xX.c"
#include"basic_test_01_int.c"
#include"basic_test_01_u.c"
#include"basic_test_01_mixed_int.c"
#include"basic_test_01_pointer.c"
#include"basic_test_small_mix.c"




void basic_test_wildcard()
{
	printf(   "test libc = [%.*s]\n", -10, "hello");
	ft_printf("test      = [%.*s]\n", -10, "hello");
	printf(   "test libc = [%*s]\n", -10, "hello");
	ft_printf("test      = [%*s]\n", -10, "hello");
	printf(   "test libc = [%*.*s]\n", 15, 2, "hello");
	ft_printf("test      = [%*.*s]\n", 15, 2, "hello");
	printf(   "test libc = [%05.*d]\n", -15, 42);
	ft_printf("test      = [%05.*d]\n", -15, 42);
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

void	basic_precentage()
{
	int returning = 0;
	int returning_libc = 0;
	printf("\n================ [precentage] =================\n");
	
	returning_libc = printf("{test 1 avec percent %%}\n");
	printf("returning = |%d|\n", returning_libc);
	returning = ft_printf("[test 1 avec percent %%]\n");
	printf("returning = |%d|\n", returning);
	returning_libc = printf("{test 2 avec percent %% chiffre %d}\n", 42);
	printf("returning = |%d|\n", returning_libc);
	returning = ft_printf("[test 2 avec percent %% chiffre %d]\n", 42);
	printf("returning = |%d|\n", returning);

	returning_libc = printf("{test 2  avec percent %%}\n");
	printf("returning = |%d|\n", returning_libc);
	returning = ft_printf("{test 2  avec percent %%}\n");
	printf("returning = |%d|\n", returning);
	returning_libc = printf("{test 2 avec percent %% chiffre %d}\n", 42);
	printf("returning = |%d|\n", returning_libc);
	returning = ft_printf("[test 2 avec percent %% chiffre %d]\n", 42);
	printf("returning = |%d|\n", returning);

	printf("\n=== [with min_width and precision] =====\n");

	returning_libc = printf("{minwidth 45 %45%}\n");
	printf("returning = |%d|\n", returning_libc);
	returning = ft_printf("[minwidth 45 %45%]\n");
	printf("returning = |%d|\n", returning);

	returning_libc = printf("{precision .5 %.5%}\n");
	printf("returning = |%d|\n", returning_libc);
	returning = ft_printf("[precision .5 %.5%]\n");
	printf("returning = |%d|\n", returning);

	returning_libc = printf("{min_w 10 precision .5 %10.5%}\n");
	printf("returning = |%d|\n", returning_libc);
	returning = ft_printf("[min_w 10 precision .5 %10.5%]\n");
	printf("returning = |%d|\n", returning);

	printf("\n================ [fin] =================\n");
}

void	basic_n_conv()
{	
	printf("\n================ [n_conv] =================\n");
	long long int ret1 = 0;
	long long int ret2 = 0;

	long long int p;
	long long int *a = &p;
	long long int *b = &p;
	ret1 = printf("{test n %lln- after}\n", a);
	ret2 = ft_printf("[test n %lln- after]\n", b);

	printf("{%lli}\n", *a);
	printf("[%lld]\n", *b);
	printf("{%lli}\n", ret1);
	printf("[%lld]\n", ret2);
}

void	special_char(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("\n================ [Special _ char] =================\n");

	
	ret1 = printf("{%-c}\n", (char)564);
	ret2 = ft_printf("[%-c]\n", (char)564);
	printf("\n\nc ={%i}\n", ret1);
	printf("f =[%d]\n", ret2);

}
void	special(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("\n================ [Special] =================\n");
	printf("ref = \n[%%====%%==tdti==]\n\n\n");

	
	   ret1 = printf(" titi % +---12.5% et%%%0004% et %+1% \n");
	ret2 = ft_printf("[titi % +---12.5% et%%%0004% et %+1%]\n");
	printf("\n\nc ={%i}\n", ret1);
	printf("f =[%d]\n", ret2);
	printf("\n================ [Special 2] =================\n");

	
	ret1 = ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	printf("\n");
	ret2 = ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	printf("\n");
	printf("\n\nc ={%i}\n", ret1);
	printf("f =[%d]\n", ret2);
}

void	error_managment()
{
	printf("\n================ [error managment] =================\n");

	int ret_123 = 0;
	int ret_2 = 0;

	   ret_123 = printf("{OK C %C %7s %s!!}\n", 0xd777, "str1", "coucou");	
	ret_2 = ft_printf("[OKft %C %7s %s!!]\n", 0xd777, "str1", "coucou");	

	printf("\n|c = %d / ft = %d|\n", ret_123, ret_2);
	printf("\n================ [end] =================\n");
}

void	null(void)
{
	printf("\n================ [null] =================\n");
	int ret1 = printf("{test %-12i et %--2.4s %24s !}\n", 0, NULL, "coco");
	int ret2 = ft_printf("[test %-12i et %--2.4s %24s !]\n", 0, NULL, "coco");

	printf("\n\nc ={%i}\n", ret1);
	printf("f =[%d]\n", ret2);

}
int	main(void)
{
//	time_t t;
  //  time(&t);
	
	printf("\n================ [START] =================\n");
//	printf("\t%s", ctime(&t));


/*	basic_test_01_xX();


	basic_test_01_u();
	basic_test_01_hex();

	basic_test_01_int();
	

	basic_test_01_mixed_int();
	basic_test_01_pointer();
	sandbox();
	basic_test_small_mix();
	system("leaks a.out");	
	basic_mixed_int();
	basic_n_conv();

	basic_test_01_char();
	basic_test_01_string();
	basic_precentage();
	special();
	special_char();
	null();
//	error_managment();
	system("leaks a.out");	
*/
	basic_test_wildcard();
	printf("\n================ [xtra] =================\n");
	
	printf("test libc = [%05.*d]\n", -15, 11111111);
ft_printf("test ft   = [%05.*d]\n", -15, 11111111);
	printf("test libc = [%05.*d]\n", -15, 42);
ft_printf("test ft   = [%05.*d]\n", -15, 42);
	printf("test libc = [%010.*d]\n", -15, 42);
ft_printf("test ft   = [%010.*d]\n", -15, 42);
	printf("test libc = [%10.*d]\n", -15, 11111111);
ft_printf("test ft   = [%10.*d]\n", -15, 11111111);
	printf("test libc = [%10.*d]\n", -15, 42);
ft_printf("test ft   = [%10.*d]\n", -15, 42);
	printf("test libc = [%010d]\n", 11111111);
ft_printf("test ft   = [%010d]\n", 11111111);
	printf("test libc = [%010d]\n", 42);
ft_printf("test ft   = [%010d]\n", 42);
	printf("test libc = [%10d]\n", 11111111);
ft_printf("test ft   = [%10d]\n", 11111111);
	printf("test libc = [%10d]\n", 42);
ft_printf("test ft   = [%10d]\n", 42);
	printf("test libc = [%05.*d]\n", -15, 11111111);
ft_printf("test ft   = [%05.*d]\n", -15, 11111111);
	printf("test libc = [%05.*d]\n", -15, 42);
ft_printf("test ft   = [%05.*d]\n", -15, 42);
	printf("test libc = [%05.3d]\n", 42);
ft_printf("test ft   = [%05.3d]\n", 42);

	printf("\n");
	printf("test libc = [%05.15d]\n", 111111);
ft_printf("test ft   = [%05.15d]\n", 111111);
	printf("test libc = [%010.15d]\n", 111111);
ft_printf("test ft   = [%010.15d]\n", 111111);
	printf("test libc = [%010d]\n", 111111);
ft_printf("test ft   = [%010d]\n", 111111);
	printf("test libc = [%-10d]\n", 111111);
ft_printf("test ft   = [%-10d]\n", 111111);



	
	
	printf("\n================ [end ] =================\n");

	return(0);	

}

