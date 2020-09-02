#include "Struct_d_and_i.h"
#include "print.h"

int		ft_print_for_x_maj(unsigned int nombre_charact_int, const char *s, int i)
{
	if (s[i] == '-')
	{
		i = ft_flag_tiret_x_maj(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_x_maj(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == '.')
	{
		i = ft_flag_point_x_maj(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] == '0')
	{
		i = ft_flag_zero_x_maj(i + 1, s, nombre_charact_int) + 1;
	}
	if(s[i] == 'X')
	{
		ft_flag_x_maj(nombre_charact_int);
	}
	return (i);
}