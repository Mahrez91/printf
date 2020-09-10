#include "Struct_d_and_i.h"
#include "print.h"

int		ft_ecriture_tiret_p(int i, int y, char *dest, int len_int)
{	

	write(1, "0x", 2);
	ft_putstr(dest);
	i = i + 2;
	if (y < 0)
		y = y *(-1);
	if (y >= len_int)
	{
		y = y - len_int;
		while (y > 0)
		{

			write(1," ",1);
			y--;
		}	
	}
	return i;
}

int		ft_ecriture_largeur_p( int i, int y, char *dest, int len_int)
{	
	if (y < 0)
	{
		ft_ecriture_tiret_p(i, y, dest, len_int);
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
	write(1, "0x", 2);
	ft_putstr(dest);
	i = i + 2;
	return i;
}