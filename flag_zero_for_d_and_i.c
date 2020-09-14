#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_zero_point(int i, int y, int tampon, int nombre_charact_int, int len_int)
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
	else
	{
		ft_ecriture_point(y, tampon, nombre_charact_int, len_int);
		return i ;
	}
	i = ft_ecriture_double_flag(i, tampon, nombre_charact_int, len_int) ;
	return (i);
}

int		ft_parametre_zero_point(int i, const char *s, int nombre_charact_int, int y)
{
	int tampon;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
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
		len_int = ft_strlen(dest);
	}
	else 
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	i = ft_ecriture_zero_point(i, y, tampon, nombre_charact_int, len_int);
	return (i);
}

int		ft_flag_zero(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};
	
	y = i - 1;
	while (s[y] != 'd' && s[y] != 'i')
	{
		if (s[y] == '.')
		{
			i = ft_parametre_zero_point(i, s, nombre_charact_int, y);
			while (s[i] != 'd' && s[i] != 'i')
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
	ft_ecriture_zero(i, y, nombre_charact_int, len_int);
	return (i);
}