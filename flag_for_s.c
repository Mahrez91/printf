#include "print.h"
#include "Struct_d_and_i.h"

int		ft_flag_point_s(int i, const char *s, char *string)
{
	int y;
	char *tmp = NULL;
	char dest[7] = "(null)";
	int len_int;
	flag decalage = {0, 0};

	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	len_int = ft_strlen(string);
	if (string == NULL)
	{
		y = ft_ecriture_point_s(i, y, dest, 7);
		return (y);
	}
	y = ft_ecriture_point_s(i, y, string, len_int);
	return (y);
}
