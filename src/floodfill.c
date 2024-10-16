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

void	map_floodfill(char *argv, t_game *game)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'F')
			return ;
		if (game->map.map[y][x] == 'C')
			game->player.coins++;
		if (game->map.map[y][x] == 'E')
			game->player.exit = true;
		game->map.map[y][x] = 'F';
		ft_flood_fill(game, y + 1, x);
		ft_flood_fill(game, y - 1, x);
		ft_flood_fill(game, y, x + 1);
		ft_flood_fill(game, y, x - 1);
}

void	map_error(t_game *game)
{
	if (game->map.coin != game->player.coins || game->player.exit == false)
		ft_error("Error\nMap is not playable");
	ft_free(game);
}
