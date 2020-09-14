#include "print.h"
#include "Struct_d_and_i.h"


int		ft_ecriture_zero_point_x_min(char *dest, int y, int tampon, int len_int, unsigned int nombre_charact_int)
{
	if (y > tampon)
	{
		if (tampon > len_int)
		{
			while (y - tampon > 0)
			{
				write(1," ", 1);
				y--;
			}
		}
		else
		{
			while (y - len_int > 0)
			{
				write(1," ", 1);
				y--;
			}
			if (nombre_charact_int == 0)
				write (1, "0", 1);
		}
	}
	else
	{
		ft_ecriture_point_x(y, tampon, dest, len_int, nombre_charact_int);
		return (2);
	}
	return (1);
}

int		ft_parametre_zero_tiret_x_min(int i, int y, const char *s, unsigned int nombre_charact_int)
{
	int tampon;
	char *dest = NULL;
	char *tmp = NULL;
	int len_int;
	flag decalage = {0,0};

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
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	y = ft_ecriture_zero_point_x_min(dest, y, tampon, len_int, nombre_charact_int);
	if ( y == 1)
		ft_ecriture_double_flag_x(i, tampon, nombre_charact_int, len_int);
	return (1);
}

int		ft_flag_zero_x(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	int tampon;
	flag decalage = {0,0};

	y = i - 1;
	tampon = 0;
	while (s[y] != 'x')
	{
		if (s[y] == '.')
		{
			ft_parametre_zero_tiret_x_min(i, y, s, nombre_charact_int);
			while (s[i] != 'x')
				{
					i++;
				}
			return (i);
		}
		y++;
	} 
	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_zero_x( i, y, dest, len_int, nombre_charact_int);
	return (i);
}
