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
				while (s[c] != 'd' && s[c] != 'i' && s[c] != 'c' && s[c] != 's' && s[c] != 'u' && s[c] != 'p' && s[c] != 'x' && s[c] != 'X')
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
					i = ft_print_for_p(va_arg(list,void *), s, i + 1);
				}
				if(s[c] == 'x')
				{
					i = ft_print_for_x_min(va_arg(list,unsigned int), s, i + 1);
				}
				if(s[c] == 'X')
				{
					i = ft_print_for_x_maj(va_arg(list,unsigned int), s, i + 1);
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
			if(s[i + 1] == 'x')
			{
					i = ft_print_for_x_min(va_arg(list,unsigned int), s, i + 1);
					i = i + 1;
			}
			if(s[i +1] == 'X')
			{
				i = ft_print_for_x_maj(va_arg(list,unsigned int), s, i + 1);
				i = i + 1;			
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
	int *ptr = 0;
	/*char s2[] = "salut ca va bien";
	char c = '8';	

	printf("\n\n----------INT----------\n\n");

 	ft_printf("%-25d|| %d || %.13d || %0019d|| %14d || %-49.50d || %14.32d || %-12.8d || %-2.8d || %14.8d \n", 10, 23,24,26,14,258,23,1,21,12);
	printf("%-25d|| %d || %.13d || %0019d|| %14d || %-49.50d || %14.32d || %-12.8d || %-2.8d || %14.8d \n\n", 10, 23,24,26,14,258,23,1,21,12);

	printf("\n\n----------STRINGS----------\n\n");

	ft_printf("%-25s|| %s || %.8s || %19.s|| %14s || %-49.50s || %14.32s || %-12.8s || %-2.8s || %14.8s||\n", s2, s2, s2,s2,s2, s2, s2,s2,s2, s2);
	printf("%-25s|| %s || %.8s || %19.s|| %14s || %-49.50s || %14.32s || %-12.8s || %-2.8s || %14.8s||\n\n", s2, s2, s2,s2,s2, s2, s2,s2,s2, s2);

	printf("\n\n----------CHAR----------\n\n");

	ft_printf("%-25c|| %c || %25c || %-19c|| %44c ||\n",c,c,c,c,c);
	printf("%-25c|| %c || %25c || %-19c|| %44c ||",c,c,c,c,c);

	printf("\n\n----------UNSIGNED-INT----------\n\n");

 	ft_printf("%-25u| %u || %.13u || %0019u || %14u || %-69.50u || %14.32u || %-12.8u || %-2.8u || %14.8u \n", 10, 23, 24,26,14,258,23,1,21,12);
	printf("%-25u| %u || %.13u || %0019u || %14u || %-69.50u || %14.32u || %-12.8u || %-2.8u || %14.8u \n\n", 10, 23, 24,26,14,258,23,1,21,12);

	printf("\n\n----------UNSIGNED-INT-X----------\n\n");

 	ft_printf("%-25X| %X || %.13X || %0019X || %14X || %-69.50X || %14.32X || %-12.8X || %-2.8X || %14.8X ||\n", 10, 23, 24,26,14,258,23,1,21,12);
	printf("%-25X| %X || %.13X || %0019X || %14X || %-69.50X || %14.32X || %-12.8X || %-2.8X || %14.8X ||", 10, 23, 24,26,14,258,23,1,21,12);*/

	printf("\n\n----------UNSIGNED-INT-x----------\n\n");

 	ft_printf("%25p ||\n", &ptr);
	printf("%25p ||" , &ptr);
	
}