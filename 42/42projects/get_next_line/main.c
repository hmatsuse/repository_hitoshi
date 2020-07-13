#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		fd;
	int 	n;
	char 	*s;

	// if (argc == 2)
	// {
		fd = open(argv[1], O_RDONLY);
		while ((n = get_next_line(fd, &s)) >= 0)
		{
			printf("%s\n", s);
			free(s);
			if (n == 0)
				break ;
		}
		// get_next_line(fd, &s);
		// printf("%s\n", s);
		close(fd);
	// }
}
