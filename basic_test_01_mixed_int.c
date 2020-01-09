
void	basic_test_01_mixed_int(void)
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
	{	"[%i] \n",
		"[%.d] \n",
		"[%5.30i] \n",
		"[%-5.30u] \n",
		"[%15i] \n",
		"[%.u] \n",
		"[%15i] \n",
		"[%15.0i] \n",
		"[%15.1u] \n",
		"[%15.10i] \n",
		"[%-15.0u] \n",
		"[%-15.1u] \n",
		"[%-+18.10i] \n",
		"[%- 18.10i] \n",
		"[%+-18.10u] \n",
		"[% +18.10u] \n",
		"[% -18.10u] \n",
		"[%-.0i] \n",
		"[%-0 .0i] \n",
		"[%+- .0u] \n",
		"[%8.8i] \n",
		"[%08i] \n",
		"[%0-15u] \n",
		"[%08u] \n",
		"[%0u] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 6)
	{
		printf("\n\n-------------------basic mixed int------------------------------------------->>[%d]\n", multi_arg[y]);	
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
	system("leaks a.out");	
}


