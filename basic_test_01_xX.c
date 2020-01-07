#include <limits.h>

void	basic_test_01_xX()
{
	

unsigned long long multi_arg[5] =
	{
		-42,
		0,
		LLONG_MIN,
		LLONG_MAX,
		0xe,
	};
	char 	multi_test[27][100] =
	{
		"[%x] \n",
		"[%.lx] \n",
		"[%.hx] \n",
		"[%.lX] \n",
		"[%.hX] \n",
		"[%.llx] \n",
		"[%.llX] \n",
		"[%.hhx] \n",
		"[%.hhX] \n",
		"[%15x] \n",
		"[%-15x] \n",
		"[%15.x] \n",
		"[%x] \n",
		"[%5x] \n",
		"[%.15x] \n",
		"[%-15x] \n",
		"[%15.1x] \n",
		"[%015.2x] \n",
		"[%#15x] \n",
		"[%#015x] \n",
		"[%5X] \n",
		"[%.15X] \n",
		"[%-15X] \n",
		"[%15.X] \n",
		"[%015.2X] \n",
		"[%#0015.X] \n",
		"[%#15.X] \n",
	};
	int 	i = 0;
	int		y = 0;
	int		ret_c = 0;
	int		ret_ft = 0;
	int		diff_ret = 0;
	while (y < 5)
	{
		printf("\n\n--------------basic pointer conv = xX ------------------------------------------------>>[%llu]\n", multi_arg[y]);	
		while (i < 27)
		{
		ret_c = 0;
		ret_ft = 0;

			printf("STRING >>>>>>>>>>>>>>>>>>>>{test %d}{%llu}>>>> %s", i, multi_arg[y], multi_test[i]);
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

