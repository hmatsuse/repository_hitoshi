/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:47:59 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/29 18:07:08 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	judgue(char s, char c)
{
	if (s == c)
		return (0);
	return (1);
}

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
		if (judgue(s[i], c) == 0)
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
	while (s[count] != '\0' && judgue(s[count], c) == 1)
		count++;
	if (!(tmp = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count = 0;
	i = 0;
	while (s[count] != '\0' & judgue(s[count], c) == 1)
		tmp[i++] = s[count++];
	tmp[i] = '\0';
	return (tmp);
}

static void		sep(char **tmp, const char *s, char c)
{
	size_t	flag;
	size_t	i;
	size_t	a;

	flag = 1;
	i = 0;
	a = 0;
	while (s[a] != '\0')
	{
		if (judgue(s[a], c) == 0)
			flag = 1;
		else if (flag == 1)
		{
			tmp[i++] = set(&s[a], c);
			flag = 0;
		}
		a++;
	}
	tmp[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		size;

	if (!s || !c)
		return (NULL);
	size = count(s, c);
	if (!(tmp = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	sep(tmp, s, c);
	return (tmp);
}
