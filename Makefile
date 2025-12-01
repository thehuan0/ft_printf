NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      parse/init_flags.c \
      parse/parse_flags.c \
      parse/apply_width.c \
	  parse/parse_precision.c \
      print/print_char.c \
      print/print_string.c \
      print/print_pointer.c \
      print/print_number.c \
      print/print_unsigned.c \
      print/print_hex.c \
      print/print_percent.c \
	  print/print_dispatch.c \
      utils/ft_putchar.c \
      utils/ft_putstr.c \
      utils/ft_putnbr_base.c \
      utils/ft_strlen.c \
      utils/ft_itoa.c \
      utils/ft_utoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
