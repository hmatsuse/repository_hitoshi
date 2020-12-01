
//1615

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX(x, y) (x>y ? x : y)
#define MIN(x, y) (x<y ? x : y)
#define ABS(x) (x>0 ? x : -x)

typedef struct s_f
{
	int w;//widht
	int dot;//dotあるかないか
	int val;//精度
	int plen;//put len
	char c;//指定子
}			t_f;

void	_bzero(void	 *s, size_t n)
{
	char *str = (char *)s;
	size_t i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	_putchar(char c, t_f *f)
{
	write(1, &c, 1);
	f->plen++;
}

void	_putnbr(long long n, t_f *f)
{
	if (f->dot == 1 && f->val == 0 && n == 0) //5.0d, 0 => [     ]
		return ;
	char *base = (f->c == 'd' ? "0123456789" : "0123456789abcdef");
	long long x = (f->c == 'd' ? 10 : 16);

	if (n >= x)
		_putnbr(n / x, f);
	_putchar(base[n % x], f);
}

int	 _nbrlen(long long n, t_f *f)
{
	if (f->dot == 1 && f->val == 0 && n == 0)
		return (0);
	if (n == 0)
		return (1);
	long long x = (f->c == 'd' ? 10 : 16);
	int count = 0;
	while (n > 0)
	{
		n /= x;
		count++;
	}
	return (count);
}

int		_fmt(va_list ap, char *s, t_f *f)
{
	int rc = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			while ('0' <= *s && *s <= '9')
			{
				f->w = f->w * 10 + *s - '0';
				s++;
			}
			if (*s == '.')
			{
				f->dot = 1;
				s++;
			}
			while ('0' <= *s && *s <= '9')
			{
				f->val  = f->val * 10 + *s - '0';
				s++;
			}
			if (*s == 'd' || *s == 'x')
			{
				// box = f->w - MAX(f->val, len);
				// -
				// zero = MAX(f->val - len, 0);
				//putnbr(ABS(n))
				long long n;
				if (*s == 'd') n = va_arg(ap, int);
				else n = va_arg(ap, unsigned int);
				f->c = *s;
				long long len = _nbrlen(ABS(n), f);
				int box = f->w - MAX(f->val, len);
				if (n < 0) box--;
				int i = 0;
				while (i < box)
				{
					_putchar(' ', f);
					i++;
				}
				if (n < 0)
					_putchar('-', f);
				int zero = MAX(f->val - len, 0);
				i = 0;
				while (i < zero)
				{
					_putchar('0', f);
					i++;
				}
				_putnbr(ABS(n), f);
			}
			else if (*s == 's')
			{
				// box = f->w - MIN(len, f->val);
				// 出力する文字数 MIN(len, f->val)
				char *t = va_arg(ap, char *);
				if (t == NULL)
					t = "(null)";
				int len=0;
				while (t[len])
					len++;
				if (f->dot == 0)
					f->val = len;
				int box = f->w - MIN(len, f->val);
				int i = 0;
				while (i < box)
				{
					_putchar(' ', f);
					i++;
				}
				i = 0;
				while (i < MIN(len, f->val))
				{
					_putchar(t[i], f);
					i++;
				}
			}
			if (*s == '\0') 
				return (-1);
			s++;

		}
		else
		{
			_putchar(*s, f);
			s++;
		}
		rc += f->plen;
		_bzero(f, sizeof(t_f));//0で初期化
	}
	return (rc);
}

int	ft_printf(char *s, ...)
{
	t_f *f = malloc(sizeof(t_f) * 1);
	if (!f) return (0);
	_bzero(f, sizeof(t_f));
	va_list ap;
	int rc = 0;
	va_start(ap, s);

	rc = _fmt(ap, s, f);

	va_end(ap);
	free(f);
	f = NULL;
	return (rc);
}


