NAME = libftprint.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		srcs/ft_putchar_fd_l.c \
		srcs/ft_putstr_fd_l.c \
		srcs/ft_putnbr_fd_l.c \
		srcs/ft_u_putnbr_fd_l.c \
		srcs/ft_hexadecimal.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strlen.c \
		srcs/ft_pointer.c \
		srcs/ft_int_len.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re