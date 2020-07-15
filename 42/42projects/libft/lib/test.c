
// #include "libft.h"
// #include <stdio.h>

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	needlelen;

// 	needlelen = ft_strlen(needle);
// 	if (*needle == '\0')
// 		return ((char *)haystack);
// 	while (*haystack != '\0' && len >= needlelen)
// 	{
// 		if (*haystack == *needle)
// 		{
// 			if (ft_strncmp(haystack, needle, needlelen) == 0)
// 				return ((char *)haystack);
// 		}
// 		haystack++;
// 		len--;
// 	}
// 	return (NULL);
// }

// int main()
// {
// 	char s[] = "HelloWorld";
// 	char s1[] = "Wor";

// 	printf("%s\n", ft_strnstr(s, s1, 1));
// }