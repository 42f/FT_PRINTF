/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:51:42 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/27 11:03:41 by bvalette         ###   ########.fr       */
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
		"[% +18.10c] \n",
		"[% -18.10c] \n",
		"[%+.0c] \n",
		"[%-.0c] \n",
		"[% .0c] \n",
		"[%+ .0c] \n",
		"[% -0+15.0c] \n",
		"[%+-0 15.0c] \n",
		"[%d.0c] \n",
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
	{
		12312142,
		-89898989,
		42,
		9,
		0,
		-42,

	};
	char 	multi_test[25][100] =
	{	"[%d] \n",
		"[%.d] \n",
		"[%5.30d] \n",
		"[%-5.30d] \n",
		"[%15d] \n",
		"[%.d] \n",
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
		"[%-.0d] \n",
		"[%-0 .0d] \n",
		"[%+- .0d] \n",
		"[%8.8i] \n",
		"[%08i] \n",
		"[%0-15d] \n",
		"[%08d] \n",
		"[%0d] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 6)
	{
		printf("\n\n-------------------------------------------------------------->>[%d]\n", multi_arg[y]);	
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
		"[%+.s] \n",
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
	
	basic_test_01_string();
	basic_test_01_char();
	basic_test_01_int();
//	mixed_test_01_string();
//	basic_test_02();
//	basic_test_flags_03();
//	basic_test_wildcard();
char c=125;
c+=10;
printf("%d\n",c); //outputs  -121 which is understood.
ft_printf(" FT %d\n",c); //outputs  -121 which is understood.
printf("%u\n",c); // outputs 4294967175.
ft_printf(" FT %u\n",c); // outputs 4294967175.
//	system("leaks a.out");	
    printf("test atoi = %i\n", ft_atoi("2147483648"));   // UB: out of range of int


	return(0);	

}
