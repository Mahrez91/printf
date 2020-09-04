#include "print.h"
#include "Struct_d_and_i.h"

int		ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int nb;

	sign = 1;
	nb = 0;
	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v' ||
		nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}

char		*ft_itoa(int n)
{
	char *alpha;
	char *str;
	int i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count(n) + 1))))
		return (0);
	alpha = "0123456789abcdef";
	if (n < 0)
	{
		n = 4294967296 - (-1 * n);
	}
	while (n > 0)
	{
		str[i] = alpha[n % 10];
		i++;
		n = n / 10;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return(str);
}

char		*ft_itoa_for_u(unsigned int n)
{
	char *alpha;
	char *str;
	int i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count(n) + 1))))
		return (0);
	alpha = "0123456789abcdef";
	if (n < 0)
	{
		n = 4294967296 - (-1 * n);
	}
	while (n > 0)
	{
		str[i] = alpha[n % 10];
		i++;
		n = n / 10;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return(str);
}

int	ft_conversion(unsigned int n)
{
	int i;

	i = n;
	if (i < 0)
	{
		i = n * (-1);
		n = 4294967296 - i;
		return(n);
	}
	return n;
}