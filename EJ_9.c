#include <stdio.h>
#include "TP1_Recursividad.h"

bool esCero(int, int); 

void main(){
    // divisiblePor7(999999);
    divisiblePor7(32291);
    // divisiblePor7(110);
    // divisiblePor7(7863);
    // divisiblePor7(-32291);
    divisiblePor7(7);
    divisiblePor7(0);
}

// 78756 -> 6*2 = 12 -> 7875 - 12 = 7863 -> repito
void divisiblePor7(int numero){
    // static i = 1, se ejecuta una unica vez en la funcion donde esta definida y su valor se mantiene hasta salir de dicho programa, asi q cuando mas abajo en el codigo cambio i a 0, la variable quedara en 0 hasta finalizar la ejecucion. Esto me permite verificar si el primer valor ingresado en la llamada a la funcion es 0. 
    static int i = 1;
    if (esCero(numero, i)){
        printf("El numero ingresado debe ser mayor a 0\n");
        return;
    }
    if (numero > 99999) {
        printf("El numero ingresado debe ser menor a 100.000\n");
        return;
    }
    if (numero < 70){
        if (numero % 7 == 0) printf("El numero es divisible por 7\n");
        else printf("El numero NO es divisible por 7\n");
        return;
    }

    i = 0;
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
    i = 1;
}

bool esCero(int num, int i) {
    bool cero = false;
    if (num == 0 && i == 1) cero = true;
    else cero = false;

    return cero;
}