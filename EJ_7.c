#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ondaDigital(char*, char);
int comprobarCadena(char *cadena);

int main() {
    // Ejemplos de uso
    char cadena1[] = "lhlhlh";
    char cadena2[] = "HH3HLLLLHHHHHaLHH";
    char cadena3[] = "HHHLLLLHHHHHLHH";

    printf("%s => ", cadena1);
    if (comprobarCadena(cadena1) == 0) ondaDigital(cadena1, '\0');
    else printf("La cadena no puede tener valores diferentes a 'H' o 'L', sean minusculas o mayusculas");
    printf("\n");

    printf("%s => ", cadena2);
    if (comprobarCadena(cadena2) == 0) ondaDigital(cadena2, '\0');
    else printf("La cadena no puede tener valores diferentes a 'H' o 'L', sean minusculas o mayusculas");
    printf("\n");
    
    printf("%s => ", cadena3);
    if (comprobarCadena(cadena3) == 0) ondaDigital(cadena3, '\0');
    else printf("La cadena no puede tener valores diferentes a 'H' o 'L', sean minusculas o mayusculas");
    printf("\n");

    return 0;
}

void ondaDigital(char* cadena, char caracterAnterior) {
    // Caso base: si la cadena está vacía, retornar una cadena vacía
    if (strlen(cadena) == 0) {
        return;
    }

    // Tomo el primer caracter de la cadena y el anterior y los paso a mayusculas
    char primerCaracter = toupper(cadena[0]);
    caracterAnterior = toupper(caracterAnterior);

    // Caso recursivo: si es una H y el caracter anterior tambien es H, imprimira '-', si el caracter anterior es L imprimira "|-"
    if (primerCaracter == 'H') {
        if (caracterAnterior == 'H' || caracterAnterior == '\0') printf("-");
        else printf("|-");
        
        ondaDigital(cadena + 1, cadena[0]);
    }
    // Caso recursivo: si es una L y el caracter anterior tambien es L, imprimira '_', si el caracter anterior es H imprimira "|_"
    else if (primerCaracter == 'L') {
        if (caracterAnterior == 'L' || caracterAnterior == '\0') printf("_");
        else printf("|_");
        
       ondaDigital(cadena + 1, cadena[0]);
    }
}

int comprobarCadena(char *cadena) {
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++) {
        cadena[i] = toupper(cadena[i]);
        if (cadena[i] != 'L' && cadena[i] != 'H') {
            return 1; // retorna 1 si hay un valor diferente a L o H
        }
    }
    return 0; // retorna 0 si todos los valores son L o H
}