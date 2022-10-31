SRCS =  ft_printf.c ft_printf_utils.c ft_printf_utils2.c
		
OBJS = ${SRCS:.c=.o}

CC = gcc -Wall -Werror -Wextra

NAME = libftprintf.a

.c.o:
	${CC} -c $< -o ${<:.c=.o} -I.

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
		rm -f ${OBJS} ${OBJSB}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

bonus:		${NAME_B}

.PHONY: all clean fclean re bonus
