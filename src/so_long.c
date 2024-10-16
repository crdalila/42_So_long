/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:49:08 by dalcabre          #+#    #+#             */
/*   Updated: 2024/10/08 13:09:24 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2); //función para escribir un str en un fd concreto (salida de errores)
	exit(1); //salida de error
}

int		main(int argc, char **argv)
{
	t_game game;

	
	if (argc != 2)
		ft_error("Error!\nNot enough arguments");
	map_is_ber(argv[1]);
	is_map_ok(argv[1], &game);
	ber_to_matrix(argv[1], &game);
	check_map_walls(&game);
	check_map_content(&game);
	write(1, "Successful map\n", 15);
	return (0);
}
