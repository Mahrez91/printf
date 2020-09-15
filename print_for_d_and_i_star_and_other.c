#include "Struct_d_and_i.h"
#include "print.h"

int		ft_print_for_d_and_i_tiret(int etoile,int etoile2, const char *s, int i, int nombre_charact_int)
{
	int c;
	int count;
	char	*tmp = NULL;
	char	*dest = NULL;

	count = 0;
	if (etoile < 0)
		etoile = etoile * (-1);
	ft_flag_tiret(i + 1, s, nombre_charact_int);
	if (s[i+ 3] >= '0' && s[i + 3] <= '9')
	{
		c = i + 2;
		while (s[i + 3] >= '0' && s[i + 3] <= '9')
		{
			count++;
			i++;
		}
		tmp = ft_strlcpy(tmp, s, count, c);
	}
	c = ft_atoi(tmp);
	if ( nombre_charact_int < 0)
	{
		dest = ft_itoa(nombre_charact_int * (-1));
		count = ft_strlen(dest) + 1;
	}
	else
	{
		dest = ft_itoa(nombre_charact_int);
		count = ft_strlen(dest);	
	}
	if (c <= count)
		c = count;
	if (etoile > c)
	{
		while (etoile != c)
		{
			write(1, " " , 1);
			etoile--;
		}
	}
	while (s[i] != 'd' && s[i] != 'i')
		i++;
	etoile2--;
	return (i + 1);
}