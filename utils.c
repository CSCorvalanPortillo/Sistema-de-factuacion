#include "utils.h"

// Función para crear los archivos binarios si no existen
void crearArchivos(void) {
    FILE *clientes = fopen("clientes.dat", "ab+");
    if (clientes == NULL) {
        printf("Error al crear o abrir el archivo clientes.dat\n");
    } else {
        fclose(clientes);
    }

    FILE *articulos = fopen("articulos.dat", "ab+");
    if (articulos == NULL) {
        printf("Error al crear o abrir el archivo articulos.dat\n");
    } else {
        fclose(articulos);
    }

    FILE *facturas = fopen("facturas.dat", "ab+");
    if (facturas == NULL) {
        printf("Error al crear o abrir el archivo facturas.dat\n");
    } else {
        fclose(facturas);
    }
}

// Función para mostrar el menú principal y leer la opción del usuario
int menu(void) {
    int op;

    printf("\n\t\t\t BIENVENIDO REGISTRO CLIENTES S.A\n");
    printf("\n\t\t\t - MOSTRAR CLIENTES <1>\n");
    printf("\t\t\t - MOSTRAR ARTICULOS <2>\n");
    printf("\t\t\t - INGRESAR CLIENTE NUEVO <3>\n");
    printf("\t\t\t - INGRESAR ARTICULO NUEVO <4>\n");
    printf("\t\t\t - REALIZAR UNA FACTURACION <5>\n");
    printf("\t\t\t - MOSTRAR ESTADISTICAS <6>\n");
    printf("\t\t\t - MOSTRAR LISTADO CLIENTES ORDENADOS <7>\n");
    printf("\t\t\t - MOSTRAR FACTURAS <8>\n");
    printf("\t\t\t - SALIR <9>\n");
    printf("\n\t\t\t Ingrese Opcion [1-9] : ");
    scanf("%d", &op);

    return op;
}

// Función para limpiar el buffer del teclado
void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
