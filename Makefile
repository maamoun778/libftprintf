NAME = libftprintf.a

SRCS = ft_printf.c  ft_putchar_pf.c  ft_putnbr_pf.c  ft_putstr_pf.c \
ft_puthex_pf.c   ft_putptr_pf.c  ft_putuint_pf.c 

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
