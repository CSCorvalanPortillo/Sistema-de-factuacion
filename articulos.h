#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <stdbool.h>

void mostrarArticulos(void);
void agregarArticulos(void);
bool existeArticulo(int codigo);
bool validaStock(int codigo, int cantidad);
void estadisticaProductoEstrella(void);

#endif
