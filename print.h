#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

void			ft_putchar(char s);
void			ft_int(int n);
void			ft_int_pos(unsigned int n);
void			ft_chaine(char *s);
int				ft_printf(const char *s, ...);
int				ft_count(int n);
char			*ft_itoa_base_min(unsigned int n);
char			*ft_itoa_base_maj(unsigned int n);
char			*ft_write_itoa(char *s);
char			*ft_strrev(char *str);
char		    *ft_itoa_base_pointeur(unsigned int n);
void	        ft_putstr(char *str);

#endif