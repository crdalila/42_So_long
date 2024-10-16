/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:26:10 by dalcabre          #+#    #+#             */
/*   Updated: 2024/09/27 12:13:58 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_document(char *buffer, char *saved, int fd)
{
	int	chars_read; //número de characters leídos, donde guardamos el read
	
	chars_read = BUFFER_SIZE; //le pongo cualquier valor que no sea 0 xq sino no entro en el bucle
	if (ft_strlen_gnl(buffer) > 0) //si hay algo en el buffer (si hay algo de una llamada anterior)
		saved = ft_strjoin_gnl(saved, buffer);//a saved se le añade lo nuevo que hay en buffer
	while (!ft_strchr_gnl(buffer, '\n') && chars_read != 0) //mientras no haya salto de línea o hasta que ya no haya nada más que leer (chars_Read=0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE); //3 porque el buffer size es 3
		if (chars_read < 0)
		{ //por si falla el read, y vuelvo a llamar a gnl, que no guarde lo que había en el buffer
			buffer[0] = '\0';
			free(saved);
			return (NULL);
		}
		buffer[chars_read] = '\0'; //xq funciona como string
		saved = ft_strjoin_gnl(saved, buffer); //juntamos el saved y buffer 
		if (!saved)
		{
			free(saved);
			return (NULL);
		}
	}
	return (saved);
}

char	*prepare_new_line(char *saved)
{
	char	*new_line;
	int		new_size;
	
	if (ft_strchr_gnl(saved, '\n')) //si hay un \n 
		new_size = ft_strchr_gnl(saved, '\n') - saved + 1; //la linea total menos lo que hay después del salto de línea, +1 para que se ponga detrás del \n
	else
		new_size = ft_strlen_gnl(saved); //si no hay, es la línea completa
	if (new_size == 0)
	{
		free(saved);
		return (NULL);
	}
	new_line = (char *)malloc((sizeof(char) * new_size) + 1); //??????
	if (!new_line)
	{
		free(saved);
		return (NULL);
	}
	ft_memcpy_gnl (new_line, saved, new_size); //copia la línea original en la nueva
	new_line[new_size] = '\0'; //añadimos el nulo al final
	free(saved); //porque solo me interesa new_line, libero el saved
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1]; //la caja
	char			*saved; //el contenido de la caja
	
	saved = malloc(sizeof(char));//porque necesitamos iniciializarlo y da igual el valor, reservamos 1 
	if (!saved)
	{
		free (saved);
		return (NULL);
	}
	saved[0] = '\0'; //se inicializa el primer byte a \0 para asegurar que está vacío y listo para recibir datos
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(saved), NULL); //lo mismo que ponerlo en dos líneas
	saved = read_document(buffer, saved, fd);//leemos el fd
	if (saved == NULL) //gestión de errores al leer el documento
		return (NULL);
	saved = prepare_new_line(saved);
	if (saved == NULL)
		return (NULL);
	if (ft_strchr_gnl(buffer, '\n')) //si saved tiene algo más que \n hay que reservar memoria para line
	{//si hay \n en buffer, copia el contenido de después del \n al comienzo del buffer
		ft_memcpy_gnl(buffer, ft_strchr_gnl(buffer, '\n') + 1, \
			ft_strlen_gnl(ft_strchr_gnl(buffer, '\n') + 1) + 1);
	}//el strchr lo que hace es busca el primer \n y va al caracter siguiente
	//el strlen calcula cuánto mide eso
	//le añadimos +1 para el caracter nulo
	return (saved);
}

/*int	main(void)
{
	char	*line;
	printf("%s", line);
	int		fd;

	fd = open("example.txt", O_RDONLY); //abrimos documento
	if (fd == -1) //si no hay fd, error
	{
		write(2, "Can't open the file\n", 20);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL) //siempre que la línea tenga algo y no sea nula, o sea no se termine.
	{//esto hará que en cada while vayamos a una línea distinta. si lo declarámos arriba, tendríamos que poner abajo que vuelva a hacerlo cada vez que entra al while
		printf("%s\n", line);
		free(line);
	}
	close (fd);
	return (0);
}*/