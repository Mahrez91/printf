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


	ft_printf("%-20.20s || %10.4s || %11.20s ||\n", "", NULL, "");
	printf("%-20.20s || %10.4s || %11.20s ||", "", NULL, "");
	
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