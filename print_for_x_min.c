#include "Struct_d_and_i.h"
#include "print.h"

int		ft_print_for_x_min(unsigned int nombre_charact_int, const char *s, int i)
{
	if (s[i] == '-')
	{
		i = ft_flag_tiret_x(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_x(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == '.')
	{
		i = ft_flag_point_x(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] == '0')
	{
		i = ft_flag_zero_x(i + 1, s, nombre_charact_int) + 1;
	}
	if(s[i] == 'x')
	{
		ft_flag_x_min(nombre_charact_int);
	}
	return (i);
}