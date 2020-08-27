#include "Struct_d_and_i.h"
#include "print.h"

int		ft_ecriture_tiret_p(const char *s, int i, int y, char *dest, int len_int)
{	
	if (s[i + 1] == 'p')
	{
		write(1, "0x7ffe",6);
		ft_putstr(dest);
		i = i + 2;
	}
	if (y >= len_int)
	{
		y = y - len_int;
		while (y != 0)
		{
			write(1," ",1);
			y--;
		}	
	}
	return i;
}

int		ft_flag_tiret_p(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
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
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest) + 6;
	y = ft_atoi(tmp);
	ft_ecriture_tiret_p(s, i, y, dest, len_int);
	return (i);
}

int		ft_ecriture_largeur_p(const char *s, int i, int y, char *dest, int len_int)
{	
	if (y > len_int)
	{
		y = y - len_int;
		if (s[i] == 'p')
		{
			while(y > 0)
			{
				write(1," ",1);
				y--;
			}
		}
	}
	write(1, "0x7ffe",6);
	ft_putstr(dest);
	i = i + 2;
	return i;
}

int		ft_flag_largeur_p(int i, const char *s,unsigned int nombre_charact_int)
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
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest) + 6;
	ft_ecriture_largeur_p(s, i, y, dest, len_int);
	return (i);
}