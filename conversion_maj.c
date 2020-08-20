#include "print.h"

char		*ft_itoa_base_maj(unsigned int n)
{
	char *alpha;
	char *str;
	int i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count(n) + 1))))
		return (0);
	alpha = "0123456789ABCDEF";
	if (n == 0)
	{
		str[i] = '0';
		return (ft_write_itoa(str));
	}
	if (n < 0)
	{
		n = 4294967296 - (-1 * n);
	}
	while (n > 0)
	{
		str[i] = alpha[n % 16];
		i++;
		n = n / 16;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return(ft_write_itoa(str));
}