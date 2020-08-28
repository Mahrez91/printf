#include "Struct_d_and_i.h"
#include "print.h"

int		ft_print_for_c(int character, const char *s, int i)
{
	if (s[i] == '-')
	{
		i = ft_flag_tiret_c(i + 1, s, character) + 1;
	}
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_c(i, s, character) + 1;
	}
	return (i);
}