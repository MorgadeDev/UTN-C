#include "pila.h"
#include "time.h"
int main(){

    int op;
    char c='s';

    while(c=='s'){

        printf("Quiere ingresar un ejercicio? s/n\n");
        fflush(stdin);
        scanf("%c",&c);

    if(c=='s'){
        printf("\nIngrese ejercicio del TP \n\n");
    scanf("%i",&op);

            switch (op)
            {
                case 1:{
                    int acumulador=0;

                    Pila pilaA,AUX;
                    inicpila(&AUX);
                    inicpila(&pilaA);

                    char c='s';

                    while(c=='s'){
                        printf("Quiere ingresar un dato a la Pila? s/n\n");
                        fflush(stdin);
                        scanf("%c",&c);

                        if(c=='s'){
                            leer(&pilaA);
                        }
                    }
                    while(!pilavacia(&pilaA)){

                        acumulador = acumulador + tope(&pilaA);
                        apilar(&AUX,desapilar(&pilaA));
                    }

                    printf("La suma de los elementos es %i\n",acumulador);

                    }break;

                case 2:{

                    Pila pilaEle,AUX;
                    inicpila(&AUX);
                    inicpila(&pilaEle);

                    int contador=0;

                    char c='s';

                    while(c=='s'){
                        printf("Quiere ingresar un dato a la Pila? s/n\n");
                        fflush(stdin);
                        scanf("%c",&c);

                        if(c=='s'){
                            leer(&pilaEle);
                        }
                    }
                    while(!pilavacia(&pilaEle)){
                            apilar(&AUX,desapilar(&pilaEle));
                            contador ++;
                    }
                    printf("La cantidad de elementos de la Pila es %i\n",contador);
                }

                case 3:{

                    int acumulador=0;
                    int contador=0;

                    Pila pilaA,AUX;
                    inicpila(&AUX);
                    inicpila(&pilaA);

                    char c='s';

                    while(c=='s'){
                        printf("Quiere ingresar un dato a la Pila? s/n\n");
                        fflush(stdin);
                        scanf("%c",&c);

                        if(c=='s'){
                            leer(&pilaA);
                            contador ++;
                        }
                    }
                    while(!pilavacia(&pilaA)){

                        acumulador = acumulador + tope(&pilaA);
                        apilar(&AUX,desapilar(&pilaA));
                    }
                    int promedio = acumulador/contador;
                    printf("El promedio de los valores de la pila es %i\n",promedio);
                }

                case 4:{

                    Pila cuaTro,AUX,MENOR;
                    inicpila(&AUX);
                    inicpila(&MENOR);
                    inicpila(&cuaTro);

                    char c='s';

                    while(c=='s'){
                        printf("Quiere ingresar un dato a la Pila? s/n\n");
                        fflush(stdin);
                        scanf("%c",&c);

                        if(c=='s'){
                            leer(&cuaTro);
                        }
                    }
                    apilar(&MENOR,desapilar(&cuaTro));
                    while(!pilavacia(&cuaTro)){

                            if(tope(&cuaTro)>tope(&MENOR)){

                                apilar(&AUX,desapilar(&cuaTro));
                            }
                            else if(tope(&cuaTro)<tope(&MENOR)){

                                apilar(&AUX,desapilar(&MENOR));
                                apilar(&MENOR,desapilar(&cuaTro));
                            }
                            else{
                                apilar(&AUX,desapilar(&cuaTro));
                            }
                    }
                    while(!pilavacia(&AUX)){
                        apilar(&cuaTro,desapilar(&AUX));
                    }
                    printf("El elemento menor es\n");
                    mostrar(&MENOR);
                    printf("La pila original quedaria\n");
                    mostrar(&cuaTro);
                }
                break;

                case 5:{
                    Pila ORDENADA,TOPE,AUX;
                    inicpila(&TOPE);
                    inicpila(&AUX);
                    inicpila(&ORDENADA);

                      apilar(&ORDENADA,40);
                      apilar(&ORDENADA,35);
                      apilar(&ORDENADA,30);
                      apilar(&ORDENADA,27);
                      apilar(&ORDENADA,24);
                      apilar(&ORDENADA,20);
                      apilar(&ORDENADA,15);
                      apilar(&ORDENADA,10);
                      apilar(&ORDENADA,5);
                      apilar(&ORDENADA,2);

                    printf("Pila Ordenada\n");
                      mostrar(&ORDENADA);


                     leer(&TOPE);

                     while(!pilavacia(&TOPE)){

                        if(tope(&TOPE)>tope(&ORDENADA)){

                           apilar(&AUX,desapilar(&ORDENADA));

                           }else{

                           apilar(&ORDENADA,desapilar(&TOPE));

                           }
                     }
                     while(!pilavacia(&AUX)){

                        apilar(&ORDENADA,desapilar(&AUX));
                     }
                     mostrar(&ORDENADA);
                     }break;

                     case 6:{

                        Pila PRIMERA,MENOR,AUX1,AUX2;
                        inicpila(&PRIMERA);
                        inicpila(&AUX2);
                        inicpila(&MENOR);
                        inicpila(&AUX1);

                        int i=1,cantidad;

                        printf("Llenar primer PILA\n\n");


                    printf("Cuantos elementos quiere ingresar en la pila PRIMERA\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos\n");
                    for(i=1;i<=cantidad;i++){
                        leer(&PRIMERA);
                    }

                    printf("Pila PRIMERA\n");
                    mostrar(&PRIMERA);
                    apilar(&MENOR,desapilar(&PRIMERA));
                    while(!pilavacia(&PRIMERA)){

                            if(tope(&PRIMERA)>tope(&MENOR)){

                                apilar(&AUX1,desapilar(&PRIMERA));
                            }
                            else if(tope(&PRIMERA)<tope(&MENOR)){

                                apilar(&AUX1,desapilar(&MENOR));
                                apilar(&MENOR,desapilar(&PRIMERA));
                            }
                            else{
                                apilar(&MENOR,desapilar(&PRIMERA));
                            }
                            while(!pilavacia(&AUX1)){
                                    apilar(&MENOR,desapilar(&AUX1));
                                if(tope(&AUX1)>tope(&MENOR)){

                                apilar(&PRIMERA,desapilar(&AUX1));
                            }
                            else if(tope(&AUX1)<tope(&MENOR)){

                                apilar(&PRIMERA,desapilar(&MENOR));
                                apilar(&MENOR,desapilar(&AUX1));
                            }
                            else{
                                apilar(&MENOR,desapilar(&AUX1));
                            }
                            }
                    }
                    printf("Pila Menor\n");
                    mostrar(&MENOR);
                    }break;

                    case 7:{

                    Pila DADA,AUX1;
                    inicpila(&AUX1);
                    inicpila(&DADA);

                    int elemento=0,i=1,cantidad;

                    printf("Llenar Pila ejemplo\n");

                    printf("Cuantos elementos quiere ingresar en la Pila Ejemplo\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos\n");
                    for(i=1;i<=cantidad;i++){
                        leer(&DADA);
                    }

                    printf("\nIngrese elemento a buscar\n");
                    scanf("%i",&elemento);

                    if(elemento==tope(&DADA)){
                        printf("El elemento buscado esta en la PILA\n");
                    }
                    while(!pilavacia(&DADA) && elemento!=tope(&DADA)){
                        apilar(&AUX1,desapilar(&DADA));

                    }
                      if(pilavacia(&DADA)){
                        printf("El elemento no se encuentra en la Pila\n");
                      }else if(!pilavacia(&DADA)){
                        printf("El elemento si se encuentra en la Pila\n");
                      }

                      while(!pilavacia(&AUX1)){
                        apilar(&DADA,desapilar(&AUX1));
                      }
                      mostrar(&DADA);

                      printf("El elemento buscado es %i\n",elemento);


                    }break;

                    case 8:{

                             Pila DADA,AUX1;
                    inicpila(&AUX1);
                    inicpila(&DADA);

                    int elemento=0;
                    int i=1,cantidad;


                    printf("Cuantos elementos quiere ingresar en la Pila Ejemplo\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos\n");
                    for(i=1;i<=cantidad;i++){
                        leer(&DADA);
                    }

                    printf("\nIngrese elemento a eliminar\n");
                    scanf("%i",&elemento);

                    if(elemento==tope(&DADA)){
                        desapilar(&DADA);
                    }
                    while(!pilavacia(&DADA) && elemento!=tope(&DADA)){
                        apilar(&AUX1,desapilar(&DADA));

                    }
                      if(pilavacia(&DADA)){
                        printf("El elemento no se encuentra en la Pila\n");
                      }else if(elemento==tope(&DADA)){
                        desapilar(&DADA);
                      }

                      while(!pilavacia(&AUX1)){
                        apilar(&DADA,desapilar(&AUX1));
                      }
                      mostrar(&DADA);
                    }break;

                    case 9:{

                    Pila CAPICUA,CLON,AUX,AUX2;
                    inicpila(&CAPICUA);
                    inicpila(&CLON);
                    inicpila(&AUX);
                    inicpila(&AUX2);

                    int i=1,cantidad;

                    printf("Cuantos elementos quiere ingresar en la pila CAPICUA\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos\n");
                    for(i=1;i<=cantidad;i++){
                        leer(&CAPICUA);
                    }
                    while(!pilavacia(&CAPICUA)){

                        apilar(&CLON,tope(&CAPICUA));
                        apilar(&AUX,desapilar(&CAPICUA));

                    }

                    while(!pilavacia(&AUX)){
                        apilar(&CAPICUA,desapilar(&AUX));
                    }
                    while(!pilavacia(&CAPICUA) && tope(&CAPICUA)==tope(&CLON))
                    {

                        if(tope(&CAPICUA)==tope(&CLON)){
                            apilar(&AUX,desapilar(&CLON));
                            apilar(&AUX2,desapilar(&CAPICUA));
                        }
                    }

                    if(!pilavacia(&CAPICUA)){
                        printf("\nLa pila no es capicua\n\n");
                    }
                    else{
                        printf("\nLa pila es capicua\n\n");
                    }
                    }break;


                    case 10:{

                        Pila A,B,C,AUX,DESCARTE,ingreso;
                        inicpila(&A);
                        inicpila(&B);
                        inicpila(&C);
                        inicpila(&AUX);
                        inicpila(&DESCARTE);
                        inicpila(&ingreso);

                        int i=1,cantidad;

                        printf("Cuantos elementos quiere ingresar en la pila A\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos\n");
                    for(i=1;i<=cantidad;i++){
                        leer(&A);
                    }
                    printf("Cuantos elementos quiere ingresar en la pila B\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos\n");
                    for(i=1;i<=cantidad;i++){
                        leer(&B);
                    }

                    printf("La union entre las 2 pilas es \n");

                    while(!pilavacia(&A)){
                        apilar(&AUX,desapilar(&A));
                        apilar(&C,desapilar(&AUX));
                    }
                    while(!pilavacia(&B)){

                        if(tope(&B)==tope(&C)){
                            apilar(&DESCARTE,desapilar(&B));
                        }
                        else if(tope(&B)!=tope(&C) && !pilavacia(&C)){
                            apilar(&AUX,desapilar(&C));
                        }
                        else if(pilavacia(&C)){
                            apilar(&ingreso,desapilar(&B));
                            while(!pilavacia(&AUX)){
                                apilar(&C,desapilar(&AUX));
                            }
                        }
                    }
                    while(!pilavacia(&AUX)){
                        apilar(&C,desapilar(&AUX));
                    }
                    while(!pilavacia(&ingreso)){
                        apilar(&C,desapilar(&ingreso));
                    }

                    mostrar(&C);

                    }break;


                    case 11:{

                        Pila ORDENADA1,ORDENADA2,ORDENADAFINAL,AUX,ingreso;
                        inicpila(&ORDENADA1);
                        inicpila(&ORDENADA2);
                        inicpila(&ORDENADAFINAL);
                        inicpila(&AUX);
                        inicpila(&ingreso);

                        int i=1,cantidad;

                        printf("Cuantos elementos quiere ingresar en la pila ORDENADA1\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos de forma creciente\n");
                    for(i=1;i<=cantidad;i++){
                        leer(&ORDENADA1);
                    }
                    printf("Cuantos elementos quiere ingresar en la ORDENADA2\n");
                    scanf("%i",&cantidad);
                    printf("Ingrese los elementos de forma creciente \n");
                    for(i=1;i<=cantidad;i++){
                        leer(&ORDENADA2);
                    }

                    while(!pilavacia(&ORDENADA1)){
                        apilar(&AUX,desapilar(&ORDENADA1));
                    }
                    while(!pilavacia(&AUX)){
                        apilar(&ORDENADAFINAL,desapilar(&AUX));
                    }
                    while(!pilavacia(&ORDENADA2)){

                        if(tope(&ORDENADA2)>tope(&ORDENADAFINAL)){

                           apilar(&ORDENADAFINAL,desapilar(&ORDENADA2));

                           }
                           else if(tope(&ORDENADA2)<tope(&ORDENADAFINAL) && !pilavacia(&ORDENADAFINAL)){

                           apilar(&AUX,desapilar(&ORDENADAFINAL));

                           }
                           else if(tope(&ORDENADA2)==tope(&ORDENADAFINAL) && !pilavacia(&ORDENADAFINAL)){

                           apilar(&ORDENADAFINAL,desapilar(&ORDENADA2));
                           }
                           else if(pilavacia(&ORDENADAFINAL)){
                            while(!pilavacia(&ORDENADA2)){
                                apilar(&ingreso,desapilar(&ORDENADA2));
                            }
                            while(!pilavacia(&ingreso)){
                                apilar(&ORDENADAFINAL,desapilar(&ingreso));
                            }
                            while(!pilavacia(&AUX)){
                                apilar(&ORDENADAFINAL,desapilar(&AUX));
                            }
                           }
                     }
                     mostrar(&ORDENADAFINAL);
                     mostrar(&ORDENADA2);



                    }break;

                    case 12:{

                        Pila ORIGEN,AUX,AUX2,destino;
                        inicpila(&AUX);
                        inicpila(&AUX2);
                        inicpila(&destino);
                        inicpila(&ORIGEN);

                        int i=1,cantidad;

                         printf("Cuantos elementos quiere ingresar en la ORIGEN\n");
                        scanf("%i",&cantidad);

                        for(i=1;i<=cantidad;i++){
                        leer(&ORIGEN);
                        }

                        for(i=1;i<=cantidad;i++){

                        apilar(&AUX,desapilar(&ORIGEN));

                        while(!pilavacia(&ORIGEN)){

                            if(tope(&ORIGEN)>tope(&AUX)){
                                apilar(&AUX2,desapilar(&ORIGEN));
                            }
                            else if(tope(&ORIGEN)<tope(&AUX)){
                                apilar(&AUX2,desapilar(&AUX));
                                apilar(&AUX,desapilar(&ORIGEN));
                            }
                        }
                        while(!pilavacia(&AUX2)){
                            apilar(&ORIGEN,desapilar(&AUX2));
                            }
                        }
                        while(!pilavacia(&AUX)){
                            apilar(&ORIGEN,desapilar(&AUX));
                        }

                        mostrar(&ORIGEN);
                    }break;


                    case 13:{


                            printf("No logre resolver el ejercicio, intente usar funcion srand y rand() pero no pude\n");
                            printf("Revisar CODIGO\n");

                        Pila MAZO,AUX1,AUX2;
                        Pila mazoJug1,mazoJug2;
                        inicpila(&mazoJug1);
                        inicpila(&mazoJug2);
                        inicpila(&AUX1);
                        inicpila(&AUX2);
                        inicpila(&MAZO);

                        int PUNTOSJUG1=0,PUNTOSJUG2=0;

                        apilar(&MAZO,1);
                        apilar(&MAZO,2);
                        apilar(&MAZO,3);
                        apilar(&MAZO,4);
                        apilar(&MAZO,5);
                        apilar(&MAZO,6);
                        apilar(&MAZO,7);
                        apilar(&MAZO,8);
                        apilar(&MAZO,9);
                        apilar(&MAZO,10);
                        apilar(&MAZO,11);
                        apilar(&MAZO,12);
                        apilar(&MAZO,13);
                        apilar(&MAZO,14);
                        apilar(&MAZO,15);
                        apilar(&MAZO,16);
                        apilar(&MAZO,17);
                        apilar(&MAZO,18);
                        apilar(&MAZO,19);
                        apilar(&MAZO,20);

                        int valor=20;
                        srand(time(NULL));
                        rand()%valor;

                        int contador;
                        contador=0;

                        char ronda='s';

                        while(ronda=='s'){
                        printf("Quiere repartir una mano? s/n\n");
                        fflush(stdin);
                        scanf("%c",ronda);

                        if(ronda=='s'){


                            for(contador=0;contador<=rand()%valor;contador++){
                                apilar(&AUX1,desapilar(&MAZO));
                            }
                            apilar(&mazoJug1,desapilar(&MAZO));

                            while(!pilavacia(&AUX1)){
                                apilar(&MAZO,desapilar(&AUX1));
                            }
                            valor = valor-1;
                            for(contador=0;contador<=rand()%valor;contador++){
                                apilar(&AUX1,desapilar(&MAZO));
                            }

                            apilar(&mazoJug1,desapilar(&MAZO));

                            while(!pilavacia(&AUX1)){
                                apilar(&MAZO,desapilar(&AUX1));
                            }
                            valor = valor-1;

                        }

                        }//Fin del While

                        mostrar(&mazoJug1);


                    }
                default:{
                    printf("");
                }
            }
        }
    }
return 0;
}

















































