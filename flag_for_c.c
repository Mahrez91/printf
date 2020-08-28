#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_c(int i, int y, int character)
{	
	ft_putchar(character);
	i = i + 2;
	
	while (y > 1)
	{
		write(1," ",1);
		y--;
	}	
	return i;
}

int		ft_flag_tiret_c(int i, const char *s,int character)
{
	int y;
	char *tmp = NULL;
	flag decalage = {0,0};

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

int		ft_ecriture_largeur_c(int i, int y, int character)
{	
	if (y >= 1)
		y = y - 1;
	while(y > 0)
	{
		write(1," ",1);
		y--;
	}
	ft_putchar(character);
	i = i + 2;

	return i;
}

int		ft_flag_largeur_c(int i, const char *s,int character)
{
	int y;
	char *tmp = NULL;
	flag decalage = {0,0};

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