#include <stdio.h>

int		main(void)
{
	int i = 0;
	// (1 < 2 && 1 < 8 ? printf("+\n") : printf("-\n"));
	(1 < 2 && 1 < 8 ? i++ : 0);
	printf("%d\n", i);
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
	// printf("[-----s------]\n");
	// ft_printf("%10s;;;%%s%s\n", "lllll", "test");
	// printf("%10s;;;%%s%s\n", "lllll", "test");
	// ft_printf("-------------\n");
	// ft_printf("%-20s!!%010s\n", "Hello World", "Hey!");
	// printf("%-20s!!%010s\n", "Hello World", "Hey!");
	// ft_printf("-------------\n");
	// ft_printf("%-20.2sl\n", "aaaaaaaaaaa");
	// printf("%-20.2sl\n", "aaaaaaaaaaa");
	// ft_printf("-------------\n");
	// ft_printf("%-10.2saaa%013....2s\n", "aaaaaaaaaaa", "bbbb");
	// printf("%-10.2saaa%013....2s\n", "aaaaaaaaaaa", "bbbb");
	// ft_printf("-------------\n");
	// ft_printf("qqq%10..3.2s\n", "aaaaaaaaaaa", "kkkkk");
	// printf("qqq%10..3.2s\n", "aaaaaaaaaaa", "kkkkk");
	// ft_printf("-------------\n");

	// d
	// printf("[-----d------]\n");
	// ft_printf("%0-10d\n", -10);
	// printf("%0-10d\n", -10);

	// *
	// ft_printf("%*s\n", 3, "aaaa");
	// printf("%*s\n", 3, "aaaa");
	// ft_printf("-------------\n");
	// ft_printf("%*.*s\n", 3, -10, "aaff");
	// printf("%*.*s\n", 3, -10, "aaff");
	// ft_printf("-------------\n");
	// ft_printf("%*.*s\n", 10, 2, "ppppp");
	// printf("%*.*s\n", 10, 2, "ppppp");
	// ft_printf("-------------\n");
	// ft_printf("%0*.*sl\n", -10, 3, "kkkkkk");
	// printf("%0*.*sl\n", -10, 3, "kkkkkk");
	// ft_printf("-------------\n");
	// ft_printf("%0*.*sl\n", 10, 3, "kkkkkk");
	// printf("%0*.*sl\n", 10, 3, "kkkkkk");
	// ft_printf("-------------\n");
	return (0);
}
