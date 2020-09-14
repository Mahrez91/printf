#include "print.h"

/*v4oid	ft_chaine(char *s)
{
	write(1, s, strlen(s));
}*/


int main()
{	
	char s2[] = "salut ca va bien";
	//char c = 'a';

	printf("\n\n----------NUMBERS----------\n\n");


	ft_printf("%0045.50x || %00.4x || %0011.1x ||\n", 0, 0, 0);
	printf("%0045.50x || %00.4x || %0011.1x ||", 0, 0, 0);
	
	/*char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";
	char s2 [100] = "salut ca va bien";

	char *s = malloc(sizeof(char) * 4);
	strlcpy(s,"salut", 5);
	ft_chaine(s);*/
}