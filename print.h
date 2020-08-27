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
int				ft_strlen(char *s);
int				ft_flag_tiret(int i, const char *s,int nombre_charact_int);
int				ft_flag_largeur(int i, const char *s,int nombre_charact_int);
int				ft_flag_point_and_zero(int i, const char *s,int nombre_charact_int);
int				ft_print_for_d_and_i(int nombre_charact_int, const char *s, int i);
int				ft_flag_point_s(int i, const char *s,char *string);
int				ft_flag_largeur_s(int i, const char *s,char *string);
int				ft_flag_tiret_s(int i, const char *s,char *string);
int				ft_flag_tiret_c(int i, const char *s,int character);
int				ft_flag_largeur_c(int i, const char *s,int character);
int				ft_flag_tiret_x(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_x(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_point_and_zero_x(int i, const char *s,int nombre_charact_int);
int				ft_flag_tiret_x_maj(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_x_maj(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_point_and_zero_x_maj(int i, const char *s,int nombre_charact_int);
int				ft_flag_tiret_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_point_and_zero_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_p(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_tiret_p(int i, const char *s,unsigned int nombre_charact_int);
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
char			*ft_strlcpy(char *dst, const char *src, int n, int y);
char			*ft_itoa_base_min(unsigned int n);
char			*ft_itoa_base_maj(unsigned int n);
char			*ft_strrev(char *str);
char		    *ft_itoa_base_pointeur(unsigned int n);
void	        ft_putstr(char *str);

#endif