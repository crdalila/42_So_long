/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:49:08 by dalcabre          #+#    #+#             */
/*   Updated: 2024/10/30 12:16:47 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2); //función para escribir un str en un fd concreto (salida de errores)
	exit(1); //salida de error
}

void	ft_free(t_game *game) //lo miramos luego
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
	game->map.map = NULL;
}

int		main(int argc, char **argv)
{
	t_game game;

	
	if (argc != 2)
		ft_error("Error!\nNot enough arguments");
	ft_bzero(&game, sizeof(t_game)); //inicializamos t_game a 0 antes de usarlo para evitar errores
	map_is_ber(argv[1]);
	is_map_ok(argv[1], &game);
	ber_to_matrix(argv[1], &game);
	check_map_walls(&game);
	check_map_content(&game);
	where_is_player(&game);
	map_floodfill(&game, game.player.y, game.player.x);
	map_error(&game);
	is_map_ok(argv[1], &game);//para abrir el mapa de nuevo después de comprobar si se puede jugar
	game.mlx = mlx_init();//funcion predeterminada para inicializar el mlx
	game.mlx_window = mlx_new_window(game.mlx, game.map.x * 128,
			game.map.y * 128, "title of the game");//para abrir una ventana, función predeterminada
	hooks(&game);
	//images(&game);
	mlx_loop(game.mlx);//para seguir jugando
	return (0);
}
