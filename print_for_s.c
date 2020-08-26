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
int		ft_ecriture_largeur_s(const char *s, int i, int y, char *string, int len_int)
{	
	if (y > len_int)
	{
		y = y - len_int;
		if (s[i] == 's')
		{
			while(y > 0)
			{
				write(1," ",1);
				y--;
			}
		}
	}
	ft_chaine(string);
	i = i + 2;
	return i;
}

int		ft_flag_largeur_s(int i, const char *s,char *string)
{
	int y;
	char *tmp = NULL;
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	len_int = ft_strlen(string);
	ft_ecriture_largeur_s(s, i, y, string, len_int);
	return (i);
}

int		ft_ecriture_tiret_s(const char *s, int i, int y, char *string)
{	
	if (s[i + 1] == 's')
	{
		ft_chaine(string);
		i = i + 2;
	}
	if (y > 0)
	{
		while (y != 0)
		{
			write(1," ",1);
			y--;
		}	
	}
	return i;
}

int		ft_flag_tiret_s(int i, const char *s,char *string)
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
	y = ft_atoi(tmp) - ft_strlen(string);
	ft_ecriture_tiret_s(s, i, y, string);
	return (i);
}

int		ft_ecriture_point_s(int i, int y, char *string, int len_int)
{	
	int count;
	int tmp;

	tmp = 0;
	count = 0;
	if (y < len_int)
	{	
		tmp = len_int - y;
		while(y > 0)
		{
			ft_putchar(string[count]);
			y--;
			count++;
		}
		return (i + 2);
	}
	else
		ft_chaine(string);
	i = i + 2;
	return i;
}

int		ft_flag_point_s(int i, const char *s,char *string)
{
	int y;
	char *tmp = NULL;
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	y = i;
	while (s[i + 1] >= '0' && s[i + 1] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	len_int = ft_strlen(string);
	y = ft_ecriture_point_s(i, y, string, len_int);
	return (y);
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
	ft_printf("j'ai %.s ans\n", "vingt");
	printf("j'ai %.s ans", "vingt");
}