#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
void Cargar(Pila *P);

int main()
{
    Pila JORGE;
    inicpila(&JORGE);

    apilar(&JORGE,2);

    int Puntero = &JORGE;

    Cargar(&JORGE);

    printf("punter %i\n",&Puntero);


    printf("Jorge %i\n",&JORGE);

    printf("Que hay en direcc? %i\n", Puntero);

    return 0;
}


void Cargar(Pila *p){


    leer(p);


}
