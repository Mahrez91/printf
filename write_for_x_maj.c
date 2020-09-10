#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_x_maj(int i, int y, char *dest, int len_int)
{	

	ft_putstr(dest);
	i = i + 2;
	if (y >= len_int)
	{
		y = y - len_int;
		while (y > 0)
		{
			write(1," ",1);
			y--;
		}	
	}
	return (i );
}

int		ft_ecriture_largeur_x_maj(int i, int y, char *dest, int len_int)
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

int		ft_ecriture_point_x_maj(int i, int y, char *dest, int len_int, int nombre_charact_int)
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
int		ft_ecriture_zero_x_maj(int i, int y, char *dest, int len_int, int nombre_charact_int)
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
	{	
		ft_putstr(dest);
		return (i + 2);
	}
	if (nombre_charact_int == 0)
		write(1, "0", 1);
	i = i + 2;
	return i;
}

int		ft_ecriture_double_flag_x_maj(int i, int y, int unsigned nombre_charact_int,int len_int)
{	
	while(y > len_int)
	{
		write(1,"0",1);
		y--;
	}
	
	ft_flag_x_maj(nombre_charact_int);
	return (i + 2);
}

int		ft_ecriture_tiret_point_etoile_x_maj(int i, int y,int len_int)
{		
	if (y < 0)
		y = y *(-1);
	if (y >= len_int)
	{
		y = y - len_int + 1;
		while (y > 1)
		{
			write(1," ",1);
			y--;
		}	
	}
	return i;
}

int		ft_ecriture_zero_point_etoile_x_maj(int i, int y,unsigned int nombre_charact_int, int len_int)
{	
	if (y > len_int)
	{
		y = y - len_int;
		if (nombre_charact_int == 0)
			y--;
		while(y > 0)
		{
			write(1," ",1);
			y--;
		}
	}
	i = i + 2;
	return i;
}