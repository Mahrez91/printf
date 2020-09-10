#include "print.h"

void	ft_chaine(char *s)
{
	int i;

	i = 0;
	if (!s || !*s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}


int main()
{	
	/*char s2[] = "salut ca va bien";
	char c = 'a';

	printf("\n\n----------NUMBERS----------\n\n");


	ft_printf("%*.*X||\n", 0, -10, 0);
	printf("%*.*X||\n\n", 0, -10, 0);
	
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";*/

	char *s = malloc(sizeof(char) * 3);
	strlcpy(s,"salut", 5);
	ft_chaine(s);

}