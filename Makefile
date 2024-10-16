# Nombre del ejecutable
NAME = so_long

# Directorios
OBJ_DIR = objects
SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = printf

# Archivos fuente
SRCS =	$(SRC_DIR)/so_long.c \
		$(SRC_DIR)/map.c \
		$(SRC_DIR)/player.c \
		$(SRC_DIR)/floodfill.c \

# Archivos objeto
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:$(SRC_DIR)/%.c=%.o))

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

# Bibliotecas
LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

# Incluye directorios de cabeceras de las bibliotecas
LIBFT_INC = -I$(LIBFT_DIR)
PRINTF_INC = -I$(PRINTF_DIR)

# Directorios de las bibliotecas para el linker
LIBS_DIR = -L$(LIBFT_DIR) -L$(PRINTF_DIR)

# Enlazar con las bibliotecas
LIBS = -lft -lftprintf


# Regla por defecto
all: $(NAME)

# Para crear el ejecutable
$(NAME) : $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_DIR) $(LIBS) -o $(NAME)

# Compilar archivos .c en .o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(LIBFT_INC) $(PRINTF_INC) $< -o $@

# Compilar las biblioteca Libft, printf y GNL
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)
$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

# Limpiar los archivos objeto del proyecto y las bibliotecas
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) 
	@$(MAKE) clean -C $(PRINTF_DIR)

# Limpiar los binarios
fclean: clean
	@rm -f $(NAME) $(LIBFT_A) $(PRINTF_A)

re: fclean all

# Ejecutar el programa con un argumento de mapa
run: $(NAME)
	./$(NAME) $(MAP)

.PHONY: clean fclean all re run