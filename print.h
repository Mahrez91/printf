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
int				ft_flag_tiret(int i, const char *s,int nombre_charact_int);
int				ft_flag_largeur(int i, const char *s,int nombre_charact_int);
int				ft_flag_zero(int i, const char *s,int nombre_charact_int);
int				ft_flag_point(int i, const char *s,int nombre_charact_int);
int				ft_flag_etoile(int i, int nombre_charact_int, int etoile);
int				ft_flag_etoile_zero(int i,int nombre_charact_int, int etoile);
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
int				ft_print_for_x_min(unsigned int nombre_charact_int, const char *s, int i);
int				ft_flag_tiret_x_maj(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_x_maj(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_zero_x_maj(int i, const char *s,int nombre_charact_int);
int				ft_flag_point_x_maj(int i, const char *s,int nombre_charact_int);
char			*ft_flag_x_maj(unsigned int n);
int				ft_print_for_x_maj(unsigned int nombre_charact_int, const char *s, int i);
int				ft_flag_tiret_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_largeur_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_point_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_zero_u(int i, const char *s,unsigned int nombre_charact_int);
int				ft_flag_etoile_u(int etoile, int i,unsigned int nombre_charact_int);
int				ft_ecriture_tiret_u(int i, int y, unsigned int nombre_charact_int);
int		ft_flag_etoile_zero_u(int etoile, int i, unsigned int nombre_charact_int);
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