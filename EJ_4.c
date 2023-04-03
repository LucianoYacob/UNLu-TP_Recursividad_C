#include <stdio.h>
#include "TP1_Recursividad.h"

int main(int argc, char const *argv[])
{
    // float resultado1 = division(27, 5, 0); //5.4
    // float resultado2 = division(10, 2, 0); //5
    // float resultado3 = division(22, 3, 0); //7.3...
    // float resultado4 = division(0, 8, 0);  //0
    // float resultado5 = division(20, 0, 0); //Error, division por 0
    float resultado6 = division(-10.8, 2.4, 0); //-4.5
    float resultado7 = division(-10.8, -2, 0); //5.4
    float resultado8 = division(10.8, -2, 0); //-5.4

    // printf("Res 1: %.4f\n", resultado1);
    // printf("Res 2: %.4f\n", resultado2);
    // printf("Res 3: %.4f\n", resultado3);
    // printf("Res 4: %.4f\n", resultado4);
    // printf("Res 5: %.4f\n", resultado5);
    printf("Res 6: %.4f\n", resultado6);
    printf("Res 7: %.4f\n", resultado7);
    printf("Res 8: %.4f\n", resultado8);

    return 0;
}

// m = dividendo, n = divisor, i = cociente|resultado ( indice que sirve para ver cuantas veces se resto el dividendo por el divisor ) debe empezar en 0  
float division(float m, float n, float i){

    if (n == 0) {
        // No se puede dividir por 0 
        printf("ERROR: No se puede dividir por 0\n");
        return 0;
    }
    else if (n < 0) {
        // b) divisor negativo
        n = -n;
        m = -m;
        return division(m, n, i);
    }
    else if (m > n){
        // a) resto m-n y sumo uno a i, vuevlo a llamar a la funcion
        m = m - n;
        i++;
        return division(m, n, i);
    } 
    else if (m < 0 && n > 0) {
        // c) dividendo negativo y divisor positivo
        m = m + n;
        i--;
        return division(m, n, i);
    }
    else if (m <= n && m >= 0) {
        // Se termino la division
        // b) cociente es = i, cociente += (resto/divisor)
        i += (m/n); 
        return i ;
    }
    else {
        // Caso donde el dividendo es cero y el divisor es negativo
        printf("ERROR: Division indefinida\n");
        return 0;
    }
}