#include "print.h"
#include "Struct_d_and_i.h"

int		ft_flag_etoile_x_maj(int etoile, int i, unsigned int nombre_charact_int)
{
	char *dest = NULL; 
	int len_int;

	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur_x_maj( i, etoile , dest, len_int);
	return (i);
}

int		ft_flag_tiret_etoile_x_maj(int etoile, int i, unsigned int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_tiret_x_maj(i, etoile, dest, len_int);
	return (i);
}

int		ft_flag_etoile_zero_x_maj(int etoile, int i, int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_zero_x_maj( i, etoile, dest, len_int, nombre_charact_int);
	return (i);
}

int		ft_flag_etoile_point_x_maj(int etoile, int i, int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_point_x_maj( i, etoile, dest, len_int, nombre_charact_int);
	return (i);
}

int		ft_flag_etoile_tiret_point_x_maj(int i, int etoile,int etoile2,int nombre_charact_int)
{
	int len_int;
	char *dest = NULL;

	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	if (etoile >= etoile2)
		etoile = etoile - etoile2 + len_int;
	else
		etoile = 0;
	if (etoile2 < len_int)
		etoile = etoile - (len_int - etoile2);	
	ft_flag_etoile_point_x_maj(etoile2, i, nombre_charact_int);
	//if (nombre_charact_int == 0 && etoile2 < 0)
	//	etoile--;
	ft_ecriture_tiret_point_etoile_x_maj(i, etoile  , len_int);
	return (i);
}

int		ft_flag_etoile_zero_point_x_maj(int i, int etoile,int etoile2,unsigned int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	if (nombre_charact_int == 0)
		etoile++;
	if (etoile2 < len_int)
		etoile = etoile - (len_int - etoile2);
	if (etoile > etoile2)
	{
		if (etoile >= etoile2)
			etoile = etoile - etoile2 + len_int;
		ft_ecriture_zero_point_etoile_x_maj(i, etoile  , nombre_charact_int, len_int);
	}
	if (etoile2 != 0 || nombre_charact_int != 0)
	{
		ft_ecriture_zero_x_maj(i, etoile2  ,dest, len_int, nombre_charact_int);
	}
	return (i);
}