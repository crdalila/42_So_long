/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:46:52 by dalcabre          #+#    #+#             */
/*   Updated: 2024/10/16 12:53:56 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" //en la carpeta anterior

/*¿EL mapa que nos dan es válido? (.ber)?*/
void	map_is_ber(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".ber", 4) != 0) //si no termina en .ber
		ft_error("Error!\nIncorrect file type");
}



/*Vamos a comprobar si hay algo en el .ber y si todas
las filas y columnas miden igual (es regular)*/
void	is_map_ok(char *argv, t_game *game)
{
	int		fd;//para abrir docu
	char	*line;//para chequear lineas
	char	*temp;

	fd = open(argv, O_RDONLY); //no usamos argv[1] porque en el main, ya le especificamos que es argv[1]
	if (fd < 0) //si no es compatible
		ft_error("Error!\nMap not found");
	line = get_next_line(fd); //si es compatible, mira las líneas
	if (!line)
		ft_error("Error!\nEmpty map");
	game->map.x = ft_strlen(line) - 1;//calcula long de la línea sin el \n final y lo guarda en map.x
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n') //sustituir los \n por \0
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != game->map.x)//columnas miden igual
			ft_error("Error!\nIrregular map");
		game->map.y++;//para leer el resto de filas
		temp = line;//para liberar la línea actual y que se pueda apuntar a la siguiente
		line = get_next_line(fd);
		free(temp); 
	}
	close(fd);
}



/*Necesitamos almacenar el .ber a algo que C pueda leer,
para comprobar que hay todo lo que nos pide el enunciado (E, P, 1, etc)*/
void	ber_to_matrix(char *argv, t_game *game)
{
	int		fd;
	int		i;
	char	*line;
//abrir
	fd = open(argv, O_RDONLY);//no usamos argv[1] porque en el main, ya le especificamos que es argv[1]
	if (fd < 0) //si no es compatible
		ft_error("Error!\nMap not found");
	/*Para acceder a t_game map y dentro de t_map a map
	sizeof(char *) es para sacar el tamaño de un puntero
	y lo multiplicamos por las filas que hemos calculaddo antes
	+1 por el nulo que se le añade al final de la matriz*/
//alocar memoria
	game->map.map = malloc(sizeof(char *) * (game->map.y + 1));
	if (!game->map.map)
    	return ; //termina la función sin devolver nada (porque es void) no lanzamos sms
//añadir nulo para anunciar el final de las filas	
	game->map.map[game->map.y] = NULL;
//leer líneas
	line = get_next_line(fd); //si es compatible, mira las líneas
	if (!line)
		ft_error("Error!\nEmpty map");
//pasar las líneas a la matriz	
	i = 0;
	while (i < game->map.y)
	{
		game->map.map[i] = line; //fila i, en la primera vuelta 0, 1, 2...
		line = get_next_line(fd);
		i++;
	}
	close (fd);
}

void	check_map_walls(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x; //número de columnas
	y = game->map.y; //número de filas
	while (x--) //empezamos por abajo hasta llegar a 0
	{
		if (game->map.map[0][x] != '1' || game->map.map[y - 1][x] != '1') //verificar primera y última fila
			ft_error("Error\nYou need first and last rows to be walls");
	}
	while (y--)
	{
		if (game->map.map[y][0] != '1' || game->map.map[y][game->map.x - 1] != '1') //verificar primera y última columna
			ft_error("Error\nNot closed by wall");
	}
}

void	check_map_content(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y] != NULL)//recorremos cada fila
	{
		x = 0;//reiniciamos al principio de cada fila
		while (game->map.map[y][x])//cada columna de la fila actual
		{
			if (game->map.map[y][x] == 'P')
				game->map.player = game->map.player + 1;
			else if (game->map.map[y][x] == 'E')
				game->map.exit = game->map.exit + 1;
			else if (game->map.map[y][x] == 'C')
				game->map.coin = game->map.coin + 1;
			else if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
				&& game->map.map[y][x] != '\n')//saltos de línea por si acaso se ha quedado alguna en la matriz del .ber
				ft_error("Error!\nInvalid map content");
			x++;
		}
		y++;
	}
	if (game->map.player != 1 || game->map.exit != 1 || game->map.coin < 1)
		ft_error("Error!\nYour map needs only one player, one exit and at least one coin");
}
