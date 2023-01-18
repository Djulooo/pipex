.PHONY:		all clean fclean re bonus

SRCS	=	ft_isascii.c	ft_memcmp.c	ft_putendl_fd.c	ft_strdup.c	ft_strlen.c	ft_substr.c	\
			ft_bzero.c	ft_isdigit.c	ft_memcpy.c	ft_putnbr_fd.c	ft_striteri.c	ft_strmapi.c	ft_tolower.c	\
			ft_calloc.c	ft_isprint.c	ft_memmove.c	ft_putstr_fd.c	ft_strjoin.c	ft_strnstr.c	ft_toupper.c	\
			ft_isalnum.c	ft_itoa.c	ft_memset.c	ft_split.c	ft_strlcat.c	ft_strrchr.c	ft_isalpha.c	\
			ft_memchr.c	ft_putchar_fd.c	ft_strchr.c	ft_strlcpy.c	ft_strtrim.c	ft_strncmp.c	ft_atoi.c

OBJS	=	${SRCS:.c=.o}

B_SRCS	=	ft_lstsize.c	ft_lstnew.c	ft_lstlast.c	ft_lstadd_front.c	ft_lstadd_back.c	ft_lstdelone.c	\
			ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

B_OBJS	= 	${B_SRCS:.c=.o}

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	libft.h

LIB		=	${AR} rc

NAME	=	libft.a

all:		${NAME} Makefile

%.o:		%.c ${HEADER} Makefile
			${CC} ${FLAGS} -I${HEADER} -c $< -o $@

${NAME}:	${OBJS}
			${LIB} $@ ${OBJS}

bonus:		${B_OBJS} ${OBJS}
			${LIB} ${NAME} ${OBJS} ${B_OBJS}

clean:
			${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all