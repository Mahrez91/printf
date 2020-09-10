#include "print.h"
#include "Struct_d_and_i.h"

int		ft_flag_tiret_c(int i, const char *s, int character)
{
	int			y;
	char		*tmp;
	flag decalage;

	tmp = NULL;
	decalage.nombre_d_espace = 0;
	tmp = malloc(sizeof(char) * 3);
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
	ft_ecriture_tiret_c(i, y, character);
	return (i);
}

int		ft_flag_largeur_c(int i, const char *s, int character)
{
	int			y;
	char		*tmp;
	flag decalage;

	tmp = NULL;
	decalage.nombre_d_espace = 0;
	tmp = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	ft_ecriture_largeur_c(i, y, character);
	return (i);
}
