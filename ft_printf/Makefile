.PHONY:		all clean fclean re

SRCS =		ft_convert_args_hexp.c	ft_convert_args_unsigned.c	ft_convert_args.c	ft_convert_hex_heX.c	ft_printf_str.c

OBJS =		${SRCS:.c=.o}

HEADER =	ft_printf.h

FLAGS =		-Wall -Wextra -Werror

NAME =		libftprintf.a

LIB =		ar rc

RM =		rm -f

all:	${NAME} Makefile

%.o:	%.c ${HEADER} Makefile
	CC ${FLAGS} -I${HEADER} -c $< -o $@

${NAME}:	${OBJS} Makefile
	${LIB} $@ ${OBJS}

clean:        
	${RM} ${OBJS}

fclean:	clean 
	${RM} ${NAME}

re:	fclean all
