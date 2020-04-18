#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

int     main(int argc, char *argv[])
{
    int i;
    int s;

    if (argc)
    {
        s = 0;
        while (s < argc)
        {
            i = 0;
            while (argv[s][i] != '\0')
            {
                ft_putchar(argv[s][i]);
                i++;
            }
            ft_putchar('\n');
            s++;
        }
    }
    return (0);
}
