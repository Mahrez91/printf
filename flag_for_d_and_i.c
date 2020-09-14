#include "print.h"
#include "Struct_d_and_i.h"

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
	while (s[y] != 'd' && s[y] != 'i')
	{
		if (s[y] == '.')
		{
			ft_flag_zero(i, s, nombre_charact_int);
			while (s[i] != 'd' && s[i] != 'i')
				{
					i++;
				}
			return i;
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
		len_int = ft_strlen(dest) +1 ;
	}
	else 
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	ft_ecriture_largeur(i, y, nombre_charact_int, len_int);
	return (i);
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
		len_int = ft_strlen(dest);
	}
	else
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	ft_ecriture_point(i, y, nombre_charact_int, len_int);
	return (i);
}