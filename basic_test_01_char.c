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
		printf("\n\n-----------basic char--------------------------->>[%c]\n", multi_arg[y]);	
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

