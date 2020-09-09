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
			if (s[i + 1] == '*' || (s[i + 1] == '-' && s[i + 2] == '*') ||  (s[i + 1] == '.' && s[i + 2] == '*') )
			{
				if (s[i + 3] == '.')
				{
					if (s[i + 4] == '*')
					{
						while (s[c] != 'd' && s[c] != 'i' && s[c] != 'u')
						{		
							c++;
						}
						if (s[c] == 'd'|| s[c] == 'i')
						{
							i = ft_print_for_d_and_i(va_arg(list, int), va_arg(list, int), s, i + 1,  va_arg(list, int));
						}
						if (s[c] == 'u')
						{
							i = ft_print_for_u(va_arg(list, int), va_arg(list, int), s, i + 1, va_arg(list,unsigned int));
						}
					}					
				}
				if(s[i + 2] == '.')
				{
					if (s[i + 3] == '*')
					{
						
						while (s[c] != 'd' && s[c] != 'i' && s[c] != 'u')
						{		
							c++;
						}
						if (s[c] == 'd'|| s[c] == 'i')
						{
							i = ft_print_for_d_and_i(va_arg(list, int), va_arg(list, int), s, i + 1,  va_arg(list, int));
						}
						if (s[c] == 'u')
						{
						i = ft_print_for_u(va_arg(list, int),va_arg(list, int), s, i + 1,  va_arg(list, int));
						}
					}
				}
				else
				{
					while (s[c] != 'd' && s[c] != 'i' && s[c] != 'c' && s[c] != 'p' && s[c] != 's' && s[c] != 'u' && s[c] != 'X' && s[c] != 'x')
					{		
						c++;
					}
					if (s[c] == 'd'|| s[c] == 'i')
					{
						i = ft_print_for_d_and_i(va_arg(list, int),0, s, i + 1,  va_arg(list, int));
					}
					if (s[c] == 'c')
					{
						i = ft_print_for_c(va_arg(list, int), s, i + 1, va_arg(list, int));
					}
					if(s[c] == 'p')
					{
						i = ft_print_for_p(va_arg(list,int), s, i + 1, va_arg(list,void *));
					}
					if(s[c] == 's')
					{
						i = ft_print_for_s(va_arg(list, int), s, i + 1,va_arg(list, char *));
						}
					if(s[c] == 'u')
					{
						i = ft_print_for_u(va_arg(list, int),0, s, i + 1, va_arg(list,unsigned int));
					}
					if(s[c] == 'X')
					{
						i = ft_print_for_x_maj(va_arg(list, int), s, i + 1, va_arg(list,unsigned int));
					}
					if(s[c] == 'x')
					{
						i = ft_print_for_x_min(va_arg(list, int), s, i + 1, va_arg(list,unsigned int));
					}
				}
			}
			if (s[i + 1] == '0' )
			{
				c = c + 1;
				while (s[c] == '0')
					c++;
				if (s[c] == '*' && s[c + 2] != '*')
				{
					if (s[c + 1] == 'd' || s[c + 1] == 'i')
					{
						i = ft_print_for_d_and_i(va_arg(list, int),0, s, i + 1,  va_arg(list, int));
					}
					if(s[c + 1] == 'u')
					{
						i = ft_print_for_u(va_arg(list, int) , 0, s, i + 1, va_arg(list,unsigned int));
					}
					if(s[c + 1] == 'p')
					{
						i = ft_print_for_p(va_arg(list, int), s, i + 1, va_arg(list,void *));
					}
					if(s[c + 1] == 'X')
					{
						i = ft_print_for_x_maj(va_arg(list, int), s, i + 1, va_arg(list,unsigned int));
					}
					if(s[c + 1] == 'x')
					{
						i = ft_print_for_x_min(va_arg(list, int) , s, i + 1, va_arg(list,unsigned int));
					}
				}
				if (s[c] == '*' && s[c + 2] == '*')
				{
					if (s[c + 3] == 'd' || s[c + 3] == 'i')
					{
						i = ft_print_for_d_and_i(va_arg(list, int),va_arg(list, int), s, i + 1,  va_arg(list, int));
					}
					if (s[c + 3] == 'u')
					{
						i = ft_print_for_u(va_arg(list, int),va_arg(list, int), s, i + 1,  va_arg(list, int));
					}
				}
				while (s[c] != 'd' && s[c] != 'i' && s[c] != 'u' && s[c] != 'p' && s[c] != 'x' && s[c] != 'X')
				{
					c++;
				}
				if (s[c] == 'd' || s[c] == 'i')
				{
					i = ft_print_for_d_and_i(0, 0, s, i + 1,  va_arg(list, int));
				}
				if(s[c] == 'u')
				{
					i = ft_print_for_u(0 ,0, s, i + 1, va_arg(list,unsigned int));
				}
				if(s[c] == 'p')
				{
					i = ft_print_for_p(0, s, i + 1, va_arg(list,void *));
				}
				if(s[c] == 'x')
				{
					i = ft_print_for_x_min(0 , s, i + 1, va_arg(list,unsigned int));
				}
				if(s[c] == 'X')
				{
					i = ft_print_for_x_maj(0 , s, i + 1, va_arg(list,unsigned int));
				}
			}
			if (s[i + 1] == '-' || s[i + 1] == '.' || (s[i + 1] > '0' && s[i + 1] <= '9'))
			{	
				while (s[c] != 'd' && s[c] != 'i' && s[c] != 'c' && s[c] != 's' && s[c] != 'u' && s[c] != 'p' && s[c] != 'x' && s[c] != 'X')
				{	
					c++;
				}
				if (s[c] == 'd'|| s[c] == 'i')
				{
					i = ft_print_for_d_and_i(0,0, s, i + 1,  va_arg(list, int));
				}
				if(s[c] == 'c')
				{
					i = ft_print_for_c(0, s, i + 1, va_arg(list, int));
				}
				if(s[c] == 's')
				{
					i = ft_print_for_s(0, s, i + 1,va_arg(list, char *));
				}
				if(s[c] == 'u')
				{
					i = ft_print_for_u(0 ,0, s, i + 1, va_arg(list,unsigned int));
				}
				if(s[c] == 'p')
				{
					i = ft_print_for_p(0, s, i + 1, va_arg(list,void *));
				}
				if(s[c] == 'X')
				{
					i = ft_print_for_x_maj(0 , s, i + 1, va_arg(list,unsigned int));
				}
				if(s[c] == 'x')
				{
					i = ft_print_for_x_min(0 , s, i + 1, va_arg(list,unsigned int));
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
				i = ft_print_for_x_min(0 , s, i + 1, va_arg(list,unsigned int));
				i = i + 1;
			}
			if(s[i + 1] == 'X')
			{
				i = ft_print_for_x_maj(0 , s, i + 1, va_arg(list,unsigned int));
				i = i + 1;			
			}
			if(s[i + 1] == 'p')
			{
				i = ft_print_for_p(0, s, i + 1, va_arg(list,void *));
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
	//char c = 'a';

	printf("\n\n----------NUMBERS----------\n\n");

	ft_printf("%0*.*u||\n",10,10,0);
	printf("%0*.*u||\n\n",10,10,0);
}