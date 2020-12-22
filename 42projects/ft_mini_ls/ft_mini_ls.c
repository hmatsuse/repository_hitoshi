/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsusehitoshi <matsusehitoshi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:55:34 by matsusehito       #+#    #+#             */
/*   Updated: 2020/12/03 18:52:10 by matsusehito      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 == *ss2)
	{
		if (*ss1 == '\0')
			return (0);
		ss1++;
		ss2++;
	}
	return (*ss1 - *ss2);
}

void ft_swap(int j, n_t *tn)
{
    n_t tmp;

    tmp = *(tn + j);
    *(tn + j) = *(tn + j + 1);
    *(tn + j + 1) = tmp;
}


void ft_sort_time(n_t *tn, int s)
{
    int i;
    int j;

    i = 0;
    while (i < s - 1)
    {
        j = 0;
        while (j < s - 1)
        {
            if (tn[j].sec > tn[j + 1].sec)
                ft_swap(j, tn);
            if (tn[j].sec == tn[j + 1].sec)
            {
                if (tn[j].nsec > tn[j + 1].nsec)
                    ft_swap(j, tn);
                if (tn[j].nsec == tn[j + 1].nsec && ft_strcmp(tn[j].name, tn[j + 1].name) < 0)
                    ft_swap(j, tn);
            }
            // if (tn[j].sec > tn[j + 1].sec)
            //     ft_swap(j, tn);
            // else if (tn[j].sec == tn[j + 1].sec && tn[j].nsec > tn[j + 1].nsec)
            //     ft_swap(j, tn);
            // else if (tn[j].sec == tn[j + 1].sec && tn[j].nsec == tn[j + 1].nsec && ft_strcmp(tn[j].name, tn[j + 1].name) < 0)
            //     ft_swap(j, tn);
            j++;
        }
        i++;
    }
}

int main()
{
    DIR *dp;
    struct dirent *dir;
    struct stat buf;
    n_t tn[100];
    int i;

    if ((dp = opendir(".")) == NULL)
    {
        perror("Can't open direcotry");
        return(1);
    }
    i = 0;
    while ((dir  = readdir(dp)) != NULL)
    {
        if (dir->d_ino == 0 || dir->d_name[0] == '.')
            continue;
        tn[i].name = dir->d_name;
        lstat(dir->d_name, &buf);
        tn[i].sec = (time_t)buf.st_mtimespec.tv_sec;
        tn[i].nsec = (long)buf.st_mtimespec.tv_nsec;
        // printf("name = [%s], sec = [%ld], nsec = [%ld]\n",dir->d_name, buf.st_mtimespec.tv_sec, buf.st_mtimespec.tv_nsec);
        // printf("%s\n",tn[i].name);
        i++;
    }
    ft_sort_time(tn, i);
    i = 0;
    while (tn[i].name)
    {
        ft_putendl_fd(tn[i++].name, 1);
        // printf("sec = [%ld], nsec = [%10ld], name = [%s]\n", tn[i].sec, tn[i].nsec, tn[i].name);
        // i++;
    }
    (void)closedir(dp);
    return (0);
}
