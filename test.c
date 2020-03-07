#include "print.h"

void	ft_putchar(char s)
{
	write(1, &s, 1);
}
int		ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int nb;

	sign = 1;
	nb = 0;
	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v' ||
		nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}

void	ft_chaine(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_printf(const char *s, ...)
{
	va_list list;
	int i;
	int c;
	int a;
	char tmp[10];

	i = 0;
	c = 0;
	a = 0;
	va_start(list, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == '-')
			{
				i++;
				if (s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					while (s[i + 1] >= '0' && s[i + 1] <= '9')
					{
						tmp[c] = s[i + 1];
						i++;
						c++;
					}
					tmp[c] = '\0';
					a = ft_atoi(tmp) - 1;
					printf("%d\n", a);
				}
			}
			if (s[i + 1] == 'c' && a != 0)
			{
				ft_putchar(va_arg(list, int));
				while (a != 0)
				{
					ft_putchar(' ');
					a--;
				}
				i = i + 2;
			}
			if (s[i + 1] == 'c' && a == 0)
			{
				ft_putchar(va_arg(list, int));
				i = i + 2;
			}
		}
		if (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}	
	}
	va_end(list);
	return (0);
}

int main()
{
	ft_printf("%-85cc|\n", 'a');
	printf("%-85cc|", 'a');
}