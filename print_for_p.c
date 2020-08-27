#include "Struct_d_and_i.h"
#include "print.h"

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strlcpy(char *dst, const char *src, int n, int y)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[y + 1];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_int(int n)
{
	unsigned int i;
	static int count;
	int sign;

	sign = 0;
	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
		sign++;
	}
	else
		i = n;
	if (i >= 10)
		ft_int(i / 10);
	count++;
	ft_putchar(i % 10 + 48);
	if (sign == 0)
	{
		return (count);
	}
	else
	{
		return (count + 1);
	}
}

int		ft_printf(const char *s, ...)
{
	va_list list;
	static int i;
	int y;
	int count;

	i = 0;
	y = 0;
	count = 0;
	va_start(list, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == '-')
			{
				i = ft_flag_tiret_p(i + 1, s, va_arg(list, unsigned int)) + 2;
			}
			if (s[i + 1] > '0' && s[i + 1] <= '9')
			{
				i = ft_flag_largeur_p(i + 1, s, va_arg(list, unsigned int)) + 1;
			}
			if (s[i + 1] == 'p')
			{
				ft_itoa_base_pointeur(va_arg(list, unsigned int));
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
	printf("\n");
	return (0);
}

int main()
{
	int *ptr = 0;

	ft_printf("j'ai %p ans\n", &ptr);
	printf("j'ai %p ans", &ptr);
}