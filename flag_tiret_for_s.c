#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_point_s(int y, int tampon, char *string)
{
	int len_int;

	if (ft_strlen(string) < y)
		len_int = ft_strlen(string);
	else
		len_int = y;
	if (tampon == 0)
		len_int = y;
	if (y > tampon)
	{
		if (tampon > len_int)
		{
			while (y - len_int > 0)
			{
				write(1, " ", 1);
				y--;
			}
		}
		else
		{
			while (len_int !=  tampon)
			{
				write(1, " ", 1);
				len_int--;
			}
		}
	}
	else
	{
		while (y > len_int)
		{
			write(1, " ", 1);
			y--;
		}
	}
	return (1);
}

int		ft_parametre_s(int i, int y, const char *s, char *string)
{
	int tampon;
	char *tmp = NULL;
	char *dest = NULL;
	flag decalage = {0,0};

	while (s[y + 1] >= '0' && s[y + 1] <= '9')
	{
		decalage.nombre_de_zero++;
		y++;
	}
	dest = ft_strlcpy(dest, s, decalage.nombre_de_zero, y - decalage.nombre_de_zero);
	tampon = ft_atoi(dest);
	y = i;
	while (s[i + 1] >= '0' && s[i + 1] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	ft_ecriture_tiret_point_s( y, tampon, string);
	return (1);
}

int		ft_flag_tiret_s(int i, const char *s, char *string)
{
	int y;
	char *tmp = NULL;
	flag decalage = {0, 0};

	y = i;
	while (s[y] != 's')
	{
		if (s[y] == '.')
		{
			ft_flag_point_s(y + 1, s, string);
			ft_parametre_s(i, y, s, string);
			while (s[i] != 's')
				i++;
			return (i - 1);
		}
		y++;
	}
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
	ft_ecriture_tiret_s(i, y, string);
	return (i);
}