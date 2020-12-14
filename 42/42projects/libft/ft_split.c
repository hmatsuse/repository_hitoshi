/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsusehitoshi <matsusehitoshi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:47:59 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/03 13:24:55 by matsusehito      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t	count;
	size_t	flag;
	size_t	i;

	count = 0;
	flag = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		else if (flag == 1)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

static char		*set(const char *s, char c)
{
	size_t	count;
	size_t	i;
	char	*tmp;

	count = 0;
	while (s[count] != '\0' && s[count] != c)
		count++;
	if (!(tmp = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count = 0;
	i = 0;
	while (s[count] != '\0' && s[count] != c)
		tmp[i++] = s[count++];
	tmp[i] = '\0';
	return (tmp);
}

static void		ft_free_malloc(char **tmp, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

static int		sep(char **tmp, const char *s, char c)
{
	size_t	flag;
	size_t	i;
	size_t	a;

	flag = 1;
	i = 0;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == c)
			flag = 1;
		else if (flag == 1)
		{
			if (!(tmp[i] = set(&s[a], c)))
			{
				ft_free_malloc(tmp, i);
				return (0);
			}
			i++;
			flag = 0;
		}
		a++;
	}
	tmp[i] = 0;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**tmp;
	int		size;

	if (!s)
		return (NULL);
	size = count(s, c);
	printf ("%d\n", size);
	if (!(tmp = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	if (sep(tmp, s, c) == 0)
		return (NULL);
	return (tmp);
}

int		main()
{
	char s[] = "ss";
	char **tmp;
	int i;

	i = 0;
	tmp = ft_split(s, '\0');
	while (tmp[i] != (void *)0)
	{
		printf("%s\n", tmp[i]);
		i++;
	}
}