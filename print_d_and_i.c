#include "print.h"
#include "Struct_d_and_i.h"

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

char		*ft_itoa(int n)
{
	char *alpha;
	char *str;
	int i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count(n) + 1))))
		return (0);
	alpha = "0123456789abcdef";
	if (n < 0)
	{
		n = 4294967296 - (-1 * n);
	}
	while (n > 0)
	{
		str[i] = alpha[n % 10];
		i++;
		n = n / 10;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return(str);
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

int		ft_ecriture(const char *s, int i, int y, int nombre_charact_int)
{	
	int count;

	count = 0;
	if (s[i + 1] == 'd' || s[i + 1] == 'i' )
	{
		count = ft_int(nombre_charact_int);
		i = i + 2;
	}
	if (y >= count)
	{
		y = y - count;
		while (y != 0)
		{
			write(1," ",1);
			y--;
		}	
	}
	return i;
}

int		ft_flag_tiret(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	y = 0;
	if (s[i + 1] >= '0' && s[i + 1] <= '9')
	{
		y = i;
		while (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			decalage.nombre_d_espace++;
			i++;
		}
		tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	}
	y = ft_atoi(tmp);
	ft_ecriture(s, i, y, nombre_charact_int);
	return (i);
}

int		ft_ecriture_largeur(const char *s, int i, int y, int nombre_charact_int, int len_int)
{	
	int count;

	count = 0;
	if (y > len_int)
		y = y - len_int;
	if (s[i] == 'd' || s[i] == 'i' )
	{
		while(y > 0)
		{
			write(1," ",1);
			y--;
		}
		count = ft_int(nombre_charact_int);
		i = i + 2;
	}
	return i;
}

int		ft_flag_largeur(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur(s, i, y, nombre_charact_int, len_int);
	return (i);
}

int		ft_ecriture_point(const char *s, int i, int y, int nombre_charact_int, int len_int)
{	
	int count;

	count = 0;
	if (y > len_int)
		y = y - len_int;
	if (s[i + 1] == 'd' || s[i + 1] == 'i' )
	{
		while(y > 0)
		{
			write(1,"0",1);
			y--;
		}
		count = ft_int(nombre_charact_int);
		i = i + 2;
	}
	return i;
}

int		ft_flag_point(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i;
	while (s[i + 1] >= '0' && s[i + 1] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_point(s, i, y, nombre_charact_int, len_int);
	return (i);
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
				i = ft_flag_tiret(i + 1, s, va_arg(list, int)) + 2;
			}
			if (s[i + 1] > '0' && s[i + 1] <= '9')
			{
				i = ft_flag_largeur(i + 1, s, va_arg(list, int)) + 1;
			}
			if (s[i + 1] == '.' || s[i + 1] == '0')
			{
				i = ft_flag_point(i + 1, s, va_arg(list, int)) + 2;
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
	ft_printf("j'ai %.0006d ans\n", 24);
	printf("j'ai %.0006d ans", 24);
}