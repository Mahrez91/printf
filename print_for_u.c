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

int	ft_conversion(unsigned int n)
{
	int i;

	i = n;
	if (i < 0)
	{
		i = n * (-1);
		n = 4294967296 - i;
		return(n);
	}
	return n;
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
 
int		ft_print_for_u(unsigned int nombre_charact_int, const char *s, int i)
{
	if (s[i] == '-')
	{
		i = ft_flag_tiret_u(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_u(i, s, nombre_charact_int) + 1;
	}
	if (s[i] == '.')
	{
		i = ft_flag_point_u(i + 1, s, nombre_charact_int) + 1;
	}
	if (s[i] == '0')
	{
		i = ft_flag_zero_u(i + 1, s, nombre_charact_int) + 1;
	}
	return (i);
}