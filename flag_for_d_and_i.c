#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret(int i, int y, int nombre_charact_int)
{	
	int count;

	count = ft_int(nombre_charact_int);
	i = i + 2;
	
	if (y >= count)
	{
		y = y - count + 1;
		while (y > 1)
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
	int tampon;
	int double_flag;
	int len_int;
	char *tmp = NULL;
	char *dest = NULL;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i;
	while (s[y] != 'd' && s[y] != 'i')
	{
		if (s[y] == '.')
		{
			double_flag = ft_flag_point(y + 1, s,nombre_charact_int);
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
			if (nombre_charact_int < 0)
			{
				dest = ft_itoa(nombre_charact_int * (-1));
				len_int = ft_strlen(dest) +1 ;
			}
			else 
			{
				dest = ft_itoa(nombre_charact_int);
				len_int = ft_strlen(dest);
			}
			//printf("len = %d \n", len_int);
			//printf("y = %d \n",y);
			//printf("tmp = %d \n", tampon);
			if (y > tampon)
			{
				if (tampon > len_int)
				{
					while (y - tampon > 1)
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
	ft_ecriture_tiret(i, y, nombre_charact_int);
	return (i);
}


int		ft_ecriture_largeur( int i, int y, int nombre_charact_int, int len_int)
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
	ft_int(nombre_charact_int);
	i = i + 2;
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
	while (s[y] != 'd' && s[y] != 'i')
	{
		if (s[y] == '.')
		{
			ft_flag_zero(i, s, nombre_charact_int);
			while (s[i] != 'd' && s[i] != 'i')
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
	if (nombre_charact_int < 0)
	{
		dest = ft_itoa(nombre_charact_int * (-1));
		len_int = ft_strlen(dest) +1 ;
	}
	else 
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	ft_ecriture_largeur(i, y, nombre_charact_int, len_int);
	return (i);
}

int		ft_ecriture_point_and_zero(int i, int y, int nombre_charact_int, int len_int)
{	
	if (nombre_charact_int < 0)
	{	
		write(1, "-", 1);
		nombre_charact_int = nombre_charact_int * (-1); 
	}
	if (y > len_int)
	{
		y = y - len_int;
		while(y > 0)
		{
			write(1,"0",1);
			y--;
		}
	}
	ft_int(nombre_charact_int);
	i = i + 2;
	return i;
}

int		ft_flag_point(int i, const char *s,int nombre_charact_int)
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
	if (nombre_charact_int < 0)
	{
		dest = ft_itoa(nombre_charact_int * (-1));
		len_int = ft_strlen(dest);
	}
	else
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	ft_ecriture_point_and_zero(i, y, nombre_charact_int, len_int);
	return (i);
}

int		ft_ecriture_double_flag(int i, int y, int nombre_charact_int,int len_int)
{	
	if (nombre_charact_int < 0)
	{	
		write(1, "-", 1);
		nombre_charact_int = nombre_charact_int * (-1); 
	}
	while(y > len_int)
	{
		write(1,"0",1);
		y--;
	}
	
	ft_int(nombre_charact_int);
	return (i + 2);
}

int		ft_flag_zero(int i, const char *s,int nombre_charact_int)
{
	int y;
	int tampon;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[y] != 'd' && s[y] != 'i')
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
			//printf("tmp = %d \n", tampon);
			y = i;
			//printf("s[i] = %c \n", s[i]);
			while (s[i] >= '0' && s[i] <= '9')
			{
				decalage.nombre_d_espace++;
				i++;
			}
			tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y - 1);
			y = ft_atoi(tmp);
			if (nombre_charact_int < 0)
			{
				dest = ft_itoa(nombre_charact_int * (-1));
				len_int = ft_strlen(dest) ;
			}
			else 
			{
				dest = ft_itoa(nombre_charact_int);
				len_int = ft_strlen(dest) ;
			}
			//printf("y = %d \n", len_int);
			if (y > tampon)
			{
				if (tampon > len_int)
				{
					while (y - tampon > 1)
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
				ft_ecriture_point_and_zero(y, tampon, nombre_charact_int, len_int);
				while (s[i] != 'd' && s[i] != 'i')
				{
					i++;
				}
				return i ;
			}
			//printf("s = %c \n", s[i]);
			i = ft_ecriture_double_flag(i, tampon, nombre_charact_int, len_int) ;
			//printf("s1 = %c \n", s[i]);
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
	if (nombre_charact_int < 0)
	{
		dest = ft_itoa(nombre_charact_int * (-1));
		len_int = ft_strlen(dest) + 1;
	}
	else
	{
		dest = ft_itoa(nombre_charact_int);
		len_int = ft_strlen(dest);
	}
	ft_ecriture_point_and_zero(i, y, nombre_charact_int, len_int);
	return (i);
}