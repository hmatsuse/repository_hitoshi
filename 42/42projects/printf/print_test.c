#include <stdio.h>

int		main(void)
{
	// // c
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
	// ft_printf("[%c]\n", 'a');
	// printf("[%c]\n", 'a');
	// ft_printf("-------------\n");
	// ft_printf("[%5c]\n", 'a');
	// printf("[%5c]\n", 'a');
	// ft_printf("-------------\n");
	// ft_printf("[%-3c]\n", 'a');
	// printf("[%-3c]\n", 'a');
	// ft_printf("-------------\n");
	// ft_printf("[%2c]\n", 'a');
	// ft_printf("[%.0c]\n", 'a');
	// printf("[%.0c]\n", 'a');
	// // ft_printf("\n\n");

	// // s
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
	// ft_printf("qqq%30.20s\n", "aaaaaaaaaaa", "kkkkk");
	// printf("qqq%30.20s\n", "aaaaaaaaaaa", "kkkkk");
	// ft_printf("-------------\n");

	// // d
	printf("[-----d------]\n");
	// printf("ft_printf return = %d\n", ft_printf("[%0-10d]\n", -10));
	// printf("printf return =%d\n", printf("[%0-10d]\n", -10));
	// printf("[-----------]\n");
	// ft_printf("[%010d]\n", -10);
	// printf("[%010d]\n", -10);
	// printf("[-----------]\n");
	// ft_printf("[%-10dABC%010.*s]\n", 234, 3, "OOOOOO");
	// printf("[%-10dABC%010.*s]\n", 234, 3, "OOOOOO");
	// printf("[-----------]\n");
	// ft_printf("[%010.6d]\n", -234);
	// printf("[%010.6d]\n", -234);
	// printf("[-----------]\n");
	// ft_printf("[%010.5d]\n", -234);
	// printf("[%010.5d]\n", -234);
	// ft_printf("[%u]\n", -10);
	// printf("[%u]\n", -10);
	// printf("[-----------]\n");
	// ft_printf("[%-10.5d]\n", -10);
	// printf("[%-10.5d]\n", -10);
	// printf("[-----------]\n");
	// ft_printf("[%010.7d]\n", -10);
	// printf("[%010.7d]\n", -10);
	// printf("[-----------]\n");
	// ft_printf("[%010d]\n", -10);
	// printf("[%010d]\n", -10);
	// printf("[-----------]\n");
	// ft_printf("[%010.4d]\n", 10);
	// printf("[%010.4d]\n", 10);
	// printf("[-----------]\n");
	ft_printf("[%-3.7d]\n", -2375);
	printf("[%-3.7d]\n", -2375);
	printf("-----------\n");
	ft_printf("[%03.7d]\n", 3267);
	printf("[%03.7d]\n", 3267);
	printf("-----------\n");
	ft_printf("[%.3d]\n", 0);
	printf("[%.3d]\n", 0);

	// ft_printf("%.*u\n", -1, 12345);
	// printf("%.*u\n", -1, 12345);
	// // *
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

	// ft_printf("%.0i\n", 0);
	// // p
	// printf("[-----p------]\n");
	// ft_printf("%p\n", "Hello World!");
	// printf("%p\n", "Hello World!");
	// printf("-------------\n");
	// ft_printf("%p\n", 17);
	// printf("%p\n", 17);

	// // x
	// printf("[-----x------]\n");
	// ft_printf("%x\n", "Hello World!");
	// printf("%x\n", "Hello World!");
	// printf("-------------\n");
	// ft_printf("%x\n", 100);
	// printf("%x\n", 100);

	// // X
	// printf("[------X-----]\n");
	// ft_printf("%X\n", "Hello World!");
	// printf("%X\n", "Hello World!");
	// printf("-------------\n");
	// ft_printf("%X\n", 200);
	// printf("%X\n", 200);
	// printf("-------------\n");
	// ft_printf("%02.7X\n", 3267);
	// printf("%02.7X\n", 3267);
	// printf("-------------\n");
	// ft_printf("%03.3X\n", 6983);
	// printf("%03.3X\n", 6983);
	// printf("-------------\n");
	// ft_printf("%08.3X\n", 8375);
	// printf("%08.3X\n", 8375);
	// printf("-------------\n");
	// ft_printf("%.X\n", 0);
	// printf("%.X\n", 0);
	// printf("-------------\n");
	// ft_printf("[%5p]\n", 0);
	// printf("[%5p]\n", 0);

	// // %
	// printf("[------ps-----]\n");
	// ft_printf("[%5]\n");
	// printf("[%5]\n");
	// printf("-----------\n");
	// ft_printf("[%5%]\n");
	// printf("[%5%]\n");
	// printf("-----------\n");
	// ft_printf("[%-5%]\n");
	// printf("[%-5%]\n");
	// printf("-----------\n");
	// ft_printf("[%-5.2%]\n");
	// printf("[%-5.2%]\n");
	// printf("-----------\n");
	// ft_printf("[%-5.%]\n");
	// printf("[%-5.%]\n");
	// printf("-----------\n");
	// ft_printf("[%-5.%]\n", 9);
	// printf("[%-5.%]\n", 9);
	// printf("-----------\n");
	// ft_printf("[%-5.9%]\n", 9);
	// printf("[%-5.9%]\n", 9);

	return (0);
}
