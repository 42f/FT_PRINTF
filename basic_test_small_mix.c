void	basic_test_small_mix(void)
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
	char 	multi_test[19][100] =
	{	
		"[%10d] \n",
		"[%10i] \n",
		"[%10u] \n",
		"[%+10d] \n",
		"[%+10i] \n",
		"[%+10u] \n",
		"[%-10d] \n",
		"[%-10i] \n",
		"[%-10u] \n",
		"[% 10d] \n",
		"[% 10i] \n",
		"[% 10u] \n",
		"[%0 10d] \n",
		"[%0 10i] \n",
		"[%0 10u] \n",
		"[%010d] \n",
		"[%010i] \n",
		"[%010u] \n",
		"[%010u] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	int		total_error = 0;
	while (y < 6)
	{
		printf("\n\n--------------basic int------------------------------------------------>>[%d]\n", multi_arg[y]);	
		while (i < 19)
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
				total_error++;
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
	printf("\n\n=============  TOTAL = %d  =================\n\n\n", total_error);
	system("leaks a.out");	
}


