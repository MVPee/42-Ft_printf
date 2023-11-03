NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRC_PRINTF =	srcs/printf/ft_printf.c \
				srcs/printf/ft_putchar_fd_l.c \
				srcs/printf/ft_putstr_fd_l.c \
				srcs/printf/ft_putnbr_fd_l.c \
				srcs/printf/ft_hexadecimal.c \
				srcs/printf/ft_pointer.c \
				srcs/printf/ft_u_putnbr_fd_l.c

SRC_LIBFT =		srcs/libft/ft_isalpha.c \
				srcs/libft/ft_isdigit.c \
				srcs/libft/ft_isalnum.c \
				srcs/libft/ft_isascii.c \
				srcs/libft/ft_isprint.c \
				srcs/libft/ft_strlen.c \
				srcs/libft/ft_memset.c \
				srcs/libft/ft_bzero.c \
				srcs/libft/ft_memcpy.c \
				srcs/libft/ft_memmove.c \
				srcs/libft/ft_strlcpy.c \
				srcs/libft/ft_strlcat.c \
				srcs/libft/ft_toupper.c \
				srcs/libft/ft_tolower.c \
				srcs/libft/ft_strchr.c \
				srcs/libft/ft_strrchr.c \
				srcs/libft/ft_strncmp.c \
				srcs/libft/ft_memchr.c \
				srcs/libft/ft_memcmp.c \
				srcs/libft/ft_strnstr.c \
				srcs/libft/ft_atoi.c \
				srcs/libft/ft_calloc.c \
				srcs/libft/ft_strdup.c \
				srcs/libft/ft_substr.c \
				srcs/libft/ft_strjoin.c \
				srcs/libft/ft_strtrim.c \
				srcs/libft/ft_split.c \
				srcs/libft/ft_itoa.c \
				srcs/libft/ft_strmapi.c \
				srcs/libft/ft_striteri.c \
				srcs/libft/ft_putstr_fd.c \
				srcs/libft/ft_putchar_fd.c \
				srcs/libft/ft_putendl_fd.c \
				srcs/libft/ft_putnbr_fd.c \
				srcs/libft/ft_lstnew.c \
				srcs/libft/ft_lstadd_front.c \
				srcs/libft/ft_lstsize.c \
				srcs/libft/ft_lstlast.c \
				srcs/libft/ft_lstadd_back.c \
				srcs/libft/ft_lstdelone.c \
				srcs/libft/ft_lstclear.c \
				srcs/libft/ft_lstiter.c \
				srcs/libft/ft_lstmap.c

SRC = $(SRC_PRINTF) $(SRC_LIBFT)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
