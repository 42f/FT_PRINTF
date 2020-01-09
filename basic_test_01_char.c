void	basic_test_01_char(void)
{
	int		multi_arg[5] =
	{
		'\0',
		' ',
		4562,
		'a',
		'x',
	};
	
	char 	multi_test[30][100] =
	{	
		"[%c .12]\n",
		"[%0c] \n",
		"[%+c] \n",
		"[%-c] \n",
		"[% c] \n",
		"[%1c] \n",
		"[%10c] \n",
		"[%1.c] \n",
		"[%.10c] \n",
		"[%1.1c] \n",
		"[%10.10c] \n",
		"[%010hd] \n",
		"[%-10hd] \n",
		"[%+10ld] \n",
		"[% 10lld] \n",
		"[%010.10c] \n",
		"[%-10.10c] \n",
		"[%+10.10c] \n",
		"[% 10.10c] \n",
		"[%0010c] \n",
		"[%-010c] \n",
		"[%....10c] \n",
		"[%              10c] \n",
		"[%10.5c] \n",
		"[%rd] \n",
		"[%|c] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 4)
	{
		printf("\n\n-----------basic char--------------------------->>[%c]\n", multi_arg[y]);	
		while (i < 30)
		{
		ret_c = 0;
		ret_ft = 0;

			printf("STRING >>>>>>>>>>>>>>>>>>>>{test %d}{%c}>>>> %s\n", i, multi_arg[y], multi_test[i]);
			ret_c = printf(multi_test[i], multi_arg[y]);
			ret_ft = ft_printf(multi_test[i], multi_arg[y]);
			printf("\n");
			diff_ret = ret_c - ret_ft;
			if (diff_ret != 0)
			{
				printf("\033[0;31m");
				printf(" [ko] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
					delay(50);
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
	printf("\n\n=============  [extra]  =================\n\n\n");

	long long int a;

	a = 123567;
	ret_c = printf("test %cet test %c ", 'A', (int)a);
	ret_ft = ft_printf("test %cet test %c ", 'A', (int)a);
	printf("\n");
	diff_ret = ret_c - ret_ft;
	if (diff_ret != 0)
	{
		printf("\033[0;31m");
		printf(" [ko] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
		printf("\033[0m");
		delay(50);
	}
	else
	{
		printf("\033[0;32m");
		printf(" [OK] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
		printf("\033[0m");
	}
		
			
	printf("\n\n=============  [fin extra]  =================\n\n\n");
	system("leaks a.out");	

}

