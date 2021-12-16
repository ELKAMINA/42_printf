CC = gcc -Wall -Werror -Wextra

NAME =  libftprintf.a

SRC = ft_putchar_counting.c ft_putnbr_base.c ft_putnbr_counting.c ft_strlen.c\
		ft_putstr_counting.c ft_printf.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
