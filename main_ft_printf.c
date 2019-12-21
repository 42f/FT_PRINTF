/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:51:42 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/21 17:02:00 by bvalette         ###   ########.fr       */
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
//	freopen("log_libC.txt","w",stdout);

	printf("%1c", 'H');
	printf("***.***.***\n");
	printf("%10c", 'H');
	printf("***.***.***\n");
	printf("%15c", 'H');
	printf("***.***.***\n");
	printf("%50c", 'H');
	printf("***.***.***\n");

	printf("%-1c", 'H');
	printf("***.***.***\n");
	printf("%-10c", 'H');
	printf("***.***.***\n");
	printf("%-15c", 'H');
	printf("***.***.***\n");
	printf("%-50c", 'H');
	printf("***.***.***\n");
	
//	fclose(stdout);	
				
	printf("\n\n===============\n");
	printf("=  ft_printf  =\n");
	printf("===============\n\n");
	
//	freopen("log_libFT.txt","w",stdout);

	ft_printf("%1c", 'H');
	ft_printf("***.***.***\n");
	ft_printf("%10c", 'H');
	ft_printf("***.***.***\n");
	ft_printf("%15c", 'H');
	ft_printf("***.***.***\n");
	ft_printf("%50c", 'H');
	ft_printf("***.***.***\n");

	ft_printf("%-1c", 'H');
	ft_printf("***.***.***\n");
	ft_printf("%-10c", 'H');
	ft_printf("***.***.***\n");
	ft_printf("%-15c", 'H');
	ft_printf("***.***.***\n");
	ft_printf("%-50c", 'H');
	ft_printf("***.***.***\n");
	
//	fclose(stdout);	
				
	ft_printf("\n\n=============  FIN  =================\n");
}

void	basic_test_01_int(void)
{

/*
** ============================ MULTI FLAGS TEST UNIT - for str only
*/
	int		multi_arg[6] =
	{	42,
		9,
		0,
		-42,
		12312142,
		-89898989,
	};
	char 	multi_test[14][50] =
	{	"[%d] \n",
		"[%15d] \n",
		"[%0-15d] \n",
		"[%.0d] \n",
		"[%15d] \n",
		"[%15.0d] \n",
		"[%15.1d] \n",
		"[%15.10d] \n",
		"[%-15.0d] \n",
		"[%-15.1d] \n",
		"[%-15.10d] \n",
		"[%.0d] \n",
		"[%-5.30d] \n",
		"[%5.30d] \n",
	};
	int 	i = 0;
	int		y = 0;

	while (y < 6)
	{
			printf("\n\n-------------------------------------->>[%d]\n", multi_arg[y]);	
		while (i < 14)
		{
			printf("STRING >>>>>>>>>>>>>>>>>>>>>>>> %s", multi_test[i]);
			printf(multi_test[i], multi_arg[y]);
			ft_printf(multi_test[i], multi_arg[y]);
			printf("\n");
			i++;
		}
	i = 0;
	y++;
	}
	ft_printf("\n\n=============  FIN  =================\n");
}

void	basic_test_01_string(void)
{

/*
** ============================ MULTI FLAGS TEST UNIT - for str only
*/
	char	multi_arg_str[5][50] =
	{	"coucou",
		"abcdefghijklmnopqrstuvwxyz",
		"a",
		"",
		" ",
	};
	char 	multi_test_string[14][50] =
	{	"[%s] \n",
		"[%10s] \n",
		"[%-10s] \n",
		"[%.0s] \n",
		"[%10s] \n",
		"[%10.0s] \n",
		"[%10.1s] \n",
		"[%10.2s] \n",
		"[%-10.0s] \n",
		"[%-10.1s] \n",
		"[%-10.2s] \n",
		"[%.0s] \n",
		"[%-5.30s] \n",
		"[%5.30s] \n",
	};
	int 	i = 0;
	int		y = 0;

	while (y < 5)
	{
			printf("------------------------------>>[%s]\n", multi_arg_str[y]);	
		while (i < 14)
		{
			printf("STRING >>>>>>>>>>>>>>>>>>>>>>>> %s", multi_test_string[i]);	
			printf(multi_test_string[i], multi_arg_str[y]);
			ft_printf(multi_test_string[i], multi_arg_str[y]);
			printf("\n");
			i++;
		}
	i = 0;
	y++;
	}
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
//	basic_test_01_string();
	basic_test_01_int();
//	basic_test_02();
//	basic_test_flags_03();
//	basic_test_wildcard();
	

	return(0);	

}
