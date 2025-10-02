#include "facturacion.h"
#include "archivos.h"
#include "clientes.h"
#include "articulos.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>

void mostrarFacturas(void)
{
    FILE *archivo = fopen(NOMBRE_FACTURAS, "rb");
    if (!archivo) { printf("Error abriendo facturas.dat\n"); return; }

    Factura_t f;
    printf("Muestra registros de Facturas\n");
    while (fread(&f, sizeof(Factura_t), 1, archivo))
    {
        printf("Codigo de cliente %d, Codigo de prod vendido: %d Cantidad de prod: %d Total facturacion: %.2f\n",
               f.cod_cli, f.cod_art, f.cantidad, f.total);
    }
    fclose(archivo);
}

void facturar(void)
{
    FILE *clientes = fopen(NOMBRE_CLIENTES, "rb+");
    FILE *articulos = fopen(NOMBRE_ARTICULOS, "rb+");
    FILE *facturas = fopen(NOMBRE_FACTURAS, "ab+");

    if (!clientes || !articulos || !facturas)
    {
        printf("Error abriendo archivos\n");
        return;
    }

    Factura_t factura;
    Cliente_t cliente;
    Articulo_t articulo;
    int auxcli, auxart, auxprod;
    bool existeCli, existeArt, hayStock;
    float totalFacturado;

    printf("Ingrese el numero de cliente: ");
    scanf("%d", &auxcli);

    existeCli = existeCliente(auxcli);
    if (!existeCli)
    {
        printf("El cliente no existe!\n");
        fclose(clientes);
        fclose(articulos);
        fclose(facturas);
        return;
    }

    do
    {
        printf("Ingrese el codigo del articulo [0 para salir]: ");
        scanf("%d", &auxart);
        if (auxart == 0) break;

        existeArt = existeArticulo(auxart);
        if (!existeArt)
        {
            printf("El codigo de producto no existe\n");
            continue;
        }

        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &auxprod);
        hayStock = validaStock(auxart, auxprod);
        while (!hayStock && auxprod != 0)
        {
            printf("No hay stock suficiente!\n");
            printf("Ingrese nuevamente la cantidad del producto: ");
            scanf("%d", &auxprod);
            hayStock = validaStock(auxart, auxprod);
            if (auxprod == 0)
            {
                printf("No se puede realizar la compra!\n");
                break;
            }
        }

        if (auxprod == 0) continue;

        // Actualizar stock y saldos
        rewind(articulos);
        while (fread(&articulo, sizeof(Articulo_t), 1, articulos))
        {
            if (articulo.cod_art == auxart)
            {
                articulo.stock -= auxprod;
                articulo.facturado += auxprod * articulo.precio;
                fseek(articulos, -sizeof(Articulo_t), SEEK_CUR);
                fwrite(&articulo, sizeof(Articulo_t), 1, articulos);
                fflush(articulos);
                totalFacturado = auxprod * articulo.precio;
                break;
            }
        }

        rewind(clientes);
        while (fread(&cliente, sizeof(Cliente_t), 1, clientes))
        {
            if (cliente.cod_cli == auxcli)
            {
                cliente.cuenta += totalFacturado;
                fseek(clientes, -sizeof(Cliente_t), SEEK_CUR);
                fwrite(&cliente, sizeof(Cliente_t), 1, clientes);
                fflush(clientes);
                break;
            }
        }

        // Guardar factura
        factura.cod_cli = auxcli;
        factura.cod_art = auxart;
        factura.cantidad = auxprod;
        factura.total = totalFacturado;
        fwrite(&factura, sizeof(Factura_t), 1, facturas);
        fflush(facturas);

    } while (auxart != 0);

    fclose(clientes);
    fclose(articulos);
}
