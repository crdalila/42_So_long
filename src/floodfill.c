/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:15:03 by dalcabre          #+#    #+#             */
/*   Updated: 2024/10/16 13:09:49 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*Para hacer el floodfill, necesitamos primero saber en qué posición
P, está nuestro jugador en el mapa que nos han dado*/
void	where_is_player(t_game *game)
{
		int y;//filas eje y
		int x;//columnas eje x

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{//en matriz bidimensional primero filas siempre
			if (game->map.map[y][x] == 'P')
				{
					game->player.x = x;
					game->player.y = y;
					game->map.map[y][x] = '0';
				}//para que podamos acceder de nuevo a esa casilla, la marcamos como vacía
				x++;
		}
		y++;
	}
}

/*esta función NO ES para mover al jugador, sino para que se haga
una simulación de si hay posibilidad de llegar del P a la E pasando
por todas las C*/
void	map_floodfill(t_game *game, int y, int x)
{//x e y son las coordenadas actuales en el mapa (la P)
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'F')
			return ;//si la celda actual es un muro o ya la hemos visitado, la función termina
		if (game->map.map[y][x] == 'C')//si la celda es una C
			game->player.coins++;//sumamos un colectable
		if (game->map.map[y][x] == 'E')//si la celda es una E
			game->player.exit = true;//salimos
		game->map.map[y][x] = 'F';//la celda donde esté el jugador se marca como F (visitado)
		map_floodfill(game, y + 1, x);//hacia abajo
		map_floodfill(game, y - 1, x);//hacia arriba
		map_floodfill(game, y, x + 1);//derecha
		map_floodfill(game, y, x - 1);//izquierda
}//se hace recursiva en las celdas vecinas de la actual
//esta función se sigue llamando hasta que no haya más celdas accesibles

/*Esta función es para verificar si se ha accedido a todas las C
y si se ha llegado a la E*/
void	map_error(t_game *game)
{
	if (game->map.coin != game->player.coins || game->player.exit == false)
		ft_error("Error\nMap is not playable");
	ft_free(game);
}
