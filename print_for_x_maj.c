#include "Struct_d_and_i.h"
#include "print.h"

int		ft_print_for_x_maj(int etoile, const char *s, int i, unsigned int nombre_charact_int)
{
	int c;

	c = i;
	if(s[i] == 'X')
	{
		if (nombre_charact_int == 0)
				write(1, "0", 1);
		ft_flag_x_maj(nombre_charact_int);
	}
	if (s[i] == '-' && s[i + 1] != '*')
	{
		i = ft_flag_tiret_x_maj(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_x_maj(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == '.' && s[i + 1] != '*')
	{
		i = ft_flag_point_x_maj(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] == '0')
	{
		while (s[c] == '0')
		{
			c++;
		}
		if (s[c] == '*')
		{
			if (etoile < 0 )
			{
				i = ft_flag_tiret_etoile_x_maj(etoile * (-1), i + 1, nombre_charact_int) + 1;
			}
			else
			{
				i = ft_flag_etoile_zero_x_maj(etoile, i + 1, nombre_charact_int) + 1;
			}
		}
		else
		{
			i = ft_flag_zero_x_maj(i + 1, s, nombre_charact_int) + 1;
		}
	}
	if (s[i] == '*')
	{
		if (etoile < 0 )
		{
			i = ft_flag_tiret_etoile_x_maj(etoile * (-1), i + 1, nombre_charact_int) + 1;
		}
		else
		{
			i = ft_flag_etoile_x_maj(etoile, i + 1, nombre_charact_int) + 1;
		}	
	}
	if (s[i] == '-' && s[i + 1] == '*')
	{
		if (etoile < 0 )
		{
			i = ft_flag_tiret_etoile_x_maj(etoile * (-1), i + 1, nombre_charact_int) + 2;
		}
		else
		{
			i = ft_flag_tiret_etoile_x_maj(etoile, i + 1, nombre_charact_int) + 2;
		}
	}
	if (s[i] == '.' && s[i + 1] == '*' )
	{
		if (nombre_charact_int != 0 || etoile != 0)
		{
			if (etoile < 0)
				etoile = 1;
			i = ft_flag_etoile_point_x_maj(etoile, c, nombre_charact_int);
		}
		i = i + 3;
	}
	return (i);
}