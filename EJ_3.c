#include <stdio.h>
#include <ctype.h>

void terminoSerieFibonacci(int, int, int);
int socilitarNumero();

void main() {
    int r = socilitarNumero();
    
    terminoSerieFibonacci(0, 1, r);
}

// primero y ultimo son variables que identificaran como sigue la sucesion, al principio siempre seran 0 y 1, k es la cantidad de veces que queremos hacer la sucesion
void terminoSerieFibonacci(int primero, int ultimo, int k){
    int actual;
    int resultado = 0;

    // Si k es mayor a 1 quiere decir que la sucesion continua, por lo cual debera seguir sumando los valores (primero + ultimo) para tener el proximo numero a sumar
    if (k > 1) {
        actual = primero + ultimo;
        k--; // Resto en uno k para no crear un loop infinito (Condicion de corte)
        // Actual pasara a ser el ultimo valor calculado, y ultimo sera el penultimo valor que existia
        terminoSerieFibonacci(ultimo, actual, k);
    }
    else{
        printf("\nResultado %d", ultimo);
    }
    
}

// Validacion de entrada de teclado
int socilitarNumero() {
    int k = 0, result;

    // Validacion para que el usuario solo introduzca valores enteros positivos. Los decimales son transformados automaticamente a entero
    do {
        printf("Por favor ingrese un numero positivo para calcular la sucesion Fibonacci:\n");
        result = scanf("%i", &k);
        fflush(stdin); // Limpio el buffer de entrada 
    } while (k <= 0 || result == 0);
    
    return k;
}