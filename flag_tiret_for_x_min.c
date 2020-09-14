#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_point_x_min(int y, int tampon, int len_int)
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
		}
	}
	return (1);
}

int		ft_parametre_x_min(int i, int y, const char *s, unsigned int nombre_charact_int)
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
	ft_ecriture_tiret_point_x_min(y, tampon, len_int);
	return (1);
}

int		ft_flag_tiret_x(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	y = i;
	while (s[y] != 'x')
	{
		if (s[y] == '.')
		{
			len_int = ft_flag_point_x(y + 1, s,nombre_charact_int);
			ft_parametre_x_min(i, y, s, nombre_charact_int);			
			return (len_int);
		}
		y++;
	}
	if (s[i] >= '0' && s[i] <= '9')
	{
		y = i - 1;
		while (s[i] >= '0' && s[i] <= '9')
		{
			decalage.nombre_d_espace++;
			i++;
		}
		tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	}
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	y = ft_atoi(tmp);
	ft_ecriture_tiret_x( i, y, dest, len_int);
	return (i);
}