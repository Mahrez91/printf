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

int		ft_printf(const char *s, ...)
{
	va_list list;
	int i;
	int c;

	i = 0;
	c = 0;
	va_start(list, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == '-' || s[i] = '.' || s[i] == '0' || s[i] > '0' && s[i] <= '9' || s[i] = 'd')
			{
				ft_chaine(va_arg(list, char *));
				i = i + 2;
			}
		}
		/*if (s[i] == '%' && s[i + 1] != '%')
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
		}*/
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
	int *ptr = 0;
	int *ptr2 = 0;
	ft_printf("j'ai %p %c\n", &ptr, 'a');
	printf("j'ai %p %c", &ptr2, 'a');
}