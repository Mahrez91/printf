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

int		ft_ecriture_tiret_u(int i, int y, unsigned int nombre_charact_int)
{	
	int count;

	count = ft_int_pos(nombre_charact_int);
	i = i + 2;

	if (y >= count)
	{
		y = y - count;
		while (y != 0)
		{
			write(1," ",1);
			y--;
		}	
	}
	return i;
}

int		ft_flag_tiret_u(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	y = 0;
	if (s[i] >= '0' && s[i] <= '9')
	{
		y = i - 1;
		while (s[i] >= '0' && s[i] <= '9')
		{
			decalage.nombre_d_espace++;
			i++;
		}
		tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	}
	y = ft_atoi(tmp);
	ft_ecriture_tiret_u(i, y, nombre_charact_int);
	return (i);
}

int		ft_print_for_u(int nombre_charact_int, const char *s, int i)
{
	if (s[i] == '-')
	{
		i = ft_flag_tiret_u(i + 1, s, nombre_charact_int) + 1;
	}
	/*if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == '.' || s[i] == '0')
	{
		i = ft_flag_point_and_zero(i + 1, s, nombre_charact_int) + 1;
	}*/
	return (i);
}