#include "print.h"
#include "Struct_d_and_i.h"

int		ft_flag_etoile(int i, int nombre_charact_int, int etoile)
{
	char *dest = NULL; 
	int len_int;

	dest = malloc(sizeof(char) * 3);
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
	ft_ecriture_largeur(i, etoile, nombre_charact_int, len_int);
	return (i);
}

int		ft_flag_etoile_zero(int i,int nombre_charact_int ,int etoile)
{
	char *dest = NULL;
	int len_int;

	dest = malloc(sizeof(char) * 3);
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
	ft_ecriture_zero(i, etoile, nombre_charact_int, len_int);
	return (i);
}
int		ft_flag_etoile_point(int i,int nombre_charact_int ,int etoile)
{
	char *dest = NULL;
	int len_int;

	dest = malloc(sizeof(char) * 3);
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
	ft_ecriture_point(i, etoile, nombre_charact_int, len_int);
	return (i);
}

int		ft_flag_etoile_tiret_point(int i, int etoile,int etoile2,int nombre_charact_int)
{
	int len_int;
	char *dest = NULL;

	dest = malloc(sizeof(char) * 3);
	if (nombre_charact_int < 0)
	{
		dest = ft_itoa(nombre_charact_int * (-1));
		len_int = ft_strlen(dest)+ 1;	
		etoile2++;
	}
	else
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	if (nombre_charact_int == 0 && etoile2 < 0)
		{
			etoile--;
		}
	if (etoile >= etoile2)
		etoile = etoile - etoile2 + len_int;
	else
		etoile = 0;
	if (etoile2 < len_int)
		etoile = etoile - (len_int - etoile2);	
	ft_flag_etoile_point(i, nombre_charact_int,etoile2);
	ft_ecriture_tiret_point_etoile(i, etoile  , len_int);
	return (i);
}

int		ft_flag_etoile_zero_point(int i, int etoile,int etoile2,int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = malloc(sizeof(char) * 3);
	if (nombre_charact_int < 0)
	{
		dest = ft_itoa(nombre_charact_int * (-1));
		len_int = ft_strlen(dest) + 1;
		etoile2++;
	}
	else
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	if (nombre_charact_int == 0)
		etoile++;
	if (etoile2 < len_int)
		etoile = etoile - (len_int - etoile2);
	if (etoile > etoile2)
	{
		if (etoile >= etoile2)
			etoile = etoile - etoile2 + len_int;
		ft_ecriture_zero_point_etoile(i, etoile  , nombre_charact_int, len_int);
	}
	if (etoile2 != 0 || nombre_charact_int != 0)
		ft_ecriture_zero(i, etoile2  ,nombre_charact_int,len_int);
	return (i);
}
