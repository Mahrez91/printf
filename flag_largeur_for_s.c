#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_largeur_point_s(int y, int tampon, int len_int)
{
	if (y == 0 || tampon == 0)
		y++;
	if (y > tampon)
	{
		if (tampon > len_int)
		{
			while (y - tampon > 0)
			{
				write(1, " ", 1);
				y--;
			}
		}
		else
		{
			while (y - len_int > 0)
			{
				write(1, " ", 1);
				y--;
			}
		}
	}
	return (1);
}

int		ft_parametre_largeur_point_s(int i, int y, const char *s)
{
	int tampon;
	int len_int;
	char *tmp = NULL;
	char *dest= NULL;
	flag decalage = {0, 0};
	
	while (s[y + 1] >= '0' && s[y + 1] <= '9')
	{
		decalage.nombre_de_zero++;
		y++;
	}
	dest = ft_strlcpy(dest, s, decalage.nombre_de_zero, y - decalage.nombre_de_zero);
	tampon = ft_atoi(dest);
	y = i;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y - 1);
	y = ft_atoi(tmp);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur_point_s(y , tampon ,len_int);
	return (1);
}

int		ft_flag_largeur_s(int i, const char *s, char *string)
{
	int y;
	char *tmp = NULL;
	int len_int;
	flag decalage = {0, 0};

	y = i - 1;
	while (s[y] != 's')
	{
		if (s[y] == '.')
		{
			ft_parametre_largeur_point_s(i, y, s);
			ft_flag_point_s(y + 1 , s, string);
			while (s[i] != 's')
			{
				i++;
			}
			return (i);
		}
		y++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	len_int = ft_strlen(string);
	ft_ecriture_largeur_s(i, y, string, len_int);
	return (i);
}