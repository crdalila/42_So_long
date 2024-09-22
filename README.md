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



