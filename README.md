# 42_So_long

## Primeros pasos: pseudocódigo

Decidí centrarme en lo que ya sabía de otros proyectos: **cómo leer el mapa**. Para empezar, tenía que comprobar si el mapa que me daban era .ber y, si lo era, si cumplía con las características del ejercicio.
Para ello, cree **map.c** con pseudo-código.
```
void    map_exists(char *argv)
{
	si argv[1] no termina en .ber;
		error;
	si es compatible, is_map_ok;
}
```
```
void    is_map_ok(char *argv)
{
	¿cuando lo abrimos el mapa tiene contenido?;
		no, error;
		sí, siguiente comprobación;
   	¿todas las columnas y filas miden igual?;
		no, error;
 		sí, siguiente;
	¿tiene al menos 3 filas?;
  		no, error;
  		si, siguiente;
	check_map_content;
}
```
```
void	check_map_content(char *argv)
{
	¿la primera y la última fila es todo 1?
   		no, error
   		si, siguiente;
	¿el resto de filas empiezan y terminan por 1?
    		no, error
    		sí, siguiente
	¿en las filas de enmedio hay una E?
        	no, error
        	sí, siguiente
    	¿en las filas de enmedio tienen una P position?
        	no, error
		sí, siguiente
    	¿en las filas de enmedio check content tiene al menos un C?
        	no, error
        	sí, floodfill.
    	map_floodfill(argv[1]);
}
```
```
void map_floodfill(char *argv)
{ 
    hay camino válido desde P hasta E? (parsing)
        no, error No valid map
        sí, mapa válido
}
```

## Cosas a entender **antes** de empezar:
### Estructuras
Para juegos con gráficos y mapas, o incluso para proyectos más complejos, es coveniente crear estructuras.

> Las estructuras son un tipo de dato que **permite almacenar valores dentro de una misma variable**. Es una forma de agrupar datos bajo un mismo nombre, de forma que sea accesible desde todas las funciones del proyecto.

**¿Cómo se define?**
Tienen una estructura muy concreta, y debemos definirla en nuestra librería .h personalizada
```
typedef struct s_map
{
	char	**map;
	int	x;
	int	y;
} t_map;
```
En este ejemplo, **struct s_map** es la palabra clave y el nombre de la estructura, que en la salida utilizaremos como **t_map**, un alias para no tener que estar llamando a struct s_map todo el tiempo. Suele ser aconsejable utilizar s_nombre en origen y t_nombre en salida para indicar que son estructuras.
Dentro del t_map, encontramos distintas variables agrupadas que tienen que ver con (en este caso) el mapa:
- Una matriz
- Eje x
- Eje y

**¿Cómo accedemos a una variable dentro de la estructura?**
En nuestro código, tendremos que usar como argumento t_map *mapa (o el nombre que le queramos poner a nuestra estructura t_map). Para acceder a la variable x, por ejemplo, dentro del código utilizaríamos:
```
mapa->x;
```
### Matriz


