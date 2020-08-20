/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:06:44 by idhiba            #+#    #+#             */
/*   Updated: 2019/12/01 15:06:46 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_putchar(char s)
{
	write(1, &s, 1);
}
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

void	ft_int(int n)
{
	unsigned int i;

	if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
	}
	else
		i = n;
	if (i >= 10)
		ft_int(i / 10);
	ft_putchar(i % 10 + 48);
}

void	ft_int_pos(unsigned int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = 4294967296 - (-1 * n);
	}
	else
		i = n;
	if (i >= 10)
		ft_int(i / 10);
	ft_putchar(i % 10 + 48);
}

void	ft_character(char s)
{
	write(1, &s, 1);
}

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

int		ft_printf(const char *s, ...)
{
	va_list list;
	int i;
	int c;
	char *tmp = NULL;

	i = 0;
	c = 0;
	va_start(list, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 's')
			{
				ft_chaine(va_arg(list, char *));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'x')
			{
				ft_itoa_base_min(va_arg(list, unsigned int));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'X')
			{
				ft_itoa_base_maj(va_arg(list, unsigned int));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == '0')
			{
				i++;
				if (s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					while (s[i + 1] >= '0' && s[i + 1] <= '9')
					{
						tmp[c] = s[i + 1];
						i++;
						c++;
					}
					ft_atoi(tmp);
				}
			}
			if (s[i + 1] == 'c')
			{
				ft_character(va_arg(list, int));
				i = i + 2;
			}
			if (s[i + 1] == 'c')
			{
				ft_character(va_arg(list, int));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'd' || s[i + 1] == 'i' )
			{
				ft_int(va_arg(list, int));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'u')
			{
				ft_int_pos(va_arg(list, unsigned int));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'p')
			{
				ft_itoa_base_pointeur(va_arg(list, unsigned int));
				i = i + 2;
			}
		}
		if (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}	
	}
	va_end(list);
	printf("\n");
	return (0);
}

int main()
{
	ft_printf("j'ai %d %s\n", 25, "ans");
	printf("j'ai %0*d %s OK ", 5, 25, "ans");
}