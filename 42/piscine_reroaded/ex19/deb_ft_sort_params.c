/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_sort_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 18:18:53 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 18:18:53 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    swap(char **s1, char **s2)
{
    char *tmp;

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp; 
}

int     cmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void    sort(int argc,char *argv[])
{
    int s;
    int i;
    
    s = 1;
    while (s < argc - 1)
    {
        i = 1;
        while (i < argc -1)
        {
            if (cmp(argv[i], argv[i + 1]) > 0)
                swap(&argv[i], &argv[i + 1]);
            i++;
        }
        s++;
    }
}

int     main(int argc,char *argv[])
{
    int s;
    int i;

    sort(argc, argv);
    if (argc)
    {
        s = 1;
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
