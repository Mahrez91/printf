#include "Struct_d_and_i.h"
#include "print.h"


int	ft_int_pos(unsigned int n)
{
	unsigned int i;
	int count;

	count = 0;

	if (n < 0)
	{
		i = 4294967296 - (-1 * n);
	}
	else
		i = n;
	if (i >= 10)
		count = ft_int(i / 10);
	ft_putchar(i % 10 + 48);
	return count + 1;
}

int		ft_int_for_u(unsigned int n)
{
	unsigned int i;
	static int count;

	count = 0;
	i = n;
	if (i >= 10)
		ft_int_for_u(i / 10);
	count++;
	ft_putchar(i % 10 + 48);
	return (count);
}
 
int		ft_print_for_u(int etoile, int etoile2, const char *s, int i, unsigned int nombre_charact_int)
{
	int c;
	
	c = i;
	nombre_charact_int = ft_conversion(nombre_charact_int);
	if (s[i] == '-' && s[i + 1] != '*' && s[i + 3] != '*')
	{
		i = ft_flag_tiret_u(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_u(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == '.' && s[i+1] != '*')
	{
		i = ft_flag_point_u(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] == '0')
	{
		while (s[c] == '0')
		{
			c++;
		}
		if (s[c] == '*' && s[c + 2] != '*')
		{
			if (etoile < 0)
				i = ft_ecriture_tiret_u(i, etoile - 1 , nombre_charact_int) + 2;
			else
				i = ft_flag_etoile_zero_u(etoile, c, nombre_charact_int) + 1;
		}
		if (s[c] != '*')
		{
			i = ft_flag_zero_u(i + 1, s, nombre_charact_int) + 1 ;
		}
		if (s[c] == '*' && s[c + 1] == '.' && s[c + 2] == '*')
		{
			if(etoile == 0 && etoile2 < 0 && nombre_charact_int == 0)
				write(1, "0", 1);
			if(etoile == 0 && etoile2 > 0 && nombre_charact_int == 0)
				etoile--;
			if ( etoile2 < 0 && nombre_charact_int < 0)
			{
				i = ft_flag_etoile_tiret_point_u(i, etoile , etoile - 1, nombre_charact_int) + 4;
				return (i);
			}
			if (etoile2 < 0)
				etoile2 = etoile;
			if ( etoile < 0)
			{
				if (etoile2 < 0 && nombre_charact_int == 0)
					etoile++;
				i = ft_flag_etoile_tiret_point_u(i, etoile * (-1), etoile2, nombre_charact_int) + 4;
			}
			else
			{
				if (nombre_charact_int == 0 && etoile == 0 && etoile2 != 0)
					write(1, "0", 1);
				i = ft_flag_etoile_zero_point_u(c, etoile, etoile2, nombre_charact_int) + 3;
			}
		}
	}
	if (s[i] == '*' && s[i + 2] != '*')
	{
		if (etoile < 0)
			i = ft_ecriture_tiret_u(i, etoile - 1 , nombre_charact_int) + 1;
		else
			i = ft_flag_etoile_u(etoile, i + 1, nombre_charact_int) + 1;
	}
	if (s[i] == '-' && s[i + 1] == '*' && s[i + 3] != '*')
	{
		i = ft_ecriture_tiret_u(i, etoile, nombre_charact_int) + 1;
	}
	if (s[i] == '.' && s[i + 1] == '*' )
	{
		if (nombre_charact_int != 0 || etoile != 0)
		{
			if (etoile < 0)
				etoile = 1;
			i = ft_flag_etoile_point_u(etoile, c, nombre_charact_int);
		}
		i = i + 3;
	}
	if (s[i] == '-' && s[i + 1] == '*' && s[i + 3] != '*')
	{
		i = ft_ecriture_tiret_u(i, etoile , nombre_charact_int) + 1;
	}
	if (s[i] == '-' && s[i + 1] == '*' && s[i+2] == '.' && s[i+3] == '*')
	{
		if (etoile < 0)
			etoile = etoile * (-1);
		i = ft_flag_etoile_tiret_point_u(i, etoile, etoile2, nombre_charact_int) + 4;
	}
	
	if(s[i] == '*' && s[i + 1] == '.' && s[i + 2] == '*')
	{
		if (etoile2 < 0 && nombre_charact_int == 0)
		{
				if (etoile < 0)
				etoile++;
			else
				etoile--;
		}
		if ( etoile < 0)
			i = ft_flag_etoile_tiret_point_u(i, etoile * (-1), etoile2, nombre_charact_int) + 4;
		else
		{
			i = ft_flag_etoile_zero_point_u(i, etoile, etoile2, nombre_charact_int) + 4;
		}
	}
	return (i);
}