/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:51:42 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/25 11:54:56 by bvalette         ###   ########.fr       */
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
#include "libft.h"
#include "libftprintf.h"

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void	basic_test_01_char(void)
{
	int		multi_arg[4] =
	{
		'a',
		'A',
		' ',
		2,
	};
	char 	multi_test[23][100] =
	{	"[%c] \n",
		"[%5.30c] \n",
		"[%-5.30c] \n",
		"[%15c] \n",
		"[%0-15c] \n",
		"[%.0c] \n",
		"[%15c] \n",
		"[%15.0c] \n",
		"[%15.1c] \n",
		"[%15.10c] \n",
		"[%-15.0c] \n",
		"[%-15.1c] \n",
		"[%-+18.10c] \n",
		"[%- 18.10c] \n",
		"[%+-18.10c] \n",
		"[% +18.10c] \n",
		"[% -18.10c] \n",
		"[%+.0c] \n",
		"[%-.0c] \n",
		"[% .0c] \n",
		"[%+ .0c] \n",
		"[%- .0c] \n",
		"[% 15.0c] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 4)
	{
		printf("\n\n-------------------------------------->>[%c]\n", multi_arg[y]);	
		while (i < 23)
		{
		ret_c = 0;
		ret_ft = 0;

			printf("STRING >>>>>>>>>>>>>>>>>>>>{test %d}{%c}>>>> %s", i, multi_arg[y], multi_test[i]);
			ret_c = printf(multi_test[i], multi_arg[y]);
			ret_ft = ft_printf(multi_test[i], multi_arg[y]);
			printf("\n");
			diff_ret = ret_c - ret_ft;
			if (diff_ret != 0)
			{
				printf("\033[0;31m");
				printf(" [ko] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
					delay(400);
			}
			else
			{
				printf("\033[0;32m");
				printf(" [OK] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
			}

			i++;
		}
	i = 0;
	y++;
	}
	printf("\n\n=============  FIN MAIN  =================\n\n\n");
			
}

void	basic_test_01_int(void)
{
	int		multi_arg[6] =
	{	42,
		9,
		0,
		-42,
		12312142,
		-89898989,
	};
	char 	multi_test[25][100] =
	{	"[%d] \n",
		"[%.d] \n",
		"[%5.30d] \n",
		"[%-5.30d] \n",
		"[%15d] \n",
		"[%0-15d] \n",
		"[%.0d] \n",
		"[%15d] \n",
		"[%15.0d] \n",
		"[%15.1d] \n",
		"[%15.10d] \n",
		"[%-15.0d] \n",
		"[%-15.1d] \n",
		"[%-+18.10d] \n",
		"[%- 18.10d] \n",
		"[%+-18.10d] \n",
		"[% +18.10d] \n",
		"[% -18.10d] \n",
		"[%+.0d] \n",
		"[%-.0d] \n",
		"[% .0d] \n",
		"[%+ .0d] \n",
		"[%8.8d] \n",
		"[%8d] \n",
		"[%08d] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 4)
	{
		printf("\n\n-------------------------------------->>[%d]\n", multi_arg[y]);	
		while (i < 25)
		{
		ret_c = 0;
		ret_ft = 0;

			printf("STRING >>>>>>>>>>>>>>>>>>>>{test %d}{%d}>>>> %s", i, multi_arg[y], multi_test[i]);
			ret_c = printf(multi_test[i], multi_arg[y]);
			ret_ft = ft_printf(multi_test[i], multi_arg[y]);
			printf("\n");
			diff_ret = ret_c - ret_ft;
			if (diff_ret != 0)
			{
				printf("\033[0;31m");
				printf(" [ko] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
				delay(400);
			}
			else
			{
				printf("\033[0;32m");
				printf(" [OK] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
			}

			i++;
		}
	i = 0;
	y++;
	}
	printf("\n\n=============  FIN MAIN  =================\n\n\n");
}

void	basic_test_01_string(void)
{

/*
** ============================ MULTI FLAGS TEST UNIT - for str only
*/
	char	multi_arg[5][50] =
	{	"coucou",
		"abcdefghijklmnopqrstuvwxyz",
		"a",
		"",
		" ",
	};
	char 	multi_test[23][100] =
	{	"[%s] \n",
		"[%5.30s] \n",
		"[%-5.30s] \n",
		"[%15s] \n",
		"[%0-15s] \n",
		"[%.0s] \n",
		"[%15s] \n",
		"[%15.0s] \n",
		"[%15.1s] \n",
		"[%15.10s] \n",
		"[%-15.0s] \n",
		"[%-15.1s] \n",
		"[%-+18.10s] \n",
		"[%- 18.10s] \n",
		"[%+-18.10s] \n",
		"[% +18.10s] \n",
		"[% -18.10s] \n",
		"[%+.0s] \n",
		"[%-.0s] \n",
		"[% .0s] \n",
		"[%+ .0s] \n",
		"[%- .0s] \n",
		"[% 15.0s] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 5)
	{
		printf("\n\n-------------------------------------->>[%s]\n", multi_arg[y]);	
		while (i < 23)
		{
		ret_c = 0;
		ret_ft = 0;

			printf("STRING >>>>>>>>>>>>>>>>>>>>{test %d}{%s}>>>> %s", i, multi_arg[y], multi_test[i]);
			ret_c = printf(multi_test[i], multi_arg[y]);
			ret_ft = ft_printf(multi_test[i], multi_arg[y]);
			printf("\n");
			diff_ret = ret_c - ret_ft;
			if (diff_ret != 0)
			{
				printf("\033[0;31m");
				printf(" [ko] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
				delay(400);
			}
			else
			{
				printf("\033[0;32m");
				printf(" [OK] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
			}

			i++;
		}
	i = 0;
	y++;
	}
	printf("\n\n=============  FIN MAIN  =================\n\n\n");


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

	
	printf("\n\t===============\n");
	printf("\t=  TEST FLAG  =\n");
	printf("\t===============\n");
	printf(" printf_lic  \n ft_printf\n\n");	

/* --------- vars for tester
*/


	int		i = 0;
	int		arg_int = 42424242;
	char	arg_char = 'K';
	int		arg_hexa = -42;
	char 	*arg_string = "Hello World!";
	

/*
** ============================ MULTI FLAGS TEST UNIT - for hexadecinals only
*/
	char multi_test_hexa[10][50] =
	{	"[%x] \n",
		"[%-x] \n",
		"[%+x] \n",
		"[%#x] \n",
		"[%0x] \n",
		"[%10.5x] \n",
		"[%-10.5x] \n",
		"[%'10.5x] \n",
		"[%#10.5x] \n",
		"[%010.5x] \n",
	};
	i = 0;
	while (i < 10)
	{
		printf("hexa>>>>>>>>>>>>>>>>>>>>>>>>>>>> %s", multi_test_hexa[i]);	
		printf(multi_test_hexa[i], arg_hexa);
		ft_printf(multi_test_hexa[i], arg_hexa);
		printf("\n");
		i++;
	}


/*
** ============================ MULTI FLAGS TEST UNIT - for int only
*/
	char multi_test_int[10][50] =
	{	"[%d] \n",
		"[%-d] \n",
		"[%'d] \n",
		"[%#d] \n",
		"[%0d] \n",
		"[%10.5d] \n",
		"[%-10.5d] \n",
		"[%'10.5d] \n",
		"[%#10.5d] \n",
		"[%010.5d] \n",
	};
	i = 0;
	while (i < 10)
	{
		printf("INT>>>>>>>>>>>>>>>>>>>>>>>>>>>> %s", multi_test_int[i]);	
		printf(multi_test_int[i], arg_int);
		ft_printf(multi_test_int[i], arg_int);
		printf("\n");
		i++;
	}


/*
** ============================ MULTI FLAGS TEST UNIT - for pointer only
*/
	
	char multi_test_pointer[10][50] =
	{	"[%p] \n",
		"[%-p] \n",
		"[%'p] \n",
		"[%#p] \n",
		"[%0p] \n",
		"[%60.50p] \n",
		"[%-60.50p] \n",
		"[%'60.50p] \n",
		"[%#60.50p] \n",
		"[%060.50p] \n",
	};
	i = 0;
	while (i < 10)
	{
		printf("POINTER>>>>>>>>>>>>>>>>>>>>>>>> %s", multi_test_pointer[i]);	
		printf(multi_test_pointer[i], &arg_int);
		ft_printf(multi_test_pointer[i], &arg_int);
		printf("\n");
		i++;
	}


/*
** ============================ MULTI FLAGS TEST UNIT - for char only
*/
	
	char multi_test_char[10][50] =
	{	"[%-c] \n",
		"[%+c] \n",
		"[%'c] \n",
		"[%#c] \n",
		"[%0c] \n",
		"[%-10.5c] \n",
		"[%+10.5c] \n",
		"[%'10.5c] \n",
		"[%#10.5c] \n",
		"[%010.5c] \n",
	};
	i = 0;
	while (i < 10)
	{
		printf("CHAR >>>>>>>>>>>>>>>>>>>>>>>> %s", multi_test_char[i]);	
		printf(multi_test_char[i], arg_char);
		ft_printf(multi_test_char[i], arg_char);
		printf("\n");
		i++;
	}


/*
** ============================ MULTI FLAGS TEST UNIT - for str only
*/
	
	char multi_test_string[10][50] =
	{	"[%s] \n",
		"[%-s] \n",
		"[%'s] \n",
		"[%#s] \n",
		"[%0s] \n",
		"[%10.5s] \n",
		"[%-10.5s] \n",
		"[%'10.5s] \n",
		"[%#10.5s] \n",
		"[%010.5s] \n",
	};
	i = 0;
	while (i < 10)
	{
		printf("STRING >>>>>>>>>>>>>>>>>>>>>>>> %s", multi_test_string[i]);	
		printf(multi_test_string[i], arg_string);
		ft_printf(multi_test_string[i], arg_string);
		printf("\n");
		i++;
	}

	printf("\n=============  FIN  =================\n");

}

void basic_test_wildcard()
{
	printf("test libc = [%10.*s]\n", 15, "hello");
	ft_printf("test      = [%10.*s]\n", 15, "hello");
	printf("test libc = [%*.10s]\n", 20, "hello");
	ft_printf("test      = [%*.10s]\n", 20, "hello");
	printf("test libc = [%*.*s]\n", 15, 2, "hello");
	ft_printf("test      = [%*.*s]\n", 15, 2, "hello");
}

int	main(void)
{
	time_t t;
    time(&t);
	
	printf("\n================ [START] =================\n");
	printf("\t%s", ctime(&t));
	
//	basic_test_01_string();
//	basic_test_01_char();
	basic_test_01_int();
//	basic_test_02();
//	basic_test_flags_03();
//	basic_test_wildcard();


//	system("leaks a.out");	


	return(0);	

}
