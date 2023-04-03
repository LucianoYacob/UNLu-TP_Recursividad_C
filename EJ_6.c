#include <stdio.h>
#include <string.h>
#include "TP1_Recursividad.h"

void imprimirNivel(int, int);

void main() {
    // Caso Normal
    mafiaChina(7, 1);
    // Caso Maximo
    // mafiaChina(9, 1);
    // Caso sin nivel: La mafia no se reune
    // mafiaChina(0, 1);
    // NivelActual != 1: Imprime al partir de dicho nivel
    // mafiaChina(9, 5);
    // Caso Maximo y Nivel Actual Maximo: Imprime ultimo nivel
    // mafiaChina(9, 9);
    // Caso Nivel Actual > Nivel Maximo: El nivel actual debe ser menor a nivel general
    // mafiaChina(9, 10);
    // Caso Nivel Unico
    // mafiaChina(1, 1);
    // Caso Mafia demasiado grande
    // mafiaChina(10, 1);
}

// 2 * nivel
void mafiaChina(int nivel, int nivelActual) {
    char *chino = "(-.-)";

    if (nivel == 1){
        imprimirNivel(nivel, nivelActual);
        printf("%s\n", chino);   
    }
    else if (nivel <= 0) {
        printf("Hoy la mafia no se reune\n");
        return;
    }
    else if(nivel < nivelActual) {
        printf("El nivel actual no puede ser mayor al nivel\n");
        return;
    }
    else if (nivel > 9){ 
        printf("La mafia es demasiado grande\n");
        return;
    }
    else if (nivelActual == 1){
        imprimirNivel(nivel, nivelActual);
        printf("%s", chino);   
    }
    else {
        char *left = "(-.";
        char *right = ".-)";
        int cantidad = (2*nivelActual)-1;
    
        imprimirNivel(nivel, nivelActual);
        
        for (int i = 0; i < cantidad; i++){
            if (i < cantidad/2) {
                printf("%s", left);
            }
            else if (i > cantidad/2) {
                printf("%s",right);
            }
            else {
                printf("%s", chino);
            }
        }
        
    }
    if (nivelActual < nivel){
        printf("\n");
        mafiaChina(nivel, nivelActual+1);
    }
}

void imprimirNivel(int nivel, int nivelActual) {
    int anchoTotal = (2*nivel);
    int espacios = ((anchoTotal-nivelActual)*2);

    printf("%i", nivelActual);

    for (int i = 0; i < espacios-nivelActual; i++) {
        printf(" ");
    }    
}