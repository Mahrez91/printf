#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret(const char *s, int i, int y, int nombre_charact_int)
{	
	int count;

	count = 0;
	if (s[i + 1] == 'd' || s[i + 1] == 'i' )
	{
		count = ft_int(nombre_charact_int);
		i = i + 2;
	}
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

int		ft_flag_tiret(int i, const char *s,int nombre_charact_int)
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
	y = ft_atoi(tmp);
	ft_ecriture_tiret(s, i, y, nombre_charact_int);
	return (i);
}

int		ft_ecriture_largeur(const char *s, int i, int y, int nombre_charact_int, int len_int)
{	
	int count;

	count = 0;
	if (y > len_int)
		y = y - len_int;
	if (s[i] == 'd' || s[i] == 'i' )
	{
		while(y > 0)
		{
			write(1," ",1);
			y--;
		}
		count = ft_int(nombre_charact_int);
		i = i + 2;
	}
	return i;
}

int		ft_flag_largeur(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL; 
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur(s, i, y, nombre_charact_int, len_int);
	return (i);
}

int		ft_ecriture_point_and_zero(const char *s, int i, int y, int nombre_charact_int, int len_int)
{	
	int count;

	count = 0;
	if (y > len_int)
		y = y - len_int;
	if (s[i + 1] == 'd' || s[i + 1] == 'i' )
	{
		while(y > 0)
		{
			write(1,"0",1);
			y--;
		}
		count = ft_int(nombre_charact_int);
		i = i + 2;
	}
	return i;
}

int		ft_flag_point_and_zero(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i;
	while (s[i + 1] >= '0' && s[i + 1] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_point_and_zero(s, i, y, nombre_charact_int, len_int);
	return (i);
}