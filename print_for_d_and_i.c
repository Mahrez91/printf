#include "Struct_d_and_i.h"
#include "print.h"

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strlcpy(char *dst, const char *src, int n, int y)
{
	int	i;

	i = 0; 
	while (i < n)
	{
		dst[i] = src[y + 1];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_int(int n)
{
	unsigned int i;
	static int count;
	int sign;

	sign = 0;
	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
		sign++;
	}
	else
		i = n;
	if (i >= 10)
		ft_int(i / 10);
	count++;
	ft_putchar(i % 10 + 48);
	if (sign == 0)
	{
		return (count);
	}
	else
	{
		return (count + 1);
	}
}

int		ft_print_for_d_and_i(int etoile,int etoile2, const char *s, int i, int nombre_charact_int)
{
	int c;

	c = i;
	if (s[i] == '-' && s[i+1] != '*' && s[i + 3] != '*' )
	{
		i = ft_flag_tiret(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == '.' && s[i+1] != '*')
	{
		i = ft_flag_point(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] == '0' )
	{
		while (s[c] == '0')
		{
			c++;
		}
		if (s[c] == '*' && s[c + 2] != '*')
		{
			i = ft_flag_etoile_zero(c, nombre_charact_int, etoile) + 1;
		}
		if (s[c] != '*')
		{
			i = ft_flag_zero(i + 1, s, nombre_charact_int) + 1;
		}
		if (s[c] == '*' && s[c + 1] == '.' && s[c + 2] == '*')
		{
			if(etoile == 0 && etoile2 < 0 && nombre_charact_int == 0)
				write(1, "0", 1);
			if(etoile == 0 && etoile2 > 0 && nombre_charact_int == 0)
				etoile--;
			if ( etoile2 < 0 && nombre_charact_int < 0)
			{
				i = ft_flag_etoile_tiret_point(i, etoile , etoile - 1, nombre_charact_int) + 4;
				return (i);
			}
			if (etoile2 < 0)
				etoile2 = etoile;
			if ( etoile < 0)
				i = ft_flag_etoile_tiret_point(i, etoile * (-1), etoile2, nombre_charact_int) + 4;
			else
			{
				if (nombre_charact_int == 0 && etoile == 0 && etoile2 != 0)
					write(1, "0", 1);
				i = ft_flag_etoile_zero_point(c, etoile, etoile2, nombre_charact_int) + 3;
			}
		}
	}
	if (s[i] == '*' && s[i + 1] != '.')
	{
		i = ft_flag_etoile(i + 1, nombre_charact_int, etoile) +1;
	}
	if(s[i] == '*' && s[i + 1] == '.' && s[i + 2] == '*')
	{
		/*if (etoile2 < 0)
			etoile2 = etoile;*/
		if ( etoile < 0)
			i = ft_flag_etoile_tiret_point(i, etoile * (-1), etoile2, nombre_charact_int) + 4;
		else
		{
			i = ft_flag_etoile_zero_point(c, etoile, etoile2, nombre_charact_int) + 4;
		}
	}
	if (s[i] == '-' && s[i + 1] == '*' && s[i + 3] != '*')
	{
		i = ft_ecriture_tiret(i, etoile, nombre_charact_int) + 1;
	}
	if (s[i] == '.' && s[i + 1] == '*')
	{
		if (nombre_charact_int < 0)
			etoile++;
		if (etoile < 0)
			etoile = 1;
		i = ft_flag_etoile_point(c, nombre_charact_int, etoile) + 3;
	}
	if (s[i] == '-' && s[i + 1] == '*' && s[i+2] == '.' && s[i+3] == '*')
	{
		if (etoile < 0)
			etoile = etoile * (-1);
		i = ft_flag_etoile_tiret_point(i, etoile, etoile2, nombre_charact_int) + 4;
	}
	
	return (i);
}