#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char nombres[10][50];
    float precios[10];
    int n = 0;
    int opcion;
    char nombreBuscado[50];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Ingresar productos\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Calcular precio total del inventario\n");
        printf("4. Calcular precio promedio\n");
        printf("5. Producto mas caro\n");
        printf("6. Producto mas barato\n");
        printf("7. Buscar producto por nombre\n");
        printf("8. Salir\n");

        int valido = 0;
        while (!valido) {
            printf("Seleccione una opcion: ");
            if (scanf("%d", &opcion) != 1) {
                printf("Entrada invalida. Debe ingresar un numero.\n");
                while (getchar() != '\n');
            } else {
                valido = 1;
            }
        }

        switch (opcion) {
            case 1: {
                int leido = 0;
                while (!leido) {
                    printf("Cuantos productos desea ingresar? (1-10): ");
                    if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
                        printf("Entrada invalida. Ingrese un número entre 1 y 10.\n");
                        while (getchar() != '\n');
                    } else {
                        leido = 1;
                    }
                }
                ingresarProductos(nombres, precios, n);
                break;
            }
            case 2:
                if (n > 0) mostrarProductos(nombres, precios, n);
                else printf("\nPrimero ingrese productos.\n");
                break;
            case 3:
                if (n > 0)
                    printf("\nPrecio total: $%.2f\n", calcularTotal(precios, n));
                else
                    printf("\nNo hay productos registrados.\n");
                break;
            case 4:
                if (n > 0)
                    printf("\nPrecio promedio: $%.2f\n", calcularPromedio(precios, n));
                else
                    printf("\nNo hay productos registrados.\n");
                break;
            case 5:
                if (n > 0)
                    productoMasCaro(nombres, precios, n);
                else
                    printf("\nNo hay productos registrados.\n");
                break;
            case 6:
                if (n > 0)
                    productoMasBarato(nombres, precios, n);
                else
                    printf("\nNo hay productos registrados.\n");
                break;
            case 7:
                if (n > 0) {
                    printf("\nIngrese el nombre del producto a buscar: ");
                    scanf(" %[^\n]", nombreBuscado);
                    buscarProducto(nombres, precios, n, nombreBuscado);
                } else {
                    printf("\nNo hay productos registrados.\n");
                }
                break;
            case 8:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
        }

    } while (opcion != 8);

    return 0;
}
