#include "print.h"
#include "Struct_d_and_i.h"

int		ft_ecriture_tiret_c(int i, int y, int character)
{	
	ft_putchar(character);
	i = i + 2;
	if (y < 0)
		y = y *(-1);
	while (y > 1)
	{
		write(1," ",1);
		y--;
	}	
	return i;
}

int		ft_ecriture_largeur_c(int i, int y, int character)
{	
	if (y < 0)
	{
		ft_ecriture_tiret_c(i, y, character);
		return (i + 2);
	}
	if (y >= 1)
		y = y - 1;
	while(y > 0)
	{
		write(1," ",1);
		y--;
	}
	ft_putchar(character);
	i = i + 2;

	return i;
}