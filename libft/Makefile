NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

SRC			= \
	ctype/ft_isalnum.c \
	ctype/ft_isalpha.c \
	ctype/ft_isascii.c \
	ctype/ft_isdigit.c \
	ctype/ft_isprint.c \
	ctype/ft_tolower.c \
	ctype/ft_toupper.c \
	list/ft_lstadd_back.c \
	list/ft_lstadd_front.c \
	list/ft_lstclear.c \
	list/ft_lstdelone.c \
	list/ft_lstiter.c \
	list/ft_lstlast.c \
	list/ft_lstmap.c \
	list/ft_lstnew.c \
	list/ft_lstsize.c \
	io/ft_putchar_fd.c \
	io/ft_putendl_fd.c \
	io/ft_putnbr_fd.c \
	io/ft_putstr_fd.c \
	io/ft_putunbr_fd.c \
	memory/ft_atoi.c \
	memory/ft_calloc.c \
	memory/ft_itoa.c \
	memory/ft_utoa.c \
	memory/ft_ultoa_base.c \
	memory/ft_utoa_base.c \
	string/ft_bzero.c \
	string/ft_memchr.c \
	string/ft_memcmp.c \
	string/ft_memcpy.c \
	string/ft_memmove.c \
	string/ft_memset.c \
	string/ft_split.c \
	string/ft_strchr.c \
	string/ft_strcpy.c \
	string/ft_strdup.c \
	string/ft_striteri.c \
	string/ft_strjoin.c \
	string/ft_strlcat.c \
	string/ft_strlcpy.c \
	string/ft_strlen.c \
	string/ft_strmapi.c \
	string/ft_strncmp.c \
	string/ft_strndup.c \
	string/ft_strnlen.c \
	string/ft_strnstr.c \
	string/ft_strrchr.c \
	string/ft_strtrim.c \
	string/ft_substr.c \

OBJS		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus