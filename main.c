#include <stdio.h>
#include "archivos.h"
#include "clientes.h"
#include "articulos.h"
#include "facturacion.h"

int main()
{
    int op;

    crearArchivos(); // Verifica que existan los archivos, si no los crea

    do
    {
        op = menu();

        switch (op)
        {
        case MOSTRAR_CLI:
            mostrarClientes();
            break;
        case MOSTRAR_ART:
            mostrarArticulos();
            break;
        case AGREGAR_CLI:
            agregarClientes();
            break;
        case AGREGAR_ART:
            agregarArticulos();
            break;
        case FACTURAR:
            facturar();
            break;
        case ESTADISTICAS:
            estadisticaProductoEstrella();
            break;
        case MOSTRAR_ORDENADO:
            ordenarYMostrar();
            break;
        case MOSTRAR_FAC:
            mostrarFacturas();
            break;
        case SALIR:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while (op != SALIR);

    return 0;
}
