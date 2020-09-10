#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_s(int i, int y, char *string)
{	
	ft_chaine(string);
	i = i + 2;
	//if (y < 0)
	//	y = y *(-1);
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

int		ft_ecriture_largeur_s( int i, int y, char *string, int len_int)
{	
	if (y < 0)
	{
		ft_ecriture_tiret_s(i, (y * (-1)) - len_int, string);
		return (i + 2);
	}
	if (y > len_int)
	{
		y = y - len_int;
		while(y > 0)
		{
			write(1," ",1);
			y--;
		}
	}
	ft_chaine(string);
	i = i + 2;
	return i;
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