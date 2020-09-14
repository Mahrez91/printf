#include "Struct_d_and_i.h"
#include "print.h"

int		ft_flag_largeur_u(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL; 
	int len_int;
	flag decalage = {0,0};

	nombre_charact_int = ft_conversion(nombre_charact_int);
	y = i - 1;
	while (s[y] != 'u')
	{
		if (s[y] == '.')
		{
			ft_flag_zero_u(i, s, nombre_charact_int);
			while (s[i] != 'u')
				{
					i++;
				}
			return i;
		}
		y++;
	}
	y = i-1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa_for_u(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur_u(i, y, nombre_charact_int, len_int);
	return (i);
}

int		ft_flag_point_u(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	nombre_charact_int = ft_conversion(nombre_charact_int);
	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa_for_u(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_point_u(i, y, nombre_charact_int, len_int);
	return (i);
}
