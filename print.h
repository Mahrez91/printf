#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

void			ft_putchar(char s);
void			ft_chaine(char *s);
int				ft_printf(const char *s, ...);
int				ft_count(int n);
int				ft_int(int n);
int				ft_int_pos(unsigned int n);
int				ft_int_for_u(unsigned int n);
int				ft_conversion(unsigned int n);
int				ft_strlen(char *s);
int				ft_conversion(unsigned int n);
int				ft_flag_tiret(int i, const char *s,int nombre_charact_int);
int				ft_flag_largeur(int i, const char *s,int nombre_charact_int);
int				ft_flag_zero(int i, const char *s,int nombre_charact_int);
int				ft_flag_point(int i, const char *s,int nombre_charact_int);
int				ft_flag_etoile(int i, int nombre_charact_int, int etoile);
int				ft_flag_etoile_zero(int i,int nombre_charact_int, int etoile);
int				ft_flag_etoile_point(int i,int nombre_charact_int, int etoile);
int				ft_ecriture_tiret(int i, int y, int nombre_charact_int);
int				ft_print_for_d_and_i(int etoile, const char *s, int i, int nombre_charact_int);
int				ft_flag_point_s(int i, const char *s,char *string);
int				ft_flag_largeur_s(int i, const char *s,char *string);
int				ft_flag_tiret_s(int i, const char *s,char *string);
int				ft_flag_etoile_s(int etoile, int i,char *string);
int				ft_flag_etoile_tiret_s(int etoile, int i, char *string);
int				ft_flag_etoile_point_s(int etoile, int i,char *string);
int				ft_print_for_s(int etoile, const char *s, int i, char *string);
int				ft_flag_tiret_c(int i, const char *s,int character);
int				ft_flag_largeur_c(int i, const char *s,int character);
int				ft_ecriture_largeur_c(int i, int y, int character);
int				ft_ecriture_tiret_c(int i, int y, int character);
int				ft_print_for_c(int etoile, const char *s,int i, int character);
int				ft_flag_tiret_x(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_x(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_point_x(int i, const char *s,int nombre_charact_int);
int				ft_flag_zero_x(int i, const char *s,int nombre_charact_int);
char			*ft_flag_x_min(unsigned int n);
int				ft_flag_etoile_zero_x_min(int etoile, int i, int nombre_charact_int);
int				ft_flag_tiret_etoile_x_min(int etoile, int i, unsigned int nombre_charact_int);
int				ft_flag_etoile_point_x_min(int etoile, int i, int nombre_charact_int);
int				ft_flag_etoile_x_min(int etoile, int i, unsigned int nombre_charact_int);
int				ft_print_for_x_min(int etoile, const char *s, int i, unsigned int nombre_charact_int);
int				ft_flag_tiret_x_maj(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_x_maj(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_zero_x_maj(int i, const char *s,int nombre_charact_int);
int				ft_flag_point_x_maj(int i, const char *s,int nombre_charact_int);
char			*ft_flag_x_maj(unsigned int n);
int				ft_flag_etoile_x_maj(int etoile, int i, unsigned int nombre_charact_int);
int				ft_flag_tiret_etoile_x_maj(int etoile, int i, unsigned int nombre_charact_int);
int				ft_flag_etoile_zero_x_maj(int etoile, int i, int nombre_charact_int);
int				ft_flag_etoile_point_x_maj(int etoile, int i, int nombre_charact_int);
int				ft_print_for_x_maj(int etoile, const char *s, int i, unsigned int nombre_charact_int);
int				ft_flag_tiret_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_point_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_zero_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_etoile_u(int etoile, int i,unsigned int nombre_charact_int);
int				ft_ecriture_tiret_u(int i, int y, unsigned int nombre_charact_int);
int				ft_flag_etoile_zero_u(int etoile, int i, unsigned int nombre_charact_int);
int				ft_flag_etoile_point_u(int etoile, int i, unsigned int nombre_charact_int);
int				ft_print_for_u(int etoile, const char *s, int i, unsigned int nombre_charact_int);
int				ft_flag_largeur_p(int i, const char *s,void * nombre_charact_int);
int				ft_flag_tiret_p(int i, const char *s,void * nombre_charact_int);
int				ft_flag_p(void * nombre_charact_int, int i);
int				ft_flag_etoile_p(int i, int etoile, void * nombre_charact_int);
int				ft_flag_etoile_tiret_p(int etoile, int i,void * nombre_charact_int);
int				ft_print_for_p(int etoile, const char *s, int i, void * nombre_charact_int);
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
char			*ft_itoa_for_u(unsigned int n);
char			*ft_strlcpy(char *dst, const char *src, int n, int y);
char			*ft_itoa_base_min(long n);
char			*ft_itoa_base_maj(unsigned int n);
char			*ft_strrev(char *str);
char		    *ft_itoa_base_pointeur(unsigned int n);
void	        ft_putstr(char *str);

#endif

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

/*#include "print.h"

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
			if (s[i + 1] == '*' || (s[i + 1] == '-' && s[i + 2] == '*') || (s[i + 1] == '.' && s[i + 2] == '*') )
			{
				while (s[c] != 'd' && s[c] != 'i' && s[c] != 'c' && s[c] != 'p' && s[c] != 's' && s[c] != 'u')
				{	
					c++;
				}
				if (s[c] == 'd'|| s[c] == 'i')
				{
					i = ft_print_for_d_and_i(va_arg(list, int), s, i + 1,  va_arg(list, int));
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
					i = ft_print_for_u(va_arg(list, int), s, i + 1, va_arg(list,unsigned int));
				}
			}
			if (s[i + 1] == '0' )
			{
				while (s[c] == 0)
					c++;
				if (s[c] == 'd' || s[c] == 'i')
				{
					i = ft_print_for_d_and_i(0, s, i + 1,  va_arg(list, int));
				}
				if(s[c] == 'u')
				{
					i = ft_print_for_u(0 , s, i + 1, va_arg(list,unsigned int));
				}
				if(s[c] == 'p')
				{
					i = ft_print_for_p(0, s, i + 1, va_arg(list,void *));
				}
				if (s[c] == '*')
				{
					if (s[c + 1] == 'd' || s[c] == 'i')
					{
						i = ft_print_for_d_and_i(va_arg(list, int), s, i + 1,  va_arg(list, int));
					}
					if(s[c + 1] == 'u')
					{
						i = ft_print_for_u(va_arg(list, int) , s, i + 1, va_arg(list,unsigned int));
					}
					if(s[c + 1] == 'p')
					{
						i = ft_print_for_p(va_arg(list, int), s, i + 1, va_arg(list,void *));
					}
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
					i = ft_print_for_d_and_i(0, s, i + 1,  va_arg(list, int));
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
					i = ft_print_for_u(0 , s, i + 1, va_arg(list,unsigned int));
				}
				if(s[c] == 'p')
				{
					i = ft_print_for_p(0, s, i + 1, va_arg(list,void *));
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
			if(s[i + 1] == 'X')
			{
				i = ft_print_for_x_maj(va_arg(list,unsigned int), s, i + 1);
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
	printf("\n\n----------INT----------\n\n");

	ft_printf("j'ai %00d |\n", 500);
	printf("j'ai %00d |\n",  500);
}*/