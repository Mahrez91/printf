#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_largeur_s(const char *s, int i, int y, char *string, int len_int)
{	
	if (y > len_int)
	{
		y = y - len_int;
		if (s[i] == 's')
		{
			while(y > 0)
			{
				write(1," ",1);
				y--;
			}
		}
	}
	ft_chaine(string);
	i = i + 2;
	return i;
}

int		ft_flag_largeur_s(int i, const char *s,char *string)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int tampon;
	int placement;
	int len_int;
	flag decalage = {0,0};

	placement = 0;
	tampon = 0;
	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i - 1;
	while (s[y] != 's')
	{
		if (s[y] == '.')
		{
			placement = y + 1;
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
			tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace,y - 1);
			y = ft_atoi(tmp);
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
			ft_flag_point_s(placement, s,string);
			while (s[i] != 's')
			{
				i++;
			}
			return i;
		}
		y++;
	}
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

int		ft_ecriture_tiret_s(int i, int y, char *string)
{	
	ft_chaine(string);
	i = i + 2;
	if (y > 0)
	{
		while (y > 0)
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
	char *dest = NULL;
	int len_int;
	int tampon;
	int double_flag;
	flag decalage = {0,0};

	tampon = 0;
	len_int = 0;
	tmp = malloc(sizeof(char) * 3);
	dest = malloc(sizeof(char) * 3);
	y = i;
	while (s[y] != 's')
	{
		if (s[y] == '.')
		{
			double_flag =ft_flag_point_s(y + 1, s,string);
			while (s[y + 1] >= '0' && s[y + 1] <= '9')
			{
				decalage.nombre_de_zero++;
				y++;
			}
			dest = ft_strlcpy(dest, s, decalage.nombre_de_zero, y - decalage.nombre_de_zero);
			tampon = ft_atoi(dest);
			//printf("tampon = %d \n", tampon);
			y = i;
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				decalage.nombre_d_espace++;
				i++;
			}
			tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
			y = ft_atoi(tmp);
			if (ft_strlen(string) < y)
				len_int = ft_strlen(string);
			else
				len_int = y;
			//printf("len = %d \n", len_int);
			if (y > tampon)
			{
				if (tampon > len_int)
				{
					while (y - len_int > 0)
					{
						write(1," ", 1);
						y--;
					}
				}
				else 
				{
					while (len_int !=  tampon)
					{
						write(1," ", 1);
						len_int--;
					}
				}
			}
			else
			{	
				while (y > len_int)
				{
					write(1," ", 1);
					y--;
				}
			}
			while (s[i] != 's')
			{
				i++;
			}
			return (i - 1);
		}
		y++;
	}
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
	ft_ecriture_tiret_s(i, y, string);
	return (i);
}

int		ft_ecriture_point_s(int i, int y, char *string, int len_int)
{	
	int count;
	
	count = 0;
	if (y < len_int)
	{	
		while(y > 0)
		{
			ft_putchar(string[count]);
			y--;
			count++;
		}
		return (i + 2);
	}
	else
		ft_chaine(string);
	i = i + 2;
	return i;
}

int		ft_flag_point_s(int i, const char *s,char *string)
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
	y = ft_ecriture_point_s(i, y, string, len_int);
	return (y);
}