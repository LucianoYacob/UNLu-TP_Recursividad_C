#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TP1_Recursividad.h"

void validorEntrada();
char *eliminarEspacios(char *);
void eliminarCeros(char *cadena);
char* auxAgregarSeparador(char* string);

void main()
{
    //  Casos de prueba
    char numero1[] = "12 23 2 32 323";
    char numero2[] = "0001233.232.3";
    char numero3[] = "2312332";
    char numero4[] = "0002312882";
    char numero5[] = "   ";

    // Ejecucion de la funcion auxiliar, la cual llama a la funcion principal
    char* resultado1 = auxAgregarSeparador(numero1);
    char* resultado2 = auxAgregarSeparador(numero2);
    char* resultado3 = auxAgregarSeparador(numero3);
    char* resultado4 = auxAgregarSeparador(numero4);
    char* resultado5 = auxAgregarSeparador(numero5);

    // Impresion por pantalla de los resultados
    printf("%s\n", resultado1);
    printf("%s\n", resultado2);
    printf("%s\n", resultado3);
    printf("%s\n", resultado4);
    printf("%s\n", resultado5);
}

// Se encarga de validar si un string es o no valido para agregarle puntos separadores de miles
char* auxAgregarSeparador(char* string) {
    if (strchr(string, '.') != NULL || strlen(string) <= 3 ) {
        return "La cadena no debe tener puntos y debe tener mas de 3 digitos.\n";
    }
    else {
        if (strchr(string, ' ') != NULL) {
            char *sinEspacios = eliminarEspacios(string);
            strcpy(string, sinEspacios);

            if (strlen(string) <= 3){
                return "La cadena debe tener mas de 3 digitos.\n";
            }
        }
        
        if(string[0] == '0') eliminarCeros(string);
    }

    return agregarSeparadorMiles(string);
}

// Funcion principal, utilizada para dado un string agregarle puntos separadores de miles a traves de un funcionamiento recursivo. Retorna el string con separadores de miles
char* agregarSeparadorMiles(char* numero) {
    int len = strlen(numero);

    if (len <= 3 ) return numero;

    // Obtener los ultimos tres dígitos
    char *ultimosTresDigitos = malloc(sizeof(char)*5);

    ultimosTresDigitos[0] = '.';
    strncpy(ultimosTresDigitos+1, (numero+len)-3, 3);
    // strncpy(destino, origen, cantidad de elementos); Me permite copiar una cadena en otra limitando la cantidad de caracteres que se copian
    ultimosTresDigitos[4] = '\0';
    
    char *restoDigitos = calloc((len-3)+1,sizeof(char)); 
    strncpy(restoDigitos, numero, len-3); // Almaceno en el puntero a char "restoDigitos" los primeros digitos de la cadena numero, osea el resto de digitos que sobraron desde el punto hasta el inicio
    restoDigitos[(len-3)+1] = '\0';    

    char* result = calloc(len, sizeof(char));
    result = agregarSeparadorMiles(restoDigitos);
    // Le paso el resto de digitos, para que los concatene a los ultimos 3 digitos y me retorne el resultado de esa concatenacion

    // CONSULTA! Cuando ejecuto free, el programa se pausa, como si tendria un punto de interrupcion, esta bien liberar memoria aca?
    free(restoDigitos);
    strcat(result, ultimosTresDigitos);
    free(ultimosTresDigitos);
    return result;
}

char *eliminarEspacios(char str[100]) {
    static char strSinEspacios[100]; //Si saco el static la variable no se mantiene en memoria y al terminar de ejecutar esta funcion se pierde su espacio en memoria, por lo que genera error
    int i, j;
    i = 0;
    j = 0;

    strSinEspacios[0] = '\0';

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            strSinEspacios[j] = str[i];
            j++;
        }
        i++;
    }

    return strSinEspacios;
}

void eliminarCeros(char cadena[]) {
    int i, j;

    // Buscar el primer caracter que no sea un cero
    i = 0; // Guardo la posicion en donde aparece el 1er caracter q no es 0
    while (cadena[i] == '0') {
        i++;
    }

    // Mover los caracteres restantes hacia la izquierda
    j = 0;
    while (cadena[i] != '\0') {
        cadena[j] = cadena[i];
        i++;
        j++;
    }
    cadena[j] = '\0';
}



















//  Validar entrada de usuario, verifica que no se haya ingresado ningun punto
// No es utilizada, ya que ingreso parametros en la funcion principal
void validorEntrada()
{
    char str[100];
    do
    {
        printf("Por favor ingresa valores numericos sin puntos\n");
        fgets(str, 100, stdin);
    } while (strchr(str, '.') != NULL);
    // strchr() verifica si en "x" cadena hay "y" caracter, si existe ese caracter en ese valor lo retorno, si no existe devuelve NULL.
}