#include "Struct_d_and_i.h"
#include "print.h"


int		ft_print_for_p(void * nombre_charact_int, const char *s, int i)
{
	if (s[i] == '-')
	{
		i = ft_flag_tiret_p(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_p(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == 'p')
	{
		i = ft_flag_p(nombre_charact_int, i) + 1;
	}
	return (i);
}
