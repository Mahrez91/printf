#include "print.h"
#include "Struct_d_and_i.h"

int		ft_flag_etoile_s(int etoile, int i, char *string)
{
	int len_int;

	len_int = ft_strlen(string);
	ft_ecriture_largeur_s(i, etoile, string, len_int);
	return (i);
}

int		ft_flag_etoile_tiret_s(int etoile, int i, char *string)
{
	etoile = etoile - ft_strlen(string);
	ft_ecriture_tiret_s(i, etoile, string);
	return (i);
}

int		ft_flag_etoile_point_s(int etoile, int i, char *string)
{
	int len_int;

	len_int = ft_strlen(string);
	i = ft_ecriture_point_s(i, etoile, string, len_int);
	return (i);
}
