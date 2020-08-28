#include "Struct_d_and_i.h"
#include "print.h"

void	ft_chaine(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}



int		ft_print_for_s(char *string, const char *s, int i)
{
	if (s[i] > '0' && s[i] <= '9')
	{
		i = ft_flag_largeur_s(i, s, string) + 1;
	}
	if (s[i] == '-')
	{
		i = ft_flag_tiret_s(i, s, string) + 2;
	}
	if (s[i] == '.')
	{
		i = ft_flag_point_s(i + 1, s, string) - 1;
	}
	return (i);
}