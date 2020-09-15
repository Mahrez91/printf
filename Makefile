SRC=    conversion_maj.c       		\
		conversion_min.c      \
		conversion.c      \
		flag_for_c.c    \
		flag_for_d_and_i_etoile.c	\
		flag_tiret_for_s.c	\
		flag_tiret_for_u.c	\
		flag_tiret_for_x_min.c	\
		flag_tiret_for_x_maj.c	\
		flag_tiret_for_d_and_i.c	\
		flag_largeur_for_s.c	\
		flag_zero_for_u.c	\
		flag_zero_for_d_and_i.c	\
		flag_zero_for_x_min.c	\
		flag_zero_for_x_maj.c	\
		flag_for_d_and_i.c       \
		flag_for_s_etoile.c	\
		flag_for_s.c    	\
		flag_for_p.c     \
		flag_for_u_etoile.c	\
		flag_for_u.c     \
		flag_for_x_min_etoile.c	\
		flag_for_x_min.c     \
		flag_for_x_maj_etoile.c     \
		flag_for_x_maj.c     \
		print_for_x_maj.c     \
		print_for_x_min.c     \
		print_for_d_and_i.c    \
		print_for_d_and_i_star_and_other.c	\
		print_for_p.c     \
		print_for_u.c     \
		print_for_u_tiret.c	\
		ft_printf.c  \
		print_for_s.c  \
		print_for_c.c	\
		write_for_d_and_i.c	\
		write_for_p.c	\
		write_for_s.c	\
		write_for_u.c	\
		write_for_x_min.c	\
		write_for_x_maj.c	\
		write_for_c.c	\
		
NAME= libftprintf.a

OBJETS= ${SRC:.c=.o}


gcc=gcc -Werror -Wall -Wextra

%.o: %.c
	${gcc} -o $@ -c $<

$(NAME):    ${OBJETS}
			ar -rc ${NAME} $^
			ranlib ${NAME}

all: ${NAME}

re: fclean all

clean:
		rm -f ${OBJETS}

fclean: clean
		rm -f ${NAME}

.PHONY: all clean fclean re