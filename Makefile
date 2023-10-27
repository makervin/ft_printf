NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -g

SRC_DIR		= src
OBJ_DIR		= .obj
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC		= \
	ft_printf.c \
	ft_printf_convert.c \
	ft_printf_flags.c \
	ft_printf_parse.c \
	ft_printf_char.c \
	ft_printf_hex.c \
	ft_printf_int.c \
	ft_printf_ptr.c \
	ft_printf_str.c \

OBJS	= $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	cp -r $(LIBFT) $(NAME)
	ar rsc $@ $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	-make -C $(LIBFT_DIR) clean
	-rm -rf $(OBJ_DIR)

fclean: clean
	-make -C $(LIBFT_DIR) fclean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re