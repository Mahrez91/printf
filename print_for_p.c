#include "Struct_d_and_i.h"
#include "print.h"


int		ft_print_for_p(int etoile, const char *s, int i, void * nombre_charact_int)
{

	if (s[i] == '-' && s[i+1] != '*')
	{
		i = ft_flag_tiret_p(i + 1, s, nombre_charact_int) ;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_p(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == 'p')
	{
		i = ft_flag_p(nombre_charact_int, i) + 1;
	}
	if(s[i] == '*')
	{
		i = ft_flag_etoile_p(i, etoile, nombre_charact_int) + 2;
	}
	if (s[i] == '-' && s[i+1] == '*')
	{
		if (etoile == 0)
		{
			i = ft_flag_etoile_tiret_p(etoile ,i+1,  nombre_charact_int)  + 2;
			return (i);
		}
		if (etoile < 0)
			etoile = etoile *(-1);
		i = ft_flag_etoile_tiret_p(etoile ,i+1,  nombre_charact_int)  + 1;
	}
	return (i);
}
