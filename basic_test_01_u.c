void	basic_test_01_u(void)
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
	{	"[%u] \n",
		"[%.u] \n",
		"[%5.30u] \n",
		"[%-5.30u] \n",
		"[%15u] \n",
		"[%.u] \n",
		"[%15u] \n",
		"[%15.0u] \n",
		"[%15.1u] \n",
		"[%15.10u] \n",
		"[%-15.0u] \n",
		"[%-15.1u] \n",
		"[%-+18.10u] \n",
		"[%- 18.10u] \n",
		"[%+-18.10u] \n",
		"[% +18.10u] \n",
		"[% -18.10u] \n",
		"[%-.0u] \n",
		"[%-0 .0u] \n",
		"[%+- .0u] \n",
		"[%8.9u] \n",
		"[%8.8u] \n",
		"[%08u] \n",
		"[%05.1u] \n",
		"[%.1u] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	int		total = 0;
	int		total_error = 0;
	while (y < 6)
	{
		printf("\n\n--------------basic u ------------------------------------------------>>[%d]\n", multi_arg[y]);	
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
				total_error++;
			}
			else
			{
				printf("\033[0;32m");
				printf(" [OK] return ! libc = %d, ft = %d\n\n\n", ret_c, ret_ft);
				printf("\033[0m");
			}
			total++;
			i++;
		}
	i = 0;
	y++;
	}
	printf("\n\n=============  FIN MAIN  =================\n\n");
			if (total_error != 0)
			{
				printf("\033[0;31m");
	printf("\n\n========  %d errors / %d test ============\n\n\n", total_error, total);
				printf("\033[0m");
				delay(400);
			}
			else
			{
			printf("\033[0;32m");
			printf(" == [OK] == \n\n");
			printf("\033[0m");
			}

//
// SANDBOX
//


printf("%u\n", -1);
ft_printf("%u\n--\n", -1);
printf("%u\n", 0);
ft_printf("%u\n--\n", 0);
printf("%u\n", UINT_MAX);
ft_printf("%u\n--\n", UINT_MAX);

printf("%u\n", INT_MIN);
ft_printf("%u\n--\n", INT_MIN);



}

