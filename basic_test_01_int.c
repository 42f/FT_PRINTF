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
		printf("\n\n--------------basic int------------------------------------------------>>[%d]\n", multi_arg[y]);	
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


