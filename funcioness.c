#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char nombres[][50], float precios[], int cantidades[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nProducto %d nombre: ", i + 1);
        scanf(" %[^\n]", nombres[i]);

        int leido = 0;
        while (!leido) {
            printf("Precio: ");
            if (scanf("%f", &precios[i]) != 1 || precios[i] < 0) {
                printf("Entrada invalida. Ingrese un numero positivo.\n");
                while (getchar() != '\n');
            } else {
                leido = 1;
            }
        }

        leido = 0;
        while (!leido) {
            printf("Cantidad: ");
            if (scanf("%d", &cantidades[i]) != 1 || cantidades[i] < 0) {
                printf("Entrada invalida. Ingrese una cantidad valida (entero positivo).\n");
                while (getchar() != '\n');
            } else {
                leido = 1;
            }
        }
    }
}

void mostrarProductos(char nombres[][50], float precios[], int cantidades[], int n) {
    int i;
    printf("\n=== Inventario de Productos ===\n");
    printf("-------------------------------------------------\n");
    printf(" N | %-20s | %-8s | %-8s\n", "Nombre", "Precio", "Cantidad");
    printf("-------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%2d | %-20s | $%-7.2f | %-8d\n", i + 1, nombres[i], precios[i], cantidades[i]);
    }
    printf("-------------------------------------------------\n");
}

float calcularTotal(float precios[], int cantidades[], int n) {
    int i;
    float total = 0;
    for (i = 0; i < n; i++) {
        total += precios[i] * cantidades[i];
    }
    return total;
}

float calcularPromedio(float precios[], int cantidades[], int n) {
    float total = calcularTotal(precios, cantidades, n);
    int totalProductos = 0, i;
    for (i = 0; i < n; i++) {
        totalProductos += cantidades[i];
    }
    return totalProductos > 0 ? total / totalProductos : 0;
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
