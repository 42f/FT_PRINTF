void	basic_test_01_hex()
{
	

char	*str = "hello";
	void	*multi_arg[4] =
	{
		str,
		0,
		(unsigned int *)-41313,
		(void *)0xe,
	};
	char 	multi_test[25][100] =
	{
		"[%p] \n",
		"[%.1p] \n",
		"[%15p] \n",
		"[%-15p] \n",
		"[%15.p] \n",
		"[%x] \n",
		"[%5x] \n",
		"[%.15x] \n",
		"[%-15x] \n",
		"[%15.1x] \n",
		"[%015x] \n",
		"[%#15.x] \n",
		"[%X] \n",
		"[%5X] \n",
		"[%.15X] \n",
		"[%-15X] \n",
		"[%15.X] \n",
		"[%015X] \n",
		"[%#0015.X] \n",
		"[%#15.X] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 4)
	{
		printf("\n\n--------------basic pointer conv = p ------------------------------------------------>>[%p]\n", multi_arg[y]);	
		while (i < 20)
		{
		ret_c = 0;
		ret_ft = 0;

			printf("STRING >>>>>>>>>>>>>>>>>>>>{test %d}{%p}>>>> %s", i, multi_arg[y], multi_test[i]);
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
	system("leaks a.out");	
}

