
void	basic_mixed_int()
{
	int c = -125;
	char 	*multi_test = "[%d]\n[%d]\n[%5.30d]\n[%-5.30d]\n[%15d]\n[%.d]\n[%15.0d]\n[%15.1d]\n[%15.10d]  \n\n\n\n";

	printf(multi_test, c,c,c,c,c,c,c,c,c);	
	ft_printf(multi_test, c,c,c,c,c,c,c,c,c);	
	system("leaks a.out");	
	
}
