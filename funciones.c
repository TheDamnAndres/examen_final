#include <stdio.h>
#include <string.h>

#define MAX_PROD 100
#define MAX_N 100
#define MAX_DESCRIP 100

void inputProducto(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int* cantidad) {
    if (*cantidad < MAX_PROD) {
        printf("Ingrese el nombre del producto: ");
        scanf(" %[^\n]", prod[*cantidad]);

        printf("Ingrese la descripcion del producto: ");
        scanf(" %[^\n]", descrip[*cantidad]);

        printf("Ingrese el precio del producto: ");
        scanf("%f", &precios[*cantidad]);

        (*cantidad)++;
        printf("Producto ingresado con exito.\n");
    } else {
        printf("No es posible ingresar más prod. Se alcanzó el límite máximo.\n");
    }
}

void editProducto(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int cantidad) {
    if (cantidad > 0) {
        int indice;
        printf("Ingrese el indice del producto a editar (0-%d): ", cantidad - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < cantidad) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf(" %[^\n]", prod[indice]);

            printf("Ingrese la nueva descripcion del producto: ");
            scanf(" %[^\n]", descrip[indice]);

            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &precios[indice]);

            printf("Producto editado con exito.\n");
        } else {
            printf("Indice invalido. No se puede editar el producto.\n");
        }
    } else {
        printf("No hay prod ingresados.\n");
    }
}

void showProductos(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int cantidad) {
    printf("\tINVENTARIO\n");

    for (int i = 0; i < cantidad; i++) {
        printf("\t\tProducto N%d \n", i+1);
        printf("Nombre: %s\n", prod[i]);
        printf("Descripcion: %s\n", descrip[i]);
        printf("Precio: %.2f\n", precios[i]);
    }

    if (cantidad == 0) {
        printf("No se encontro prod.\n");
    }
}

void eliminarProducto(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int* cantidad, int indice) {
    if (indice >= 0 && indice < *cantidad) {

        for (int i = indice; i < *cantidad - 1; i++) {
            strcpy(prod[i], prod[i + 1]);
            strcpy(descrip[i], descrip[i + 1]);
            precios[i] = precios[i + 1];
        }

        (*cantidad)--;
        printf("Producto eliminado con exito.\n");
    } else {
        printf("Indice invalido. No se puede eliminar el producto.\n");
    }
}

int loadProductos(FILE* archivo, char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[]) {
    rewind(archivo); // Volver al principio del archivo

    int cantidad = 0;
    char temporal[MAX_N + MAX_DESCRIP + 7]; // Tamaño máximo de línea en el archivo

    while (fgets(temporal, sizeof(temporal), archivo)) {
        sscanf(temporal, "%[^;];%[^;];%f", prod[cantidad], descrip[cantidad], &precios[cantidad]);
        cantidad++;
    }

    printf("Productos cargados correctamente.\n");

    return cantidad;
}

void storeProductos(FILE* archivo, char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int cantidad) {
    rewind(archivo); // Volver al principio del archivo

    for (int i = 0; i < cantidad; i++) {
        fprintf(archivo, "%s;%s;%.2f\n", prod[i], descrip[i], precios[i]);
    }

    printf("Productos guardados correctamente.\n");
}