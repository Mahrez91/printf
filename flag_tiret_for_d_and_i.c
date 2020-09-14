#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_point(int y, int tampon, int nombre_charact_int, int len_int)
{
	if (y > tampon)
	{
		if (tampon > len_int)
		{
			if (nombre_charact_int < 0)
			{
				while (y - tampon > 1)
				{
					write(1," ", 1);
					y--;
				}
			}
			else
			{
				while (y - tampon > 0)
				{
					write(1," ", 1);
					y--;
				}
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

int		ft_parametre(int i, int y, const char *s, int  nombre_charact_int)
{
	int tampon;
	int len_int;
	char *tmp = NULL;
	char *dest = NULL;
	flag decalage = {0,0};

	tampon = 0;
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
	if (nombre_charact_int < 0)
	{
		dest = ft_itoa(nombre_charact_int * (-1));
	len_int = ft_strlen(dest) + 1;
	}
	else 
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	ft_ecriture_tiret_point(y, tampon, nombre_charact_int, len_int);
	return (1);
}

int		ft_flag_tiret(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	int double_flag;
	flag decalage = {0,0};

	y = i;
	while (s[y] != 'd' && s[y] != 'i')
	{
		if (s[y] == '.')
		{
			double_flag = ft_flag_point(y + 1, s,nombre_charact_int);
			ft_parametre(i, y, s, nombre_charact_int);
			return (double_flag);
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
	y = ft_atoi(tmp);
	ft_ecriture_tiret(i, y, nombre_charact_int);
	return (i);
}