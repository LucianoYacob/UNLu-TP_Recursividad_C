#include <stdio.h>
#include <stdlib.h>
#include "TP1_Recursividad.h"

void main() {
    float m = -15.5;
    int n = 0;

    printf("El resultado de %f * %d es: %f\n", m, n, producto(m, n, 0));

    printf("El resultado de %d * %d es: %f\n", 7, 3, producto(7, 3, 0));
}

// El parametro res, es la respuesta final, q inicia en 0 y llega al valor deseado. No encontre otra manera de hacer una funcion recursiva que calcule el producto n veces de un numero sin usar este parametro, se podria quitar realizando un for si no seria necesario hacerla recursiva
float producto(float m, int n, float res){

    if (n < 0){
        printf("Por favor ingrese un multiplicador positivo \n");
        res = -1;
    }

// producto recibe m y n, m se va a sumar n veces hasta q n sea 0
    if (n > 0) {
        res += m;
        n -= 1;
        res = producto(m, n, res);
    }
    else 
    
    return res;
}
