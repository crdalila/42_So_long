# 42_So_long


Primeros pasos:
Mapa
Tiene que ser un .ber, único argumento a la hora de ejecutar, y con al menos estas opciones:
  0 - Espacio vacío
  1 - Muro (tiene que rodear el mapa sí o sí)
  C - Coleccionable (no mínimo)
  E - Exit (una)
  P - Posición original del jugador (uno)
Ejemplo de mapa válido:
1111111111111
1001000000001
1000011111001
10P011E000001
1111111111111

Por otro lado, sabemos que:
  Todas las filas tienen que medir lo mismo
  Todas las columnas tienen que medir lo mismo
  Ha de haber una forma de completar el juego, un camino válido (parsing)

Para eso, cree map.c en pseudo-código
void    map_exists(char *argv)
{
    int fd; //para abrir docu
    int	len;

	len = ft_strlen(argv); //por qué no argv[1]??
	if (ft_strncmp(&argv[len - 4], ".ber", 4) != 0) //si no termina en .ber
		ft_error("Error\nIncorrect file type"); //error

    fd = open(argv, O_RDONLY);
    if (fd < 0) //si no es compatible 
        error
    //si es compatible
    is_map_ok;
}

void    is_map_ok(char *argv)
{
    todas las columnas y filas miden igual?
    hay camino válido? //parsing
        tiene al menos una E exit?
        tiene una P position?
    check walls está rodeado de 1?
    check content tiene al menos un C?
}



18/09

#include "../so_long.h" //en la carpeta anterior

void    map_exists(char *argv)
{
    int	len;

	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[len - 4], ".ber", 4) != 0) //si no termina en .ber
		ft_error("Error!\nIncorrect file type\n");
}

void    is_map_ok(char *argv, t_game *game)
{
    int     fd; //para abrir docu
    char    *line; //para chequear lineas
    char    *temp

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) //si no es compatible
        ft_error("Error!\nMap not found\n");
    line = get_next_line(fd); //si es compatible, mira las líneas
    if (!line)
        ft_error("Error!\nEmpty map\n");
    game->map.x = ft_strlen(line) - 1;//calcula long de la línea sin el \n final y lo guarda en map.x
    while (line != NULL) //
    {
        if (ft_strlen(line) == '\n') //sustituir los \n por \0
            line[ft_strlen(line) - 1] = '\0';
        if (ft_strlen(line) != game->map.x)//columnas miden igual
            ft_error("Error!\nIrregular map\n");
        game->map.y++;//para leer el resto de filas
        temp = line;//para liberar la línea actual y que se pueda apuntar a la siguiente
        line = get_next_line(fd);
        free(temp);
        close(fd);
    }


    tiene al menos 3 filas?
        no, error
        si, siguiente
    todas las filas y columnas miden igual?
        no, error
        sí, siguiente
    la primera y la última fila es todo 1?
        no, error
        si, siguiente
    el resto de filas empiezan y terminan por 1?
        no, error
        sí, siguiente
        check_map_content
}

void    check_map_content(char *argv)
{   
    las filas de enmedio hay una E?
        no, error
        sí, siguiente
    las filas de enmedio tienen una P position?
            no, error
        sí, siguiente
    las filas de enmedio check content tiene al menos un C?
            no, error
        sí, floodfill.
}

void    map_floodfill(char *argv)
{
    hay camino válido desde P hasta E? //parsing
    no, error  No valid map
    sí, mapa válido
}

y en el .h

#ifndef SO_LONG_H
# define SO_LONG_H

//libraries
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

//estructures
typedef struct s_map
{
    char    **map; //matriz del mapa, para acceder a cada celda del mapa
    size_t  x; //ancho del mapa (columnas) es más probable que haya más columnas que filas, por eso size_t
    int     y; //altura del mapa (filas)
    char    *path; //ruta al archivo del mapa, facilita la carga del mapa desde un archivo externo
    int     character; //opcional: 
    int     count;//contador de movimientos y coleccionables
}   t_map;

typedef struct s_game
{
	t_map		map;//mapa
	t_player	player;//jugador
	t_images	images;//graficos
}	t_game;


// map.c
void    map_exists(char *argv);
void    is_map_ok(char *argv);

// so_long.c
int     main(int argc, char **argv);


#endif


y el solong.c

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2); //función para escribir un str en un fd concreto (salida de errores)
	exit(1); //salida de error
}

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_error("Error!\nNot enough arguments");
    map_exists(argv[1]);
}


