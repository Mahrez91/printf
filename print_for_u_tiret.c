#include "Struct_d_and_i.h"
#include "print.h"

int		ft_print_for_u_tiret(int etoile, int etoile2, const char *s, int i, unsigned int nombre_charact_int)
{
	int c;
	int count;
	char	*tmp = NULL;
	char	*dest = NULL;

	count = 0;
	nombre_charact_int = ft_conversion(nombre_charact_int);
	ft_flag_tiret_u(i + 1, s, nombre_charact_int);
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
	dest = ft_itoa_for_u(nombre_charact_int);
	count = ft_strlen(dest);
	if (etoile > c)
	{
		while (etoile != c)
		{
			write(1, " " , 1);
			etoile--;
		}
	}
	while (s[i] != 'u')
		i++;
	etoile2--;
	etoile--;
	return (i + 1);
}