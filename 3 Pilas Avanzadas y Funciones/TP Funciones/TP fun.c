#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "math.h"
void llenarPila(Pila *p);
void pasarPila(Pila *datos,Pila *destino);
void pasarPilaOrden(Pila *uno,Pila *ORDEN);
void eliminarMenor(Pila *PRUEBA,Pila *MENOR);
void nPilaOrdenada(Pila *PRUEBA,Pila *MENOR,Pila *Orden);
void insertarOrdenada(Pila *PRUEBA,Pila *elemento);
void insertarPilaEnOtraPilaOrdenada2(Pila *ordenada2,Pila *ordenadaOrig);
int sumaElementosSinAlterar(Pila datos);
int sumaElementos(Pila aCalcular);
int elementosPila(Pila aCalcular);
int promedioElementos(Pila aCalcular);
int pilaDecimal(Pila datos);
//1
void llenarPila(Pila *p){

    int i=1,cantidad;

        printf("Cuantos elementos quiere ingresar\n");
        scanf("%i",&cantidad);

        printf("Ingrese los elementos\n");
        for(i=1;i<=cantidad;i++){
            leer(p);
            }
        }
//2
void pasarPila(Pila *datos,Pila *destino){


        while(!pilavacia(datos)){

            apilar(destino,desapilar(datos));
        }
}

//3
void pasarPilaOrden(Pila *uno,Pila *ORDEN){

        Pila AUX;
        inicpila(&AUX);

        while(!pilavacia(uno)){

            apilar(&AUX,desapilar(uno));
        }
        while(!pilavacia(&AUX)){
            apilar(ORDEN,desapilar(&AUX));
        }
}
//4
void eliminarMenor(Pila *PRUEBA,Pila *MENOR){

    Pila AUX;
    inicpila(&AUX);

    apilar(MENOR,desapilar(PRUEBA));
        while(!pilavacia(PRUEBA)){

            if(tope(PRUEBA)>tope(MENOR)){
                apilar(&AUX,desapilar(PRUEBA));
                }
            else if(tope(PRUEBA)<tope(MENOR)){
                apilar(&AUX,desapilar(MENOR));
                apilar(MENOR,desapilar(PRUEBA));
                }
            else{
                apilar(&AUX,desapilar(PRUEBA));
                }
            }
            while(!pilavacia(&AUX)){
                apilar(PRUEBA,desapilar(&AUX));
            }
}
//5
void nPilaOrdenada(Pila *PRUEBA,Pila *MENOR,Pila *Orden){


    do{
    eliminarMenor(PRUEBA,MENOR);
    apilar(Orden,desapilar(MENOR));
    }while(!pilavacia(PRUEBA));


}

//6
void insertarOrdenada(Pila *PRUEBA,Pila *elemento){

    Pila AUX;
    inicpila(&AUX);

    while((!pilavacia(PRUEBA)) && tope(PRUEBA)>tope(elemento)){

    apilar(&AUX,desapilar(PRUEBA));
    }

    apilar(PRUEBA,desapilar(elemento));

    while(!pilavacia(&AUX)){
        apilar(PRUEBA,desapilar(&AUX));
    }
}
//7
void insertarPilaEnOtraPilaOrdenada2(Pila *ordenada2,Pila *ordenadaOrig){

   apilar(ordenada2,desapilar(ordenadaOrig));
    while(!pilavacia(ordenadaOrig)){

        insertarOrdenada(ordenada2,ordenadaOrig);
    }

}
//8
int sumaElementosSinAlterar(Pila datos){

    Pila aux;
    inicpila(&aux);
    int suma;

    suma=suma+tope(&datos);

    apilar(&aux,desapilar(&datos));

    suma=suma+tope(&datos);

   return (suma);
}
//9
int sumaElementos(Pila aCalcular){

    Pila Aux;
    inicpila(&Aux);
    int suma;
    suma = 0;

    while(!pilavacia(&aCalcular)){

    suma = suma + tope(&aCalcular);
    apilar(&Aux,desapilar(&aCalcular));
    }

    return suma;
}

int elementosPila(Pila aCalcular){

    Pila Aux;
    inicpila(&Aux);

    int contador,resu;
    contador =0;


    while(!pilavacia(&aCalcular)){
       apilar(&Aux,desapilar(&aCalcular));
        contador = contador + 1;
    }
return contador;
}

int division2(int *dividendo,int *divisor){

    int resu;
    resu= 0;

    resu = *dividendo/ *divisor;

    return resu;
}
int promedioElementos(Pila aCalcular){

    int dividendo,divisor,resultado;
    resultado=0;
    dividendo=0;
    divisor=0;

    dividendo = sumaElementos(aCalcular);

    divisor = elementosPila(aCalcular);

    resultado = division2(&dividendo,&divisor);

    return resultado;
}
//10
int pilaDecimal(Pila datos){

    Pila aux1,aux2;
    inicpila(&aux1);
    inicpila(&aux2);

    int elementos,i,resu;
    elementos=0;
    resu=0;
    i=0;

    elementos = elementosPila(datos);

    while(!pilavacia(&datos)){
    apilar(&aux1,desapilar(&datos));
    }

    while(i != elementos){

        resu = resu+(tope(&aux1)*pow(10,elementos-1));
        apilar(&aux2,desapilar(&aux1));
        elementos = elementos - 1;
    }
    return resu;
}



