#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char nombres[][50], float precios[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nProducto %d nombre: ", i + 1);
        scanf(" %[^\n]", nombres[i]);

        int leido = 0;
        while (!leido) {
            printf("Precio: ");
            if (scanf("%f", &precios[i]) != 1 || precios[i] < 0) {
                printf("Entrada invalida. Ingrese un numero positivo.\n");
                while (getchar() != '\n'); // limpia el buffer
            } else {
                leido = 1;
            }
        }
    }
}

void mostrarProductos(char nombres[][50], float precios[], int n) {
    int i;
    printf("\n=== Lista de Productos ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

float calcularTotal(float precios[], int n) {
    int i;
    float total = 0;
    for (i = 0; i < n; i++) {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[], int n) {
    return calcularTotal(precios, n) / n;
}

void productoMasCaro(char nombres[][50], float precios[], int n) {
    int i, pos = 0;
    for (i = 1; i < n; i++) {
        if (precios[i] > precios[pos]) {
            pos = i;
        }
    }
    printf("\nProducto mas caro: %s - $%.2f\n", nombres[pos], precios[pos]);
}

void productoMasBarato(char nombres[][50], float precios[], int n) {
    int i, pos = 0;
    for (i = 1; i < n; i++) {
        if (precios[i] < precios[pos]) {
            pos = i;
        }
    }
    printf("Producto mas barato: %s - $%.2f\n", nombres[pos], precios[pos]);
}

void buscarProducto(char nombres[][50], float precios[], int n, char nombreBuscado[]) {
    int i, encontrado = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("\nEl precio de %s es $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nProducto no encontrado.\n");
    }
}
