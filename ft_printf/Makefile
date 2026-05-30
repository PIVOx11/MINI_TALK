NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c print_integer.c print_string.c print_char.c print_uns_int.c \
	print_hexa.c hexa_convertor.c print_address.c

OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJ} 
	ar rcs ${NAME} ${OBJ}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
