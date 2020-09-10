#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret(int i, int y, int nombre_charact_int)
{	
	int count;

	count = ft_int(nombre_charact_int);
	i = i + 2;
	
	if (y < 0)
		y = y *(-1);
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

int		ft_ecriture_largeur( int i, int y, int nombre_charact_int, int len_int)
{	
	if (y < 0)
	{
		ft_ecriture_tiret(i, y, nombre_charact_int);
		return (i + 2);
	}
	if (nombre_charact_int == 0)
		y--;
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

int		ft_ecriture_zero(int i, int y, int nombre_charact_int, int len_int)
{	
	if (nombre_charact_int < 0)
	{	
		write(1, "-", 1);
		nombre_charact_int = nombre_charact_int * (-1); 
	}
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
		ft_int(nombre_charact_int);
	if (nombre_charact_int == 0)
		write(1, "0", 1);
	i = i + 2;
	return i;
}

int		ft_ecriture_point(int i, int y, int nombre_charact_int, int len_int)
{	
	int tmp;

	tmp = y;
	if (nombre_charact_int < 0)
	{	
		write(1, "-", 1);
		nombre_charact_int = nombre_charact_int * (-1); 
	}
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
		ft_int(nombre_charact_int);
	i = i + 2;
	return i;
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

int		ft_ecriture_tiret_point_etoile(int i, int y,int len_int)
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

int		ft_ecriture_zero_point_etoile(int i, int y, int nombre_charact_int, int len_int)
{	
	/*if (nombre_charact_int < 0)
	{	
		write(1, "-", 1);
		nombre_charact_int = nombre_charact_int * (-1); 
	}*/
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