int main(){

    int op;
    char c='s';

    while(c=='s'){

        printf("Quiere ingresar un ejercicio? s/n\n");
        fflush(stdin);
        scanf("%c",&c);

    do{
        printf("\nIngrese ejercicio del TP \n\n");
    scanf("%i",&op);

            switch (op)
            {
                case 1:{

                    Pila Datos;
                    inicpila(&Datos);

                    llenarPila(&Datos);

                    mostrar(&Datos);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);



                }break;

                case 2:{

                    Pila Datos,Destino;
                    inicpila(&Datos);
                    inicpila(&Destino);

                    llenarPila(&Datos);

                    printf("Datos original\n");
                    mostrar(&Datos);

                    pasarPila(&Datos,&Destino);

                    printf("Pila Datos\n");
                    mostrar(&Datos);

                    printf("Pila Destino\n");
                    mostrar(&Destino);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);

                }break;

                case 3:{

                    Pila Datos,Orden;
                    inicpila(&Datos);
                    inicpila(&Orden);

                    llenarPila(&Datos);

                    printf("Pila Datos original\n");
                    mostrar(&Datos);

                    pasarPilaOrden(&Datos,&Orden);

                    printf("Pila Datos\n");
                    mostrar(&Datos);

                    printf("Pila Orden\n");
                    mostrar(&Orden);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);


                }break;

                case 4:{

                    Pila Datos,Menor;
                    inicpila(&Menor);
                    inicpila(&Datos);

                    llenarPila(&Datos);
                    printf("Datos Orig\n");
                    mostrar(&Datos);

                    eliminarMenor(&Datos,&Menor);

                    printf("Datos sin menor\n");
                    mostrar(&Datos);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);

                }break;

                case 5:{

                    Pila Datos,Ordenada,Menor;
                    inicpila(&Menor);
                    inicpila(&Datos);
                    inicpila(&Ordenada);

                    llenarPila(&Datos);
                    printf("Datos orig\n");
                    mostrar(&Datos);

                    nPilaOrdenada(&Datos,&Menor,&Ordenada);

                    printf("Datos\n");
                    mostrar(&Datos);

                    printf("Resultado\n");
                    mostrar(&Ordenada);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);

                }break;

                case 6:{

                    Pila Datos,Elemento;
                    inicpila(&Datos);
                    inicpila(&Elemento);
                    int ele =0;

                    llenarPila(&Datos);

                    printf("Datos orig\n");
                    mostrar(&Datos);

                    printf("Ingrese elemento a insertar\n");
                    leer(&Elemento);



                    insertarOrdenada(&Datos,&Elemento);

                    printf("Datos resultado\n");
                    mostrar(&Datos);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);
                }break;

                case 7:{

                    Pila Datos,Resultado;
                    inicpila(&Resultado);
                    inicpila(&Datos);

                    llenarPila(&Datos);
                    printf("Datos orig\n");
                    mostrar(&Datos);

                    insertarPilaEnOtraPilaOrdenada2(&Resultado,&Datos);

                    printf("Datos\n");
                    mostrar(&Datos);

                    printf("Resultado\n");
                    mostrar(&Resultado);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);
                }break;

                case 8:{

                    Pila Datos;
                    inicpila(&Datos);
                    int suma;
                    suma=0;


                    llenarPila(&Datos);

                    printf("Pila Datos orig\n");
                    mostrar(&Datos);

                    suma = sumaElementosSinAlterar(Datos);

                    printf("La suma es %i\n",suma);

                    printf("Quiere ingresar un ejercicio? s/n\n");
                    fflush(stdin);
                    scanf("%c",&c);

            }break;

            case 9:{

                Pila Datos;
                inicpila(&Datos);
                int promedio;
                promedio=0;

                llenarPila(&Datos);

                printf("Datos orig\n");
                mostrar(&Datos);

                promedio = promedioElementos(Datos);

                printf("El promedio de los datos es %i\n",promedio);

                printf("Quiere ingresar un ejercicio? s/n\n");
                fflush(stdin);
                scanf("%c",&c);

            }break;

            case 10:{

                Pila Datos;
                inicpila(&Datos);

                int resu;
                resu=0;

                llenarPila(&Datos);
                printf("Datos orig\n");
                mostrar(&Datos);

                resu = pilaDecimal(Datos);

                printf("El numero es %i\n",resu);

                printf("Quiere ingresar un ejercicio? s/n\n");
                fflush(stdin);
                scanf("%c",&c);
            }break;

            default :{

            }




            }
    }while(c=='s');

    }
 return 0;
}



















