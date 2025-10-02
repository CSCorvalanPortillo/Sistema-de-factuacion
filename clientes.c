#include "clientes.h"
#include "archivos.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void mostrarClientes(void)
{
    FILE *archivo = fopen(NOMBRE_CLIENTES, "rb");
    Cliente_t cliente;

    if (!archivo)
    {
        printf("Error al abrir clientes.dat\n");
        return;
    }

    printf("Muestra registros de Clientes: Nombre, Codigo y Cuenta\n");
    while (fread(&cliente, sizeof(Cliente_t), 1, archivo))
    {
        printf("Nombre: %s, Codigo: %d, Cuenta: %.2f\n", cliente.nom_cli, cliente.cod_cli, cliente.cuenta);
    }

    fclose(archivo);
}

void agregarClientes(void)
{
    FILE *archivo = fopen(NOMBRE_CLIENTES, "ab");
    if (!archivo)
    {
        printf("Error al abrir clientes.dat\n");
        return;
    }

    Cliente_t cliente;
    int aux;
    do
    {
        printf("Introduzca el codigo del cliente [0 para salir]: ");
        scanf("%d", &aux);
        if (aux != FINALIZAR_CARGA)
        {
            cliente.cod_cli = aux;
            printf("Introduzca el nombre del cliente: ");
            limpiarBuffer();
            scanf("%[^\n]", cliente.nom_cli);
            cliente.cuenta = 0;
            fwrite(&cliente, sizeof(Cliente_t), 1, archivo);
        }

    } while (aux != FINALIZAR_CARGA);

    fclose(archivo);
}

bool existeCliente(int codigo)
{
    FILE *archivo = fopen(NOMBRE_CLIENTES, "rb");
    Cliente_t cliente;
    if (!archivo) return false;

    while (fread(&cliente, sizeof(Cliente_t), 1, archivo))
    {
        if (cliente.cod_cli == codigo)
        {
            fclose(archivo);
            return true;
        }
    }

    fclose(archivo);
    return false;
}

void ordenarYMostrar(void)
{
    FILE *fbin = fopen(NOMBRE_CLIENTES, "rb");
    FILE *ford = fopen("clientesOrd.dat", "wb+");
    if (!fbin || !ford)
    {
        printf("No se pudieron abrir los archivos\n");
        return;
    }

    Cliente_t auxiliar[100], ordenado, r;
    int i = 0;

    // Leer registros a memoria
    while (fread(&r, sizeof(Cliente_t), 1, fbin))
    {
        auxiliar[i++] = r;
    }

    // Burbujeo para ordenar por nombre
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = 0; k < i - 1 - j; k++)
        {
            if (strcmp(auxiliar[k].nom_cli, auxiliar[k + 1].nom_cli) > 0)
            {
                ordenado = auxiliar[k];
                auxiliar[k] = auxiliar[k + 1];
                auxiliar[k + 1] = ordenado;
            }
        }
    }

    // Guardar ordenados
    for (int r = 0; r < i; r++)
    {
        fwrite(&auxiliar[r], sizeof(Cliente_t), 1, ford);
    }

    // Mostrar ordenados
    rewind(ford);
    printf("\nCod. cliente\tNombre y apellido\t\tSaldo/Recaudación total\n");
    printf("---------------------------------------------------------------\n");
    while (fread(&r, sizeof(Cliente_t), 1, ford))
    {
        printf("%d\t\t%-20s\t$%.2f\n", r.cod_cli, r.nom_cli, r.cuenta);
    }

    fclose(fbin);
    fclose(ford);
}
