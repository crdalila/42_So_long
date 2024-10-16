NAME = libftprintf.a
OBJ_DIR = objects
SRC_DIR = .
SRCS =	ft_printf.c ft_printf_char.c ft_printf_str.c \
		ft_printf_number.c ft_printf_unsigned.c ft_printf_hexa.c \
		ft_printf_pointer.c \
		

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CFLAGS = -Wall -Werror -Wextra
LIBC = ar rcs

all: $(NAME)
$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@cc -c $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: clean fclean all re