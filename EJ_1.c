#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TP1_Recursividad.h"

bool palindromo(char *, int, int);

void main() {
    char palabra_1[] = "neuquen";
    char palabra_2[] = "pedro";
    char palabra_3[] = "RotOr";
    char palabra_4[] = "BicicLeta";
    char palabra_5[] = "otto";
    char palabra_6[] = "NaRrAn";

    printf("La palabra %s Es palindromo? %d\n", palabra_5, palindromo(palabra_5, 0, strlen(palabra_5)));    

    printf("La palabra %s Es palindromo? %d\n", palabra_1, palindromo(palabra_1, 0, strlen(palabra_1)));    
    printf("La palabra %s Es palindromo? %d\n", palabra_2, palindromo(palabra_2, 0, strlen(palabra_2)));    
    printf("La palabra %s Es palindromo? %d\n", palabra_3, palindromo(palabra_3, 0, strlen(palabra_3)));    
    printf("La palabra %s Es palindromo? %d\n", palabra_4, palindromo(palabra_4, 0, strlen(palabra_4)));    
    printf("La palabra %s Es palindromo? %d\n", palabra_6, palindromo(palabra_6, 0, strlen(palabra_6)));    
}

bool palindromo(char *cadena, int startIndex, int stringLength){
    // La cadena se supone que es palindromo hasta que se demuestre lo contrario
    bool esPalindromo = true;
    stringLength -= 1;
   
    // Antes de comparar los caracteres los paso a minuscula, para que no haya error de comparacion entre minusculas y mayusculas (R == r, o == O)    
    cadena[startIndex] = tolower(cadena[startIndex]);
    cadena[stringLength] = tolower(cadena[stringLength]);

    // Voy comparando los caracteres en puntas opuestas del string hasta que los indices que comparar el final e inicio del array sean iguales, o hasta que el indice final del array sea menor que el de inicio
    if (cadena[startIndex] == cadena[stringLength]){
        // startIndex < stringLength; Se podria hacer sin esta comparacion pero generaria mas iteracciones en el codigo
        // Ej, en la pasada para verificar la palabra "otto" sin esa linea se realizan 4 pasadas, con la linea solo 2
        if (startIndex != stringLength && startIndex < stringLength){
            startIndex += 1;
            palindromo(cadena, startIndex, stringLength);
        }
        // Si los caracteres son iguales y se termino de comparar el string, este es palindromo
    }
    else {
        // Si los caracteres no son iguales No es palindromo
        esPalindromo = false;
    }

    return esPalindromo;
}