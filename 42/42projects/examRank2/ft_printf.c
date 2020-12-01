#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define ISDIGIT(c) ('0' <= c && c <= '9')
#define MAX(a, b) (a > b ? a : b)

int ft_strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return (p - s);
}

int a_toi(const char **fmt)
{	
	int ret = 0;
	while (ISDIGIT(**fmt))
	{
		ret = ret * 10 + **fmt - '0';
		(*fmt)++;
	}
	return (ret);
}

char *ft_strndup(char *str, int size)
{
	char *ret = malloc(size + 1);
	char *tmp = ret;
	while (*str && size --)
		*ret++ = *str++;
	*ret = '\0';
	return (tmp);

}

char *uitoa_base(unsigned int num, int base)
{
	char ret[16];
	char str[16] = "0123456789abcdef";
	int i = 0;
	ret[i++] = str[num % base];
	while ((num /= base) > 0)
		ret[i++] = str[num % base];
	ret[i] = '\0';
	int j = 0;
	int c;
	while (j < i / 2)
	{
		c = ret[j];
		ret[j] = ret[i - j - 1];
		ret[i - j - 1] = c;
		j++;
	}
	int len = ft_strlen(ret);

	//printf("fun uitoa_base, len:%d, ret:%s\n", len, ret);
	char *malret = ft_strndup(ret, len);

	return (malret);
}

int putnchar(char c, int size)
{
	int i = 0;
	while(i < size)
		i += write(1, &c, 1);
	return (i);
}

int put_sdx(int width, int prec, int sign, char *value)
{
	int ret = 0;
	ret += putnchar(' ', width - prec - sign);
	ret += write (1, "-", sign);
	ret += putnchar('0', prec - ft_strlen(value));
	ret += write (1, value, ft_strlen(value));
	free(value);
	return (ret);
}

int put_x(const char **fmt, int width, int prec, unsigned int x)
{
	int ret = 0;
	char *value = uitoa_base(x, 16);
	//printf("fun put_d, value:%s\n", value);
	prec = MAX(prec, ft_strlen(value));	
	ret += put_sdx(width, prec, 0, value);
	(*fmt)++;
	return (ret);
}

int ft_strnlen(char *s, int maxlen)
{
	int len = 0;
	while (*s && maxlen--)
	{
		s++;
		len++;
	}
	return (len);
}

int put_s(const char **fmt, int width, int prec, char *s)
{
	s = s ? s : "(null)";
	int ret = 0;
	//printf("fun put_d, value:%s\n", value);
	prec = ft_strnlen(s, prec);
	char *value = ft_strndup(s, prec);
	ret += put_sdx(width, prec, 0, value);
	(*fmt)++;
	return (ret);
}

int put_d(const char **fmt, int width, int prec, int d)
{
	int ret = 0;
	int sign = 0;
	if (d < 0)
	{
		sign = 1;
		d *= -1;
	}
	char *value = uitoa_base(d, 10);
	//printf("fun put_d, value:%s\n", value);
	if (d == 0 && prec == 0)
		*value = '\0';
	prec = MAX(prec, ft_strlen(value));	
	ret += put_sdx(width, prec, sign, value);
	(*fmt)++;
	return (ret);
}	

int ft_printf(const char *fmt, ...)
{
	int len = 0;
	int width = -1;
	int prec = -1;
	char *tmp;
	va_list arg;

	va_start(arg, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			len += write(1, fmt, 1);
			fmt++;
		}
		else
		{
			tmp = (char *)fmt;
			fmt++;
			if (ISDIGIT(*fmt))
				width = a_toi(&fmt);
			if (*fmt == '.')
			{
				fmt++;
				prec = a_toi(&fmt);
			}
			//printf("fun printf, width:%d, prec:%d\n", width, prec);
			if (*fmt == 'd')
				len += put_d(&fmt, width, prec, va_arg(arg, int));
			else if (*fmt == 'x')
				len += put_x(&fmt, width, prec, va_arg(arg, unsigned int));
			else if (*fmt == 's')
				len += put_s(&fmt, width, prec, va_arg(arg, char *));
			else
				len += write(1, tmp, fmt - tmp);
		}
	}
	va_end(arg);
	return (len);
}


#ifdef test
int main()
{
	printf(":%d\n", ft_printf("aaa"));
	printf(":%d\n", printf("orig[%d]", 5));
	printf(":%d\n", ft_printf("mimi[%d]", 5));
	printf(":%d\n", printf("orig[%10.5d]", 5));
	printf(":%d\n", ft_printf("mimi[%10.5d]", 5));
	printf(":%d\n", printf("orig[%10.5d]", -5));
	printf(":%d\n", ft_printf("mimi[%10.5d]", -5));
	printf(":%d\n", printf("orig[%d]", 0));
	printf(":%d\n", ft_printf("mimi[%d]",0 ));
	printf(":%d\n", printf("orig[%10.5d]", 0));
	printf(":%d\n", ft_printf("mimi[%10.5d]",0 ));
	printf(":%d\n", printf("orig[%10.5d]", 5));
	printf(":%d\n", ft_printf("mimi[%10.5d]", 5));
	printf("aaa\n");
	printf(":%d\n", printf("orig[%10.5x]", 42));
	printf(":%d\n", ft_printf("mimi[%10.5x]", 42));
	printf(":%d\n", printf("orig[%x]", 42));
	printf(":%d\n", ft_printf("mimi[%x]",42 ));
	printf(":%d\n", printf("orig[%10.0x]", 42));
	printf(":%d\n", ft_printf("mimi[%10.0x]",42 ));
	printf("aaa\n");
	printf(":%d\n", printf("orig[%10.5s]", "qwerty"));
	printf(":%d\n", ft_printf("mimi[%10.5s]", "qwerty"));
	printf(":%d\n", printf("orig[%s]", "qwerty"));
	printf(":%d\n", ft_printf("mimi[%s]", "qwerty"));
	printf(":%d\n", printf("orig[%10.0s]", "qwerty"));
	printf(":%d\n", ft_printf("mimi[%10.0s]","qwerty" ));

}
#endif
