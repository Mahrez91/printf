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

	i = 0;
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
				ft_itoa_base(va_arg(list, int));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'c')
			{
				ft_character(va_arg(list, int));
				i = i + 2;
			}
		}
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'd')
			{
				ft_int(va_arg(list, int));
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
	int b = 123;
	int c = 123;
	ft_printf("salut %s mahrez j'ai %x an%c", "je m'appel", 2596, 's');
}