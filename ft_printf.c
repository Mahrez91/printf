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
				while (s[c] != 'd' && s[c] != 'i' && s[c] != 'c')
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
	ft_printf("j'ai %.00101i ans\n", 20);
	printf("j'ai %.00101i ans", 20);
}