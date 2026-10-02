# get_next_line

Una biblioteca en C que lee una línea de un descriptor de archivo, devolviéndola línea por línea.

## Descripción general

`get_next_line` es un proyecto del plan de estudios de 42 school. Implementa una función que lee de un descriptor de archivo y devuelve una línea a la vez, manejando múltiples descriptores de archivo simultáneamente mediante variables estáticas.

## Estructura del Proyecto

```
gnl/
├── inc/                    # Archivos de cabecera
│   └── get_next_line.h
├── src/                    # Archivos fuente
│   ├── get_next_line.c     # Implementación principal
│   └── get_next_line_utils.c   # Funciones auxiliares
├── test/                   # Archivos de prueba
│   └── main.c
└── Makefile
```

## Compilación

```bash
make            # Construir la biblioteca (libgnl.a)
make test       # Construir el binario de prueba
make clean      # Eliminar archivos objeto
make fclean     # Eliminar biblioteca y binario de prueba
make re         # Reconstruir todo
```

## Uso

```c
#include "get_next_line.h"

int fd = open("archivo.txt", O_RDONLY);
char *linea;

while ((linea = get_next_line(fd)))
{
    printf("%s", linea);
    free(linea);
}
close(fd);
```

### Binario de Prueba

```bash
make test
./gnl_test
```

La suite de pruebas incluye:
- **FD Inválido**: Prueba con fd = -1
- **Archivo Vacío**: Prueba lectura de archivo vacío
- **Sin Permisos**: Prueba lectura de archivo sin permisos de lectura
- **Archivo Corto**: Prueba archivo sin salto de línea al final
- **Archivo Normal**: Prueba archivo con 5 líneas
- **Archivo Largo**: Prueba archivo con 1000 líneas
- **Multi-FD**: Prueba lectura alternada entre dos archivos

## API

### `get_next_line(int fd)`

Lee la siguiente línea del descriptor de archivo `fd`.

- **Parámetros**: `fd` - Descriptor de archivo del cual leer
- **Retorna**: Línea que fue leída, o `NULL` en EOF o error
- **Notas**: 
  - Se debe liberar la cadena devuelta después de usarla
  - Soporta hasta `MAX_FD` (1024) descriptores de archivo simultáneos
  - Tamaño del buffer configurable mediante la macro `BUFFER_SIZE` (por defecto: 42)

## Funciones Auxiliares

| Función | Descripción |
|---------|-------------|
| `ft_strchr` | Encuentra la primera ocurrencia de un carácter en una cadena |
| `ft_strjoin_and_replace` | Concatena dos cadenas, libera la primera |
| `ft_substr` | Extrae una subcadena de una cadena |
| `ft_strdup` | Duplica una cadena |

## Configuración

Define `BUFFER_SIZE` antes de incluir el header para cambiar el tamaño del buffer de lectura:

```c
#define BUFFER_SIZE 1024
#include "get_next_line.h"
```

## Requisitos

- Cumple con los estándares Norminette de 42 school
- Sin fugas de memoria (verificado con valgrind)
- Maneja casos extremos: fd inválido, EOF, archivos vacíos, errores de lectura

## Licencia

Proyecto de 42 School
