void	basic_test_01_string(void)
{
	char	multi_arg[10][50] =
	{	"coucou",
		" ",
		"a",
		"",
		"abcdefghijklmnopqrstuvwxyz"
	};
	char 	multi_test[24][100] =
	{	"[%s] \n",
		"[%5.30s] \n",
		"[%-5.30s] \n",
		"[%0-15s] \n",
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
		"[%.0s] \n",
		"[%+ .0s] \n",
		"[%- .0s] \n",
		"[% 15.s] \n",
		"[%-0 +.s] \n",
		"[%-0 +s] \n"
	};

	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 5)
	{
		printf("\n\n-----------basic string--------------------------->>[%s]\n", multi_arg[y]);	
		while (i < 24) 
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
	system("leaks a.out");	

}



