NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC		= \
	ft_printf.c \

OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(LIBFT)
	ar rsc $@ $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	-make -C $(LIBFT_DIR) clean
	-rm -f *.o

fclean: clean
	-make -C $(LIBFT_DIR) fclean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re