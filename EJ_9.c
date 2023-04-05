#include <stdio.h>
#include "TP1_Recursividad.h"

void main(){
    // divisiblePor7(999999);
    // divisiblePor7(32291);
    // divisiblePor7(110);
    // divisiblePor7(7863);
    // divisiblePor7(-32291);
    divisiblePor7(0);
}

// 78756 -> 6*2 = 12 -> 7875 - 12 = 7863 -> repito
void divisiblePor7(int numero){
    if (numero > 99999) {
        printf("El numero ingresado debe ser mayor a 0 y menor a 100.000\n");
        return;
    }
    if (numero < 70){
        if (numero % 7 == 0) printf("El numero es divisible por 7\n");
        else printf("El numero NO es divisible por 7\n");
        return;
    }

    // Obtengo el ultimo digito
    int ultimoDigito = numero % 10;
    // Multiplico el ultimo digito por 2
    int producto = ultimoDigito * 2;
    // Obtengo el resto de numeros quitando el ultimo
    int restoDigito = numero / 10;
    // Al resto obtenido anteriormente le resto el producto
    int resultado = restoDigito - producto;

    // y repito hasta que resultado sea < a 70
    divisiblePor7(resultado);
}