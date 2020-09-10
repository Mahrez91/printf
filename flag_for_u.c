#include "Struct_d_and_i.h"
#include "print.h"

int		ft_flag_tiret_u(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	int tampon;
	int double_flag;
	int len_int;
	char *tmp = NULL;
	char *dest = NULL;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i;
	while (s[y] != 'u')
	{
		if (s[y] == '.')
		{
			double_flag = ft_flag_point_u(y + 1, s,nombre_charact_int);
			while (s[y + 1] >= '0' && s[y + 1] <= '9')
			{
				decalage.nombre_de_zero++;
				y++;
			}
			dest = ft_strlcpy(dest, s, decalage.nombre_de_zero, y - decalage.nombre_de_zero);
			tampon = ft_atoi(dest);
			y = i;
			while (s[i] >= '0' && s[i] <= '9')
			{
				decalage.nombre_d_espace++;
				i++;
			}
			tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y - 1);
			y = ft_atoi(tmp);
			dest = ft_itoa_for_u(nombre_charact_int);
			len_int = ft_strlen(dest);
			if (y > tampon)
			{
				if (tampon > len_int)
				{
					while (y - tampon > 0)
					{
						write(1," ", 1);
						y--;
					}
				}
				else
				{
					while (y - len_int > 0)
					{
						write(1," ", 1);
						y--;
					}
				}
			}
			return (double_flag);
		}
		y++;
	}
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

int		ft_flag_largeur_u(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL; 
	int len_int;
	flag decalage = {0,0};

	nombre_charact_int = ft_conversion(nombre_charact_int);
	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[y] != 'u')
	{
		if (s[y] == '.')
		{
			ft_flag_zero_u(i, s, nombre_charact_int);
			while (s[i] != 'u')
				{
					i++;
				}
			return i;
		}
		y++;
	}
	y = i-1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa_for_u(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur_u(i, y, nombre_charact_int, len_int);
	return (i);
}

int		ft_flag_point_u(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	nombre_charact_int = ft_conversion(nombre_charact_int);
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
	dest = ft_itoa_for_u(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_point_u(i, y, nombre_charact_int, len_int);
	return (i);
}

int		ft_flag_zero_u(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	int tampon;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	nombre_charact_int = ft_conversion(nombre_charact_int);
	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[y] != 'u')
	{
		if (s[y] == '.')
		{
			while (s[y + 1] >= '0' && s[y + 1] <= '9')
			{
				decalage.nombre_de_zero++;
				y++;
			}
			dest = ft_strlcpy(dest, s, decalage.nombre_de_zero, y - decalage.nombre_de_zero);
			tampon = ft_atoi(dest);
			y = i;
			while (s[i] >= '0' && s[i] <= '9')
			{
				decalage.nombre_d_espace++;
				i++;
			}
			tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y - 1);
			y = ft_atoi(tmp);
			dest = ft_itoa_for_u(nombre_charact_int);
			len_int = ft_strlen(dest);
			if (y > tampon)
			{
				if (tampon > len_int)
				{
					while (y - tampon > 0)
					{
						write(1," ", 1);
						y--;
					}
				}
				else
				{
					while (y - len_int > 0)
					{
						write(1," ", 1);
						y--;
					}
				}
			}
			else
			{
				ft_ecriture_point_u(y, tampon, nombre_charact_int, len_int);
				while (s[i] != 'u')
				{
					i++;
				}
				return i ;
			}
			ft_ecriture_double_flag_u(i, tampon, nombre_charact_int, len_int);
			while (s[i] != 'u')
				{
					i++;
				}
			return (i);
		}
		y++;
	}
	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa_for_u(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_zero_u(i, y, nombre_charact_int, len_int);
	return (i);
}
