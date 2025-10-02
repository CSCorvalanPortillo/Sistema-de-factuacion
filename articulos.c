#include "articulos.h"
#include "archivos.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void mostrarArticulos(void)
{
    FILE *archivo = fopen(NOMBRE_ARTICULOS, "rb");
    Articulo_t articulo;

    if (!archivo)
    {
        printf("Error al abrir articulos.dat\n");
        return;
    }

    printf("Muestra registros de Articulos: Nombre, Codigo, Precio, Stock y Monto total facturado\n");
    while (fread(&articulo, sizeof(Articulo_t), 1, archivo))
    {
        printf("Nombre: %s, Codigo: %d, Precio: %.2f, Stock: %d, Facturado: %.2f\n",
               articulo.nom_art, articulo.cod_art, articulo.precio, articulo.stock, articulo.facturado);
    }
    fclose(archivo);
}

void agregarArticulos(void)
{
    FILE *archivo = fopen(NOMBRE_ARTICULOS, "ab");
    if (!archivo)
    {
        printf("Error al abrir articulos.dat\n");
        return;
    }

    Articulo_t articulo;
    int aux;
    do
    {
        printf("Codigo del articulo [0 para salir]: ");
        scanf("%d", &aux);
        if (aux != FINALIZAR_CARGA)
        {
            articulo.cod_art = aux;
            printf("Introduzca el nombre del articulo: ");
            limpiarBuffer();
            scanf("%[^\n]", articulo.nom_art);
            printf("Ingrese el precio unitario: ");
            scanf("%f", &articulo.precio);
            printf("Ingrese la cantidad del producto en unidades: ");
            scanf("%d", &articulo.stock);
            articulo.facturado = 0;
            fwrite(&articulo, sizeof(Articulo_t), 1, archivo);
        }
    } while (aux != FINALIZAR_CARGA);

    fclose(archivo);
}

bool existeArticulo(int codigo)
{
    FILE *archivo = fopen(NOMBRE_ARTICULOS, "rb");
    Articulo_t articulo;
    if (!archivo) return false;

    while (fread(&articulo, sizeof(Articulo_t), 1, archivo))
    {
        if (articulo.cod_art == codigo)
        {
            fclose(archivo);
            return true;
        }
    }

    fclose(archivo);
    return false;
}

bool validaStock(int codigo, int cantidad)
{
    FILE *archivo = fopen(NOMBRE_ARTICULOS, "rb");
    Articulo_t articulo;
    if (!archivo) return false;

    while (fread(&articulo, sizeof(Articulo_t), 1, archivo))
    {
        if (articulo.cod_art == codigo)
        {
            fclose(archivo);
            return (articulo.stock >= cantidad);
        }
    }
    fclose(archivo);
    return false;
}

void estadisticaProductoEstrella(void)
{
    FILE *f = fopen(NOMBRE_ARTICULOS, "rb");
    if (!f)
    {
        perror("Error abriendo archivo de artículos");
        return;
    }

    Articulo_t a, estrella;
    float max = 0;
    while (fread(&a, sizeof(Articulo_t), 1, f))
    {
        if (a.facturado > max)
        {
            max = a.facturado;
            estrella = a;
        }
    }
    fclose(f);

    if (max > 0)
    {
        printf("***Producto estrella*** Codigo: %d Nombre: %s | Facturado: %.2f\n", estrella.cod_art, estrella.nom_art, estrella.facturado);
    }
    else
    {
        printf("No hay artículos facturados aún.\n");
    }
}
