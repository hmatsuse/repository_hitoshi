int		main(void)
{
	// c
	// printf("[-----c------]\n");
	// ft_printf("%012cll  %%c%c  l%9cs\n", '9', 'x', '?');
	// printf("%012cll  %%c%c  l%9cs\n", '9', 'x', '?');
	// ft_printf("-------------\n");
	// ft_printf("ab%9cdef\n", '0');
	// printf("ab%9cdef\n", '0');
	// ft_printf("-------------\n");
	// ft_printf("ab%-4cdef\n", '0');
	// printf("ab%-4cdef\n", '0');
	// ft_printf("-------------\n");
	// ft_printf("ab%4cdef\n", '0');
	// printf("ab%4cdef\n", '0');
	// ft_printf("-------------\n");
	// ft_printf("ab%cde%-10c%sf\n", '+', '-', "Hello World");
	// printf("ab%cde%-10c%sf\n", '+', '-', "Hello World");
	// ft_printf("-------------\n");
	// ft_printf("ab%cde%10c%15sf\n", '+', '-', "Hello World");
	// printf("ab%cde%10c%15sf\n", '+', '-', "Hello World");
	// ft_printf("-------------\n");

	// ft_printf("\n\n");

	// s
	printf("[-----s------]\n");
	ft_printf("%10s;;;%%s%s\n", "lllll", "test");
	printf("%10s;;;%%s%s\n", "lllll", "test");
	ft_printf("-------------\n");
	ft_printf("%-20s!!%010s\n", "Hello World", "Hey!");
	printf("%-20s!!%010s\n", "Hello World", "Hey!");
	ft_printf("-------------\n");
	ft_printf("%20.10s\n", "aaaaaaaaaaa");
	printf("%20.000001s\n", "aaaaaaaaaaa");
	return (0);
}
