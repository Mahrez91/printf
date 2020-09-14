#include "print.h"
#include "Struct_d_and_i.h"

int		ft_flag_largeur_x_maj(int i, const char *s,unsigned int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL; 
	int len_int;
	flag decalage = {0,0};

	y = i - 1;
	while (s[y] != 'X')
	{
		if (s[y] == '.')
		{
			ft_flag_zero_x_maj(i, s, nombre_charact_int);
			while (s[i] != 'X')
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
	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_largeur_x_maj( i, y, dest, len_int);
	return (i);
}

int		ft_flag_point_x_maj(int i, const char *s,int nombre_charact_int)
{
	int y;
	char *tmp = NULL;
	char *dest = NULL;
	int len_int;
	flag decalage = {0,0};

	y = i - 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		decalage.nombre_d_espace++;
		i++;
	}
	tmp = ft_strlcpy(tmp, s, decalage.nombre_d_espace, y);
	y = ft_atoi(tmp);
	dest = ft_itoa_base_maj(nombre_charact_int);
	len_int = ft_strlen(dest);
	ft_ecriture_point_x_maj( i, y , dest, len_int , nombre_charact_int);
	return (i);
}

char		*ft_flag_x_maj(unsigned int n)
{
	char *alpha;
	char *str;
	int i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count(n) + 1))))
		return (0);
	alpha = "0123456789ABCDEF";
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
