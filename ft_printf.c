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
			c = i;
			if (s[i + 1] == '-' || s[i + 1] == '.' || s[i + 1] == '0' || (s[i + 1] > '0' && s[i + 1] <= '9'))
			{	
				while (s[c] != 'd' && s[c] != 'i' && s[c] != 'c' && s[c] != 's' && s[c] != 'u' && s[c] != 'p')
				{	
					c++;
				}
				if (s[c] == 'd'|| s[c] == 'i')
				{
					i = ft_print_for_d_and_i(va_arg(list, int), s, i + 1);

				}
				if(s[c] == 'c')
				{
					i = ft_print_for_c(va_arg(list, int), s, i + 1);
				}
				if(s[c] == 's')
				{
					i = ft_print_for_s(va_arg(list, char *), s, i + 1);
				}
				if(s[c] == 'u')
				{
					i = ft_print_for_u(va_arg(list,unsigned int), s, i + 1);
				}
				if(s[c] == 'p')
				{
					i = ft_print_for_p(va_arg(list,unsigned int), s, i + 1);
				}
			}
			if (s[i + 1] == 'd' || s[i + 1] == 'i')
			{
				ft_int(va_arg(list, int));
				i = i + 2;
			}
			if (s[i + 1] == 'c')
			{
				ft_putchar(va_arg(list, int));
				i = i + 2;
			}
			if (s[i + 1] == 's')
			{
				ft_chaine(va_arg(list, char*));
				i = i + 2;
			}
			if (s[i + 1] == 'u')
			{
				ft_int_for_u(va_arg(list, unsigned int));
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
	//char s2[] = "salut ca va bien";
	//int *ptr = 0;
	printf("\n\n----------STRINGS----------\n\n");

 	ft_printf("%-25d|| %d || %.13d || %0019d|| %14d || %-49.50d || %14.32d || %-12.8d || %-2.8d || %14.8d \n", 10, 23,24,26,14,258,23,1,21,12);
	printf("%-25d|| %d || %.13d || %0019d|| %14d || %-49.50d || %14.32d || %-12.8d || %-2.8d || %14.8d ", 10, 23,24,26,14,258,23,1,21,12);

}