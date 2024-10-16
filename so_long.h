/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:16:39 by dalcabre          #+#    #+#             */
/*   Updated: 2024/10/16 13:12:36 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//libraries
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "libft/get_next_line.h"
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
    int     player;
    int     coin; 
    int     exit;
}   t_map;

typedef struct s_player
{
    int     x;
    int     y;
    int     coins;
    bool    exit;
    int     collect;
    int     moves;
}   t_player;

/*typedef struct s_images;
{

} t_images;*/

typedef struct s_game
{
	t_map		map;//mapa
	t_player	player;//jugador
//	t_images	images;//graficos
}	t_game;




// map.c
void    map_is_ber(char *argv);
void	is_map_ok(char *argv, t_game *game);
void	ber_to_matrix(char *argv, t_game *game);
void    check_map_walls(t_game *game);
void    check_map_content(t_game *game);

//floodfill.c
void	map_floodfill(t_game *game, int x, int y);



// so_long.c
void	ft_error(char *str);
int     main(int argc, char **argv);


#endif