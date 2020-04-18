/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_print_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 17:40:49 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 17:40:49 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c);

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
        i = 1;
        while (i < argc)
        {
            s = 0;
            while (argv[i][s] != '\0')
            {
                ft_putchar(argv[i][s]);
                s++;
            }
            ft_putchar('\n');
            i++;
        }
    }
    return (0);
}
