#include <stdio.h>
#include <stdlib.h>
#include "TP1_Recursividad.h"

void subconjuntosQueSumanNRec(int *conjunto, int longitud, int *subconjunto, int i, int sum, int n);


int main() {
    int conjunto[] = {10, 3, 1, 7, 4, 2};
    int longitud = sizeof(conjunto) / sizeof(int);
    int n = 7;
    printf("Subconjuntos que suman %d:\n", n);
    subconjuntosQueSumanN(conjunto, longitud, n);
    n = 10;
    printf("Subconjuntos que suman %d:\n", n);
    subconjuntosQueSumanN(conjunto, longitud, n);
    return 0;
}

// conjunto = arreglo inicial de numeros
// longitud = tamaño del array conjunto
// subConjunto = arreglo aux en el que se almacenaran los numeros del conjunto que juntos suman n
// i = indice del elemento del "conjunto" que se esta recorriendo en un momento dado
// sum = suma que se actualizara cada vez q la funcion se ejecute para verificar si el resultado de la suma de los numeros es n
//n = numero a buscar como resultado de la suma de conjuntos
void subconjuntosQueSumanNRec(int *conjunto, int longitud, int *subconjunto, int i, int sum, int n) {
    // Caso base, suma = n entonces ya encontre un subconjunto
    if (sum == n) {
        // Imprimir subconjunto
        printf("{");
        for (int i = 0; i < i; i++) {
            printf("%d", subconjunto[i]);
            if (i < i - 1) {
                printf(", ");
            }
        }
        printf("}\n");
        return;
    }

    // Si ya se procesaron todos los elementos del conjunto o se supera la suma buscada, se sale de la funcion
    if (i == longitud || sum > n) {
        return;
    }

    // Incluyo el elemento actual y llamo recursivamente
    subconjunto[i] = conjunto[i];
    subconjuntosQueSumanNRec(conjunto, longitud, subconjunto, i + 1, sum + conjunto[i], n);

    // No incluiyo el elemento actual y llamar recursivamente
    subconjunto[i] = 0;
    subconjuntosQueSumanNRec(conjunto, longitud, subconjunto, i + 1, sum, n);
}

// Funcion que crea un arreglo auxiliar de int tomando la longitud del conjunto, y lo pasa a la funcion principal para almacenar los conjuntos que dan n
void subconjuntosQueSumanN(int *conjunto, int longitud, int n) {
    int *subconjunto = (int *)malloc(longitud * sizeof(int));
    subconjuntosQueSumanNRec(conjunto, longitud, subconjunto, 0, 0, n);
    free(subconjunto);
}

