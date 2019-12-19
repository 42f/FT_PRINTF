/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:36:25 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/19 12:59:26 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<time.h>
#include <stdlib.h>

#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"

void	basic_test_01_char(void)
{
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");
	
	int	ret_0 = 0;

	printf("%1c", 'H');
	printf("*************************\n");
	printf("%10c", 'H');
	printf("*************************\n");
	printf("%15c", 'H');
	printf("*************************\n");
	printf("%50c", 'H');
	printf("*************************\n");

	printf("%-1c", 'H');
	printf("*************************\n");
	printf("%-10c", 'H');
	printf("*************************\n");
	printf("%-15c", 'H');
	printf("*************************\n");
	printf("%-50c", 'H');
	printf("*************************\n");
				
	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");
	

	ft_printf("%1c", 'H');
	ft_printf("*************************\n");
	ft_printf("%10c", 'H');
	ft_printf("*************************\n");
	ft_printf("%15c", 'H');
	ft_printf("*************************\n");
	ft_printf("%50c", 'H');
	ft_printf("*************************\n");

	ft_printf("%-1c", 'H');
	ft_printf("*************************\n");
	ft_printf("%-10c", 'H');
	ft_printf("*************************\n");
	ft_printf("%-15c", 'H');
	ft_printf("*************************\n");
	ft_printf("%-50c", 'H');
	ft_printf("*************************\n");
				
	ft_printf("\n\n=============  FIN  =================\n");
}

void	basic_test_01_string(void)
{
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");
	
	int		ret_0 = 0;
	char 	*test_str = "coucou";
	char	*output_libc[1024];
	
	freopen("log_libC.txt","w",stdout);

	printf("%s", test_str);
	printf("*************************[0.0]\n");
	printf("%10s", test_str);
	printf("*************************[0.1]\n");
	printf("%.0s", test_str);
	printf("*************************[0.2]\n");
	printf("%.1s", test_str);
	printf("*************************[0.3]\n");
	printf("%10.0s", test_str);
	printf("*************************[1]\n");
	printf("%10.1s", test_str);
	printf("*************************[2]\n");
	printf("%10.3s", test_str);
	printf("*************************[3]\n");
	printf("%10.4s", test_str);
	printf("*************************[4]\n");

	printf("%-10.0s", test_str);
	printf("*************************[5]\n");
	printf("%-10.1s", test_str);
	printf("*************************[6]\n");
	printf("%-10.3s", test_str);
	printf("*************************[7]\n");
	printf("%-10.4s", test_str);
	printf("*************************[8]\n");

	fclose(stdout);	

	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");
	
int ret_1 = 0;

	freopen("log_libFT.txt","w",stdout);

	ft_printf("%s", test_str);
	ft_printf("*************************[0.0]\n");
	ft_printf("%10s", test_str);
	ft_printf("*************************[0.1]\n");
	ft_printf("%.0s", test_str);
	ft_printf("*************************[0.2]\n");
	ft_printf("%.1s", test_str);
	ft_printf("*************************[0.3]\n");
	ft_printf("%10s", test_str);
	ft_printf("*************************[0]\n");
	ft_printf("%10.0s", test_str);
	ft_printf("*************************[1]\n");
	ft_printf("%10.1s", test_str);
	ft_printf("*************************[2]\n");
	ft_printf("%10.3s", test_str);
	ft_printf("*************************[3]\n");
	ft_printf("%10.4s", test_str);
	ft_printf("*************************[4]\n");

	ft_printf("%-10.0s", test_str);
	ft_printf("*************************[5]\n");
	ft_printf("%-10.1s", test_str);
	ft_printf("*************************[6]\n");
	ft_printf("%-10.3s", test_str);
	ft_printf("*************************[7]\n");
	ft_printf("%-10.4s", test_str);
	ft_printf("*************************[8]\n");

	fclose(stdout);
	
	ft_printf("\n\n=============  FIN  =================\n");
}

void	basic_test_01_int(void)
{

	int	ret_0 = 0;
	int n = 1;
	int i = 0;

while (i <= 4)
{
	printf("\n===============\n");
	printf("= PRINTF LIBC =\n");
	printf("===============\n\n");

	printf("%10.0d", n);
	printf("*************************\n");
	printf("%10.1d", n);
	printf("*************************\n");
	printf("%10.3d", n);
	printf("*************************\n");
	printf("%10.4d", n);
	printf("*************************\n");

	printf("%-10.0d", n);
	printf("*************************\n");
	printf("%-10.1d", n);
	printf("*************************\n");
	printf("%-10.3d", n);
	printf("*************************\n");
	printf("%-10.4d", n);
	printf("*************************\n");
				

	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");
	
	int ret_1 = 0;

	ft_printf("%10.0d", n);
	ft_printf("*************************\n");
	ft_printf("%10.1d", n);
	ft_printf("*************************\n");
	ft_printf("%10.3d", n);
	ft_printf("*************************\n");
	ft_printf("%10.4d", n);
	ft_printf("*************************\n");

	ft_printf("%-10.0d", n);
	ft_printf("*************************\n");
	ft_printf("%-10.1d", n);
	ft_printf("*************************\n");
	ft_printf("%-10.3d", n);
	ft_printf("*************************\n");
	ft_printf("%-10.4d", n);
	ft_printf("*************************\n");

	i++;
	n += 42;
}				

	printf("\n\nCAS PARTICULIER => int = 0 & precision .0\n"); 
	printf("test libc = [%.0d]\n", 0);
	printf("test libc = [%.0d]\n", 1);
	ft_printf("test ft   = [%.0d]\n", 0);
	ft_printf("test ft   = [%.0d]\n", 1);


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
	
	int *p;
	int n = 6;

	p = &n;

	printf("\n================ [START] =================\n");
	printf("\t%s", ctime(&t));

//	basic_test_01_char();
	basic_test_01_string();
//	basic_test_01_int();
//	basic_test_02();
//	basic_test_flags_03();
//	basic_test_wildcard();
	
	system ("colordiff log_libC.txt log_libFT.txt");	

	return(0);	

}
