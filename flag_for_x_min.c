#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_x(int i, int y, char *dest, int len_int)
{	

		ft_putstr(dest);
		i = i + 2;
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

int		ft_flag_tiret_x(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	int double_flag;
	int tampon;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	double_flag = 0;
	tampon = 0;
	y = i;
	while (s[y] != 'x')
	{
		if (s[y] == '.')
		{
			double_flag = ft_flag_point_x(y + 1, s,nombre_charact_int);
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
			dest = ft_itoa_base_min(nombre_charact_int);
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
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	y = ft_atoi(tmp);
	ft_ecriture_tiret_x( i, y, dest, len_int);
	return (i);
}

int		ft_ecriture_largeur_x( int i, int y, char *dest, int len_int)
{	
	if (y > len_int)
	{
		y = y - len_int;
		while(y > 0)
		{
			write(1," ",1);
			y--;
		}
	}
	ft_putstr(dest);
	i = i + 2;
	return i;
}

int		ft_flag_largeur_x(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL; 
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[y] != 'x')
	{
		if (s[y] == '.')
		{
			ft_flag_zero_x(i, s, nombre_charact_int);
			while (s[i] != 'x')
				{
					i++;
				}
			return i;
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
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur_x( i, y, dest, len_int);
	return (i);
}

int		ft_ecriture_zero_x(int i, int y, char *dest, int len_int, int nombre_charact_int)
{	
	if (y > len_int)
	{
		y = y - len_int;
		while(y > 0)
			{
				write(1,"0",1);
				y--;
			}	
	}
	if (nombre_charact_int != 0)
		ft_putstr(dest);
	if (nombre_charact_int == 0)
		write(1, "0", 1);
	i = i + 2;
	return i;
}

int		ft_ecriture_point_x(int i, int y, char *dest, int len_int, int nombre_charact_int)
{	
	int tmp;

	tmp = y;
	if (y > len_int)
	{
		y = y - len_int;
		while(y > 0)
			{
				write(1,"0",1);
				y--;
			}	
	}
	if (nombre_charact_int != 0 || tmp != 0)
	{	
		ft_putstr(dest);
		return (i + 2);
	}
	i = i + 2;
	return i;
}

int		ft_flag_point_x(int i, const char *s,int nombre_charact_int)
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
	len_int = ft_strlen(dest);
	ft_ecriture_point_x( i, y, dest, len_int, nombre_charact_int);
	return (i);
}

char		*ft_flag_x_min(unsigned int n)
{
	char *alpha;
	char *str;
	int i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count(n) + 1))))
		return (0);
	alpha = "0123456789abcdef";
	if (n == 0)
	{
		str[i] = '0';
		return (str);
	}
	if (n < 0)
	{
		n = 4294967296 - (-1 * n);
	}
	while (n > 0)
	{
		str[i] = alpha[n % 16];
		i++;
		n = n / 16;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	ft_putstr(str);
	return(str);
}

int		ft_ecriture_double_flag_x(int i, int y, int unsigned nombre_charact_int,int len_int)
{	
	while(y > len_int)
	{
		write(1,"0",1);
		y--;
	}
	
	ft_flag_x_min(nombre_charact_int);
	return (i + 2);
}

int		ft_flag_zero_x(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	int tampon;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	tampon = 0;
	while (s[y] != 'x')
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
			dest = ft_itoa_base_min(nombre_charact_int);
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
				ft_ecriture_point_x(y, tampon, dest, len_int, nombre_charact_int);
				while (s[i] != 'x')
				{
					i++;
				}
				return i ;
			}
			ft_ecriture_double_flag_x(i, tampon, nombre_charact_int, len_int);
			while (s[i] != 'x')
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
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_zero_x( i, y, dest, len_int, nombre_charact_int);
	return (i);
}

int		ft_flag_etoile_x_min(int etoile, int i, unsigned int nombre_charact_int)
{
	char *dest = NULL; 
	int len_int;

	dest = malloc(sizeof(char) * 3);
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur_x( i, etoile , dest, len_int);
	return (i);
}

int		ft_flag_tiret_etoile_x_min(int etoile, int i, unsigned int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = malloc(sizeof(char) * 3);
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_tiret_x(i, etoile, dest, len_int);
	return (i);
}

int		ft_flag_etoile_zero_x_min(int etoile, int i, int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = malloc(sizeof(char) * 3);
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_zero_x( i, etoile, dest, len_int, nombre_charact_int);
	return (i);
}

int		ft_flag_etoile_point_x_min(int etoile, int i, int nombre_charact_int)
{
	char *dest = NULL;
	int len_int;

	dest = malloc(sizeof(char) * 3);
	dest = ft_itoa_base_min(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_point_x( i, etoile, dest, len_int, nombre_charact_int);
	return (i);
}