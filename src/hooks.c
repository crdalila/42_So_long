/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:17:21 by dalcabre          #+#    #+#             */
/*   Updated: 2024/10/30 12:52:05 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    hooks(t_game *game)
{
    mlx_hook(game->mlx.window, 17, 1, close_window, game);
    mlx_hook(game->mlx.window, 2, 1, keys, game);
}
