.PHONY:					all $(NAME) lib clean fclean re

NAME					=	pipex

HEADER_DIR				=	sources/pipex.h

DIR						=	sources/
SRC						=	pipex.c	pipex_utils.c	pipex_exec.c

OBJS					= $(SRC:%.c=$(DIR)%.o)
OBJS_BONUS				= $(SRC_BONUS:%.c=$(DIR_BONUS)%.o)

LIBFT					= libft.a
LIB_DIR					= libft/

GCC						= cc
CFLAGS					= -Wall -Wextra -Werror

RM						= rm -rf

%.o:					$(DIR)%.c $(HEADER_DIR)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -I/usr/include -O3 -c $< -o $@

all:					lib $(HEADER_DIR) $(NAME)

$(NAME):				$(OBJS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(OBJS) -o $(NAME) $(LIB_DIR)$(LIBFT) ft_printf/libftprintf.a

lib:
						@make -C $(LIB_DIR)
						@make -C ft_printf/

clean:
						@${RM} $(OBJS)
						@make clean -C $(LIB_DIR)
						@make clean -C ft_printf/

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)
						@make fclean -C ft_printf/

re:						fclean all
						$(MAKE) all