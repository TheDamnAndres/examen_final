#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PROD 100
#define MAX_N 100
#define MAX_DESCRIP 100

int main() {
    FILE* archivo;
    char prod[MAX_PROD][MAX_N];
    char descrip[MAX_PROD][MAX_DESCRIP];
    float precios[MAX_PROD];
    int cantidad = 0;
    int opcion;

    archivo = fopen("prod.txt", "r+"); // Abre el archivo en modo lectura y escritura de texto

    if (archivo == NULL) {

        archivo = fopen("prod.txt", "w+"); // Si el archivo no existe, se crea uno nuevo

        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            return 1;
        }
    } else {
        cantidad = loadProductos(archivo, prod, descrip, precios);
    }

    do {
        printf("------- Menu -------\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Mostrar prod\n");
        printf("4. Eliminar producto\n");
        printf("5. Guardar y salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                inputProducto(prod, descrip, precios, &cantidad);
                break;
            case 2:
                editProducto(prod, descrip, precios, cantidad);
                break;
            case 3:
                showProductos(prod, descrip, precios, cantidad);
                break;
            case 4:

                if (cantidad > 0) {
                    int indiceEliminar;
                    printf("Ingrese el indice del producto a eliminar (0-%d): ", cantidad - 1);
                    scanf("%d", &indiceEliminar);
                    eliminarProducto(prod, descrip, precios, &cantidad, indiceEliminar);
                } else {
                    printf("No hay prod ingresados.\n");
                }
                break;
            case 5:
                storeProductos(archivo, prod, descrip, precios, cantidad);
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    fclose(archivo);

    return 0;
}