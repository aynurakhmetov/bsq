NAME = bsq
GCC = gcc -Wall -Wextra -Werror -o
LIB = ft_decrypt.c main.c ft_io.c ft_mass.c bsq_base.c bsq_print.c bsq_test.c bsq_cons.c
HEAD = list.h

all: $(NAME)

$(NAME):
	$(GCC) $(NAME) $(LIB)
clean:
	rm -f bsq
	
fclean: clean
	rm -f $(NAME)
