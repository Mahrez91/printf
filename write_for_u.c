#include "Struct_d_and_i.h"
#include "print.h"

int		ft_ecriture_tiret_u(int i, int y, unsigned int nombre_charact_int)
{	
	int count;

	count = ft_int_pos(nombre_charact_int);
	i = i + 2;

	if (y < 0)
		y = y *(-1);
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

int		ft_ecriture_largeur_u(int i, int y,unsigned int nombre_charact_int, int len_int)
{	
	if (y < 0)
	{
		ft_ecriture_tiret(i, y, nombre_charact_int);
		return (i + 2);
	}
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
	ft_int_for_u(nombre_charact_int);
	i = i + 2;
	return i;
}

int		ft_ecriture_zero_u(int i, int y, unsigned int nombre_charact_int, int len_int)
{	
	if (y > len_int)
	{
		y = y - len_int;
		if (nombre_charact_int == 0)
			y--;
		while(y > 0)
		{
			write(1,"0",1);
			y--;
		}
	}
	if (nombre_charact_int != 0)
		ft_int_for_u(nombre_charact_int);
	if (nombre_charact_int == 0)
		write(1, "0", 1);
	i = i + 2;
	return i;
}

int		ft_ecriture_point_u(int i, int y, unsigned int nombre_charact_int, int len_int)
{	
	int tmp;

	tmp = y;
	if (y > len_int)
	{
		y = y - len_int;
		if (nombre_charact_int == 0)
			y--;
		while(y > 0)
		{
			write(1,"0",1);
			y--;
		}
	}
	if (nombre_charact_int != 0 || tmp != 0)
	{	
		ft_int_for_u(nombre_charact_int);
		return (i + 2);
	}
	i = i + 2;
	return i;
}

int		ft_ecriture_double_flag_u(int i, int y, unsigned int nombre_charact_int,int len_int)
{	
	while(y > len_int)
	{
		write(1,"0",1);
		y--;
	}
	
	ft_int_for_u(nombre_charact_int);
	return (i + 2);
}

int		ft_ecriture_tiret_point_etoile_u(int i, int y,int len_int)
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

int		ft_ecriture_zero_point_etoile_u(int i, int y,unsigned int nombre_charact_int, int len_int)
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
