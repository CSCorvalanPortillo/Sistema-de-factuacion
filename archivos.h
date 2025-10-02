#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdbool.h>

#define NOMBRE_CLIENTES "clientes.dat"
#define NOMBRE_ARTICULOS "articulos.dat"
#define NOMBRE_FACTURAS "facturas.dat"
#define MAX_CARAC 30

#define SALIR 9
#define MOSTRAR_CLI 1
#define MOSTRAR_ART 2
#define AGREGAR_CLI 3
#define AGREGAR_ART 4
#define FACTURAR 5
#define ESTADISTICAS 6
#define MOSTRAR_ORDENADO 7
#define MOSTRAR_FAC 8
#define FINALIZAR_CARGA 0

typedef struct
{
    int cod_cli;
    char nom_cli[MAX_CARAC];
    float cuenta; // acumulo el saldo o lo facturado en total a cada cliente
} Cliente_t;

typedef struct
{
    int cod_art;
    char nom_art[MAX_CARAC];
    float precio;
    int stock;       // cantidad disponible
    float facturado; // acumulo cuanto vendi en pesos de este articulo
} Articulo_t;

typedef struct
{
    int cod_cli;
    int cod_art;
    int cantidad;
    float total;
} Factura_t;

// Prototipos
int menu(void);
void crearArchivos(void);

#endif
