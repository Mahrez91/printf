#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

void			ft_putchar(char s);
void			ft_int(int n);
void			ft_character(char s);
void			ft_chaine(char *s);
int				ft_printf(const char *s, ...);
static int		ft_count(int n);
char			*ft_itoa_base(int n);
char			*ft_write_itoa(char *s);

#endif