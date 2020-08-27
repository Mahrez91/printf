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
				i = ft_flag_tiret_s(i + 1, s, va_arg(list, char*)) + 2;
			}
			if (s[i + 1] > '0' && s[i + 1] <= '9')
			{
				i = ft_flag_largeur_s(i + 1, s, va_arg(list, char*)) + 1;
			}
			if (s[i + 1] == '.')
			{
				i = ft_flag_point_s(i + 1, s, va_arg(list, char*));
			}
			if (s[i + 1] == 's')
			{
				ft_chaine(va_arg(list, char *));
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
	ft_printf("j'ai %.3s ans\n", "vingt");
	printf("j'ai %*.s ans",10, "vingt");
}