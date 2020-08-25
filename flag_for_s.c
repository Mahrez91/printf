#include "print.h"
#include "Struct_d_and_i.h"

int		ft_flag_point_s(int i, const char *s,char *string)
{
	while (s[i + 1] != 's')
	{
		i++;
	}
	ft_chaine(string);
	i = i + 2;
	return (i);
}

int		ft_ecriture_largeur_s(const char *s, int i, int y, char *string, int len_int)
{	
	if (y > len_int)
		y = y - len_int;
	if (s[i] == 's')
	{
		while(y > 0)
		{
			write(1," ",1);
			y--;
		}
		ft_chaine(string);
		i = i + 2;
	}
	return i;
}

int		ft_flag_largeur_s(int i, const char *s,char *string)
{
	int y;
	char *tmp = NULL;
	int len_int;
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
	len_int = ft_strlen(string);
	ft_ecriture_largeur_s(s, i, y, string, len_int);
	return (i);
}

int		ft_ecriture_tiret_s(const char *s, int i, int y, char *string)
{	
	if (s[i + 1] == 's')
	{
		ft_chaine(string);
		i = i + 2;
	}
	if (y > 0)
	{
		while (y != 0)
		{
			write(1," ",1);
			y--;
		}	
	}
	return i;
}

int		ft_flag_tiret_s(int i, const char *s,char *string)
{
	int y;
	char *tmp = NULL;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	y = 0;
	if (s[i + 1] >= '0' && s[i + 1] <= '9')
	{
		y = i;
		while (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			decalage.nombre_d_espace++;
			i++;
		}
		tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	}
	y = ft_atoi(tmp) - ft_strlen(string);
	ft_ecriture_tiret_s(s, i, y, string);
	return (i);
}