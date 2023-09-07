#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(){

    int op;
    char c ='s';

    while(c =='s')
    {
        printf("\n ---------------- TP 1 PILAS ----------------\n\n");
        printf("  Que ingresar un programa? s/n\n");
        fflush(stdin);
        scanf("%c",&c);

        if(c=='s')
        {
            printf("\nIngrese programa del TP 1 \n\n");
            scanf("%i",&op);

            switch (op)
            {
                case 1:{
                        Pila DADA,aux1,aux2;
                        inicpila(&DADA);
                        inicpila(&aux1);
                        inicpila(&aux2);
                        printf("Cargue 5 elementos\n");

                        for(int i=0;i<5;i++)
                        {
                            leer(&DADA);
                        }

                        printf("\n\nPila DADA\n");

                        mostrar(&DADA);

                        apilar(&aux1,desapilar (&DADA));
                        apilar(&aux1,desapilar (&DADA));
                        apilar(&aux1,desapilar (&DADA));

                        printf("Pila AUX1\n");
                        mostrar(&aux1);

                        apilar(&aux2,desapilar (&DADA));
                        apilar(&aux2,desapilar (&DADA));

                        printf("\nPila AUX2\n");
                        mostrar(&aux2);
                        }break;

                case 2:{
                      Pila origen,destino;

                      inicpila(&origen);
                      inicpila(&destino);
                      char c='s';
                            printf("\nCargue la pila por teclado\n\n");
                            do
                            {
                                leer(&origen);
                                printf("\n Quiere ingresar otro dato a la pila? s/n \n\n");
                                fflush(stdin);
                                scanf("%c",&c);

                            }while(c=='s');

                        printf("Pila origen \n");
                        mostrar (&origen);

                        while(!pilavacia(&origen)){
                        apilar(&destino,desapilar(&origen));
                       }

                      printf("\n Pila origen alterada\n");
                      mostrar(&origen);
                      printf("\n Pila destino resultado\n");
                      mostrar(&destino);


                    }
                    break;

                case 3:{

                        Pila DADA,DISTINTOS,AUX1;
                        inicpila(&DADA);
                        inicpila(&AUX1);
                        inicpila(&DISTINTOS);

                        char c='s';

                            do{
                                leer(&DADA);

                                printf("Quiere ingresar un dato a la pila? s/n\n");
                                fflush(stdin);
                                scanf("%c",&c);

                                }while(c=='s');

                           while(!pilavacia(&DADA)){

                                if(tope(&DADA)==8){

                                    apilar(&AUX1,desapilar(&DADA));
                                }else{
                                    apilar(&DISTINTOS,desapilar(&DADA));
                                }
                           }
                           while(!pilavacia(&AUX1)){
                                apilar(&DADA,desapilar(&AUX1));
                           }
                        printf("\nResultado Pila DADA\n");
                        mostrar(&DADA);
                        printf("\nResultado Pila DISTINTOS\n");
                        mostrar(&DISTINTOS);


                    }
                    break;

                case 4:{

                        Pila ORIGEN,DESTINO,AUX1;
                        inicpila(&ORIGEN);
                        inicpila(&AUX1);
                        inicpila(&DESTINO);

                       char c='s';

                            do{
                                leer(&ORIGEN);

                                printf("Quiere ingresar un dato a la pila? s/n\n");
                                fflush(stdin);
                                scanf("%c",&c);

                                }while(c=='s');

                        printf("Pila Origen\n");
                        mostrar(&ORIGEN);

                           while(!pilavacia(&ORIGEN)){

                                apilar(&AUX1,desapilar(&ORIGEN));
                                }
                            while(!pilavacia(&AUX1)){
                                    apilar(&DESTINO,desapilar(&AUX1));
                            }

                        printf(" Pila Destino\n");
                        mostrar(&DESTINO);
                    }
                    break;

                case 5:{

                        Pila DADA,AUX1,AUX2;
                        inicpila(&AUX2);
                        inicpila(&DADA);
                        inicpila(&AUX1);

                       char c='s';

                            do{
                                leer(&DADA);

                                printf("Quiere ingresar un dato a la pila? s/n\n");
                                fflush(stdin);
                                scanf("%c",&c);

                                }while(c=='s');

                        printf("Pila DADA\n");
                        mostrar(&DADA);

                           while(!pilavacia(&DADA)){

                                apilar(&AUX1,desapilar(&DADA));
                                }
                            while(!pilavacia(&AUX1)){
                                    apilar(&AUX2,desapilar(&AUX1));
                            }
                            while(!pilavacia(&AUX2)){
                                    apilar(&DADA,desapilar(&AUX2));
                            }

                        printf("Pila DADA Invertida \n");

                        mostrar(&DADA);
                    }
                break;

                case 6:{

                        Pila DADA,AUX1,AUX2;
                        inicpila(&DADA);
                        inicpila(&AUX2);
                        inicpila(&AUX1);

                       char c='s';

                            do{
                                leer(&DADA);

                                printf("Quiere ingresar un dato a la pila? s/n\n");
                                fflush(stdin);
                                scanf("%c",&c);

                                }while(c=='s');

                            printf("Pila DADA Original\n");
                            mostrar(&DADA);

                            apilar(&AUX1,desapilar(&DADA));

                             while(!pilavacia(&DADA)){

                                apilar(&AUX2,desapilar(&DADA));
                                }
                             apilar(&DADA,desapilar(&AUX1));

                             while(!pilavacia(&AUX2)){
                                        apilar(&DADA,desapilar(&AUX2));
                             };

                        printf("Pila DADA elemento tope invertido\n");

                        mostrar(&DADA);
                    }
                break;

                case 7:{

                        Pila DADA,AUX1,AUX2,AUX3;
                            inicpila(&AUX3);
                            inicpila(&DADA);
                            inicpila(&AUX2);
                            inicpila(&AUX1);

                                char c='s';

                                    do{
                                        leer(&DADA);

                                        printf("Quiere ingresar un dato a la pila? s/n\n");
                                        fflush(stdin);
                                        scanf("%c",&c);

                                        }while(c=='s');

                                    printf("Pila DADA Original\n");
                                    mostrar(&DADA);

                                     while(!pilavacia(&DADA)){

                                        apilar(&AUX2,desapilar(&DADA));
                                        }
                                     apilar(&AUX3,desapilar(&AUX2));

                                     while(!pilavacia(&AUX2)){
                                                apilar(&DADA,desapilar(&AUX2));
                                     };
                                     apilar(&DADA,desapilar(&AUX3));

                                printf("Pila DADA elemento base invertido\n");

                        mostrar(&DADA);

                    }
                break;

                case 8:{
                        Pila MAZO,JUGADOR1,JUGADOR2;
                        inicpila(&MAZO);
                        inicpila(&JUGADOR1);
                        inicpila(&JUGADOR2);


                       char c='s';
                                    printf("Ingrese mazo de cartas\n");
                                    do{
                                        leer(&MAZO);

                                        printf("Quiere ingresar un dato a la pila? s/n\n");
                                        fflush(stdin);
                                        scanf("%c",&c);

                                        }while(c=='s');

                        printf("La pila MAZO original es \n");

                        mostrar(&MAZO);

                        while(!pilavacia(&MAZO)){
                                apilar(&JUGADOR1,desapilar(&MAZO));
                                if(!pilavacia(&MAZO)){
                                apilar(&JUGADOR2,desapilar(&MAZO));}
                        }

                        printf(" La pila JUGADOR 1\n");

                        mostrar(&JUGADOR1);

                        printf(" La pila JUGADOR 2\n");

                        mostrar(&JUGADOR2);
                    }

                break;

                case 9:{



                        Pila A,B,AUX1,AUX2,AUX3,AUX4;
                           inicpila(&A);
                           inicpila(&B);
                           inicpila(&AUX1);
                           inicpila(&AUX2);
                           inicpila(&AUX3);
                           inicpila(&AUX4);
                            printf("Llenar Pila A\n");
                        char c='s';
                        char c1='s';
                        char c2='s';
                        while(c=='s'){

                            printf("Quiere ingresar un dato a la pila? s/n \n");
                            fflush(stdin);
                            scanf("%c",&c);

                            if(c=='s'){
                                leer(&A);
                            }

                            };

                            printf("Llenar Pila B\n");

                        while(c1=='s'){

                            printf("Quiere ingresar un dato a la pila? s/n \n");
                            fflush(stdin);
                            scanf("%c",&c1);

                            if(c1=='s'){
                                leer(&B);
                            }

                            };

                        if(!pilavacia(&A) && pilavacia(&B)){

                            printf("La pila B esta vacia\n");
                            mostrar(&B);
                            printf("La pila A tiene elementos\n");
                            mostrar(&A);
                            }
                        else if(!pilavacia(&B) && pilavacia(&A)){

                                printf("La pila A esta vacia\n");
                                mostrar(&A);
                                printf("La pila B tiene elementos\n");
                                mostrar(&B);
                                }
                        else if(pilavacia(&B) && pilavacia(&A)){

                                printf("Las pilas no tienen elementos\n");
                                printf("La pila A esta vacia\n");
                                mostrar(&A);
                                printf("La pila B esta vacia\n");
                                mostrar(&B);
                            }
                        else if(!pilavacia(&A) && !pilavacia(&B)){

                                printf("La pila A es\n");
                                    mostrar(&A);
                                printf("La pila B es \n");
                                    mostrar(&B);



                                while(!pilavacia(&A)  && !pilavacia(&B)){

                                    apilar(&AUX1,desapilar(&A));
                                    apilar(&AUX2,desapilar(&B));

                                    if(!pilavacia(&A) && pilavacia(&B)){

                                       printf("La pila A tiene mas elementos que la pila B\n\n");

                                    }
                                     else if(!pilavacia(&B) && pilavacia(&A)){

                                        printf("La pila B tiene mas elementos que la pila A\n\n");

                                    }
                                    else if(pilavacia(&B) && pilavacia(&A)){

                                            printf("Las pilas son iguales\n");



                                }
                            }
                        }
                    }

                break;

                case 10:{



                        Pila A,B,AUXA,AUXB;
                        int contadorA,contadorB;
                        contadorA=0;
                        contadorB=0;
                            inicpila(&AUXA);
                            inicpila(&AUXB);
                            inicpila(&A);
                           inicpila(&B);

                            printf("Llenar Pila A\n");
                        char mayor;
                        char c='s';
                        char c1='s';

                        while(c=='s'){

                            printf("Quiere ingresar un dato a la pila? s/n \n");
                            fflush(stdin);
                            scanf("%c",&c);

                            if(c=='s'){
                                leer(&A);
                                contadorA ++;
                            }

                            }

                            printf("Llenar Pila B\n");

                        while(c1=='s'){

                            printf("Quiere ingresar un dato a la pila? s/n \n");
                            fflush(stdin);
                            scanf("%c",&c1);

                            if(c1=='s'){
                                leer(&B);
                                contadorB ++;
                            }

                            }

                        if(contadorA>contadorB){
                            printf("Las pilas no son complamente iguales\n");
                        }
                        else if(contadorB>contadorA){
                            printf("Las pilas no son completamente iguales\n");
                        }
                        else
                        {
                            while(!pilavacia(&A) && !pilavacia(&B) && (tope(&A)==tope(&B))){
                                    apilar(&AUXA,desapilar(&A));
                                    apilar(&AUXB,desapilar(&B));
                            }
                                if(pilavacia(&A)&&pilavacia(&B)){
                                    printf("Las pilas son completamente iguales\n");
                                }
                                else{
                                    printf("Las pilas no son completamente iguales\n");
                                }


                        }
                        while(!pilavacia(&AUXA)){
                            apilar(&A,desapilar(&AUXA));
                        }
                        while(!pilavacia(&AUXB)){
                            apilar(&B,desapilar(&AUXB));
                        }
                        printf("Pila A\n");
                        mostrar(&A);
                        printf("Pila B\n");
                        mostrar(&B);
                    }

                break;

                case 11:{



                         Pila MODELO,DADA,BASURA,AUX1;
                         inicpila(&DADA);
                         inicpila(&BASURA);
                         inicpila(&MODELO);
                         inicpila(&AUX1);
                        char c='s';
                        while(c=='s'){

                            printf("Quiere ingresar un dato a la pila MODELO? s/n\n");
                            fflush(stdin);
                            scanf("%c",&c);

                            if(c=='s'){
                            leer(&MODELO);
                            }
                        }

                        char d='s';

                            printf("Llenar Pila DADA\n");

                        while(d=='s'){

                            printf("Quiere ingresar un dato a la pila DADA?s/n\n");
                            fflush(stdin);
                            scanf("%c",&d);

                            if(d=='s'){
                            leer(&DADA);
                            }
                        }
                         printf("\nLa pila MODELO es \n");
                        mostrar(&MODELO);

                        printf("\nLa pila DADA es \n");
                        mostrar(&DADA);

                     while(!pilavacia(&DADA)){

                         if(tope(&MODELO)==tope(&DADA)){

                                apilar(&BASURA,desapilar(&DADA));
                         }
                         else{

                            apilar(&AUX1,desapilar(&DADA));
                            }
                        }

                     while(!pilavacia(&AUX1)){

                            apilar(&DADA,desapilar(&AUX1));
                        }

                        printf("\nLa pila MODELO es \n");
                        mostrar(&MODELO);

                        printf("\nLa pila DADA sin elementos = tope de Modelo es \n");
                        mostrar(&DADA);
                    }

                break;

                case 12:{



                         Pila MODELO,DADA,IGUALES,AUX1,AUX2;
                         inicpila(&DADA);
                         inicpila(&IGUALES);
                         inicpila(&MODELO);
                         inicpila(&AUX1);
                         inicpila(&AUX2);
                        char c='s';
                        while(c=='s'){

                            printf("Quiere ingresar un dato a la pila MODELO? s/n\n");
                            fflush(stdin);
                            scanf("%c",&c);

                            if(c=='s'){
                            leer(&MODELO);
                            }
                        }

                        char d='s';

                            printf("Llenar Pila DADA\n");

                        while(d=='s'){

                            printf("Quiere ingresar un dato a la pila DADA?s/n\n");
                            fflush(stdin);
                            scanf("%c",&d);

                            if(d=='s'){
                            leer(&DADA);
                            }
                        }
                         printf("\nLa pila MODELO es \n");
                        mostrar(&MODELO);

                        printf("\nLa pila DADA es \n");
                        mostrar(&DADA);

                            while(!pilavacia(&MODELO)){

                                    while(!pilavacia(&DADA)){

                                        if(tope(&DADA)==tope(&MODELO)){

                                            apilar(&IGUALES,desapilar(&DADA));
                                        }
                                        else{
                                            apilar(&AUX1,desapilar(&DADA));
                                        }
                                    }
                                    apilar(&AUX2,desapilar(&MODELO));
                                    while(!pilavacia(&AUX1)){
                                        apilar(&DADA,desapilar(&AUX1));
                                    }
                            }
                        while(!pilavacia(&AUX1)){
                            apilar(&DADA,desapilar(&AUX1));
                        }
                        while(!pilavacia(&AUX2)){
                            apilar(&MODELO,desapilar(&AUX2));
                        }

                        printf("\nLa pila MODELO es \n");
                        mostrar(&MODELO);

                        printf("\nLa pila DADA sin elementos de MODELO es \n");
                        mostrar(&DADA);
                    }

                break;

                case 13:{



                        Pila LIMITE,DADA,MAYORES,MENORES;
                        inicpila(&MENORES);
                        inicpila(&MAYORES);
                        inicpila(&LIMITE);
                        inicpila(&DADA);

                        char c='s';
                        while(c=='s'){

                            printf("Quiere ingresar un dato a la pila LIMITE? s/n\n");
                            fflush(stdin);
                            scanf("%c",&c);

                            if(c=='s'){
                            leer(&LIMITE);
                            }
                        }

                        char c1='s';
                        while(c1=='s'){

                            printf("Quiere ingresar un dato a la pila DADA? s/n\n");
                            fflush(stdin);
                            scanf("%c",&c1);

                            if(c1=='s'){
                            leer(&DADA);
                            }
                        }
                        printf("Pila LIMITE\n");
                        mostrar(&LIMITE);
                            printf("Pila DADA\n");
                        mostrar(&DADA);

                        while(!pilavacia(&DADA)){

                            if(tope(&DADA)>=tope(&LIMITE)){
                                apilar(&MAYORES,desapilar(&DADA));
                            }else{
                            apilar(&MENORES,desapilar(&DADA));
                            }
                        }
                        printf("La pila MAYORES ES\n");
                        mostrar(&MAYORES);

                        printf("La pila MENORES ES\n");
                        mostrar(&MENORES);

                    }

                break;

                case 14:{



                        Pila DADA,PAR,IMPAR,AUX;
                        inicpila(&AUX);
                        inicpila(&DADA);
                        inicpila(&PAR);
                        inicpila(&IMPAR);

                        char c='s';
                        while(c=='s'){

                            printf("Quiere ingresar un dato a la pila DADA? s/n\n");
                            fflush(stdin);
                            scanf("%c",&c);

                            if(c=='s'){
                            leer(&DADA);
                            }
                        }
                         while(!pilavacia(&DADA)){

                            apilar(&AUX,desapilar(&DADA));
                            if(!pilavacia(&DADA)){
                                apilar(&AUX,desapilar(&DADA));
                            }
                            else{
                                apilar(&IMPAR,desapilar(&AUX));
                            }

                         }
                         if(!pilavacia(&IMPAR)){
                            printf("La pila DADA tiene cantidad impar de elementos\n");
                            printf("\nPila AUX\n");
                            mostrar(&AUX);
                            printf("\nPila Impar\n");
                            mostrar(&IMPAR);
                         }
                         else{
                            apilar(&PAR,desapilar(&AUX));
                            printf("La pila DADA tiene cantidad PAR de elementos\n");
                            printf("\nPila AUX\n");
                            mostrar(&AUX);
                            printf("\nPila PAR\n");
                            mostrar(&PAR);
                         }
                }



                break;

                case 15:{



                        printf("\nLa condicion del siguiente ciclo es que la pila (&Pila1) no este vacia\n");
                        printf("por lo que se va a cortar el ciclo cuando (&Pila1) este vacia\n");


                    }

                break;

                case 16:{


                        printf("\nLo que realiza el codigo es, analizar el tope de la (&Pila1) y que siendo igual a 5\n");
                        printf("lo almacene primero en una pila &Aux y luego en una &Result, repitiendo el codigo hasta\n");
                        printf("que la pila &Pila1 este vacia\n");

                    }

                break;

                case 17:{



                        printf("\nRespuesta a)\n\n");
                        printf("No resuelve el problema ya que solo sacaria de la Pila los elementos distintos de 5, no solo los que preceden ");

                        printf("\n\nRespuesta b)\n\n");
                        printf("Primer error, solo cargar la Pila ORIGEN con 1 unico valor\n");
                        printf("\nSegundo error, quitar elementos distintos de 5, cuando deberia solo quitar los que preceden\n");

                        printf("\n Respuesta c)\n");
                       Pila ORIGEN,DISTINTO,AUX1;
                       inicpila(&AUX1);
                       inicpila(&ORIGEN);
                       inicpila(&DISTINTO);

                           char c='s';
                        while(c=='s'){

                            printf("\n\nQuiere ingresar un dato a la pila ORIGEN? s/n\n");
                            fflush(stdin);
                            scanf("%c",&c);

                            if(c=='s'){
                            leer(&ORIGEN);
                            }
                        }
                        printf("Pila ORIGEN\n");
                        mostrar(&ORIGEN);
                        printf("Pila DISTINTO\n");
                        mostrar(&DISTINTO);
                        while(!pilavacia(&ORIGEN)){

                            if(tope(&ORIGEN)>5){
                                apilar(&DISTINTO,desapilar(&ORIGEN));
                            }else{
                                apilar(&AUX1,desapilar(&ORIGEN));
                                }
                        }
                        while(!pilavacia(&AUX1)){
                            apilar(&ORIGEN,desapilar(&AUX1));
                        }

                        printf("\n-------------Luego de la condicion-------------\n\n");
                        printf("Pila ORIGEN\n");
                        mostrar(&ORIGEN);
                        printf("Pila DISTINTO\n");
                        mostrar(&DISTINTO);


                        printf("Respuesta d)\n\n");
                        printf("Los componentes del programa son:3 Pilas (ORIGEN,DESTINO,AUX1),\n");
                        printf("3 bucles while (Uno para cargar la Pila,Otro para filtrar y el ultimo para dejarla original\n");
                        printf(",por ultimo un bucle if(){}-else{} para poder filtar los valores que preceden al 5\n");
                    }

                break;

                case 18:{


                        printf("Respuesta a)\n\n");
                        printf("La condicion del ciclo es que la pila &Pila1 no este vacia y la pila &Pila2 Tampoco\n");
                        printf("\nRespuesta b)\n\n");
                        printf("Los posibles estados son 3:\n");
                        printf("1)Las 2 pilas vacias \n");
                        printf("2)La &Pila1 con elementos y la &Pila2 vacia\n");
                        printf("3)La pila &Pila2 con elementos y la &Pila1 vacia\n");
                    }
                break;

                default:{
                    printf("Caso por defecto\n");
                }
            }
        }
    }
return 0;
}
