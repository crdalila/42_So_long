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



