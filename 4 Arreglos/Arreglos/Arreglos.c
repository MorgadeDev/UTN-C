#include <stdbool.h>
#include "pila.h"


int cargaArray(int arr[],int dimension);
void mostrarArreglo(int arr[], int validos);
int sumaElementos(int arr[],int validos);
void copiarElementos(int arr[],int validos,Pila *destino);
int buscarChar(char arr[],int validos,char buscado);
float cargaArrayFloat(float arr[]);
void mostrarArregloFloat(float arr[],int validos);
int insertarCaracter(char arr[],char c,int validos);
void mostrar_a_char(char arr[], int validos);
char maximoCaracter(char arr[],int validos);
void invertirElementos(int arr[],int validos);
int esCapi(int arr[],int validos);
int posiMenor(int arr[],int validos,int posi);
void ordenSeleccion(int arr[],int validos);
void intercambio(int *a,int*b);
void arregloOrdenado(char primero[],int validos1,char segundo[],int validos2,char resultado[],int validos3);
void insertarCharOrdenado(char arr[],char c,int validos);
int posiMenorChar(char arr[],int validos,int posi);
void sumaVector(int arry1[],int validos1,int arry2[],int resu[]);

// 1
int cargaArray(int arr[],int dimension)
{
    char cont='s';
    int validos=0;
    int elementos =0;

    printf("Cuantos elementos quiere ingresar al arr[]?,");
    printf("( de dimesion %i)\n",dimension);

    scanf("%i",&elementos);

    for(int i=0; i<elementos && cont == 's'; i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d",&arr[i]);

        validos++;

    }
    printf("La cantidad de elementos cargados es %i\n",elementos);

    return validos;
}

//2
void mostrarArreglo(int arr[], int validos)
{
    for (int i=0;i<validos;i++)
    {
        printf("|%i|",arr[i]);
    }
}


//3
int sumaElementos(int arr[],int validos)
{
    int suma=0;

    for(int i=0;i<validos;i++)
    {
        suma = suma + arr[i];
    }
    return suma;
}

//4
void copiarElementos(int arr[],int validos,Pila *destino)
{
    int elemento;

    for(int i=0;i<validos;i++)
    {
        elemento = arr[i];
        apilar(destino,elemento);
    }
}

//5
float cargaArrayFloat(float arr[]){
        char cont='s';
        int validos=0;
        int elementos =0;

        printf("Cuantos elementos quiere ingresar al arr[]? de dimesion 100\n");

        scanf("%i",&elementos);

        for(int i=0; i<elementos && cont == 's'; i++)
        {
            printf("Ingrese un numero\n");
            scanf("%f",&arr[i]);

            validos++;

        }
        printf("La cantidad de elementos cargados es %i\n",elementos);

        return validos;
}
void mostrarArregloFloat(float arr[],int validos)
{
    for (int i=0;i<validos;i++)
    {
        printf("|%f|",arr[i]);
    }
    float sum=0;
    for(int i=0;i<validos;i++)
    {
        sum = sum + arr[i];
    }
    printf("La suma de los elementos es %f\n",sum);

}

//6
int buscarChar(char arr[],int validos,char buscado){

    int i=0;
    int flag =0;

    while(i<validos && flag ==0)
    {
        if(buscado == arr[i])
        {
            flag =1;
        }else
        {
            i++;
        }
    }
    return flag;
}

//7

int insertarCaracter(char arr[],char c,int validos)
{
    int i=validos-1;

    while(i>=0 && c<arr[i])
    {

            arr[i+1]=arr[i];
            i--;
        }

            arr[i+1]=c;

return validos+1;
}

void mostrar_a_char(char arr[], int validos)
{
    for (int i=0;i<validos;i++)
    {
        printf("|%c|",arr[i]);
    }
}

//8
char maximoCaracter(char arr[],int validos)
{
    int i=0;
    char caracter;
    caracter=arr[i];
    for(i=1;i<validos;i++)
    {
        if(caracter<arr[i])
        {
            caracter=arr[i];
        }
    }
    return caracter;
}
//9
int esCapi(int arr[],int validos)
{
    int vuelta=validos-1;
    int i=0,flag=0;
    while(i<validos && flag==0)
    {
        if(arr[i]==arr[vuelta])
        {
            i++;
            vuelta--;
        }else{

        flag=1;

        }

    }
    return flag;

}


//10

void invertirElementos(int arr[],int validos)
{
    int i=0,aux1,aux2;
    int rev=validos-1;
    while(i!=rev && i<rev)
    {
        aux1=arr[i];
        arr[i]=arr[rev];
        arr[rev]=aux1;
        rev--;
        i++;
    }
}

//11 ERROR
int posiMenor(int arr[],int validos,int posi)
{
    int i=0,menor;
    menor=arr[posi];
    int pos_Menor=posi;
    while(i<validos)
    {
        if(arr[i]<menor)
        {
            menor=arr[i];
            pos_Menor=i;
        }
        i++;
    }
    return pos_Menor;
}
void ordenSeleccion(int arr[],int validos)
{
    int i=0,posmenor=0,aux;
    while(i<validos-1)
    {
        posmenor=posiMenor(arr,validos,posmenor);
        intercambio(&arr[posmenor],&arr[i]);
        i++;
    }
}
void intercambio(int *a,int*b)
{
    int aux;
    aux=*a;
    *a =*b;
    *b=aux;
}

// 12
void arregloOrdenado(char primero[],int validos1,char segundo[],int validos2,char resultado[],int validos3)
{
    int i=0,posi1=0,posi2=0;
    while(i<validos3)
    {
        if(validos1!=0)
        {
            posi1 = posiMenorChar(primero,validos1,posi1);
            resultado[i]=primero[posi1];
            validos1--;
            i++;
            primero[posi1]=primero[posi1+1];
        }
        if(validos2!=0)
        {
            posi2 = posiMenorChar(segundo,validos2,posi2);
            resultado[i]=segundo[posi2];
            validos2--;
            i++;
            segundo[posi2]=segundo[posi2+1];
        }

    }
}
// 13
void sumaVector(int arry1[],int validos1,int arry2[],int resu[])
{
    int i=0;
    while(i<validos1)
    {
        resu[0]=resu[0]+arry1[i]+arry2[i];
        i++;
    }
}



int posiMenorChar(char arr[],int validos,int posi)
{
    int i=0,menor;
    menor=arr[posi];
    int pos_Menor=posi;
    while(i<validos)
    {
        if(arr[i]<menor)
        {
            menor=arr[i];
            pos_Menor=i;
        }
        i++;
    }
    return pos_Menor;
}





int main()
{

    int op;
    char c='s';

    while(c=='s'){

        printf("\nQuiere ingresar un ejercicio? s/n\n");
        fflush(stdin);
        scanf("%c",&c);

    if(c=='s'){
        printf("\nIngrese ejercicio del TP \n\n");
    scanf("%i",&op);

            switch (op)
            {
                case 1:{
                    int arregloEmp[10];
                    int validos;
                    validos =0;

                    validos = cargaArray(arregloEmp,10);


                }break;

                case 2:{
                    int arregloEmp[10];
                    int validos;
                    validos =0;

                    validos = cargaArray(arregloEmp,10);

                    mostrarArreglo(arregloEmp,validos);
                }break;

                case 3:{
                    int arregloEmp[10];
                    int validos;
                    validos =0;
                    int sum=0;

                    validos = cargaArray(arregloEmp,10);
                    sum= sumaElementos(arregloEmp,validos);

                    printf("La suma de los elementos es %i\n",sum);
                }break;

                case 4:{
                    int arregloEmp[10];
                    int validos;
                    validos =0;
                    Pila arreglo;
                    inicpila(&arreglo);

                    validos = cargaArray(arregloEmp,10);

                    copiarElementos(arregloEmp,validos,&arreglo);
                    printf("Pila creada del arreglo\n");
                    mostrar(&arreglo);
                }break;

                case 5:{
                    float arregloEmp[100];
                    int validos;
                    validos =0;
                    float sum=0;

                    validos = cargaArrayFloat(arregloEmp);
                    mostrarArregloFloat(arregloEmp,validos);


                }break;

                case 6:{

                    int arreglo[10];
                    int validos=0,resu;
                    char buscado;

                    printf("Ingrese strings maximo 10 caracteres\n");
                    fflush(stdin);
                    gets(arreglo);

                    printf("Ingrese caracter a buscar\n");
                    scanf("%c",&buscado);

                    validos =strlen(arreglo);

                    resu = buscarChar(arreglo,validos,buscado);

                    if(resu == 1){
                        printf("El elemento esta en el arreglo\n");
                    }else if(resu == 0){
                        printf("El elemento no esta en el arreglo\n");
                    }

                }break;

                case 7:{

                    char arreglo[26]={'a','b','e','f','r','t','v','x','y','z'};
                    int validos=10;
                    char caracter;

                    printf("Ingrese caracter\n");
                    fflush(stdin);
                    scanf("%c",&caracter);

                    validos=insertarCaracter(arreglo,caracter,validos);

                    mostrar_a_char(arreglo,validos);


                }break;

                case 8:{

                    char arreglo[10]={'c','a','r','p','v','b'};
                    char maximo;
                    int  validos=6;

                    maximo = maximoCaracter(arreglo,validos);

                    printf("El maximo caracter es %c\n",maximo);

                }break;

                case 9:{

                    {
                        int arr[10]={1,2,3,2,1,5};
                        int validos=6;
                        int flag;

                        flag =esCapi(arr,validos);
                        if(flag==1){


                        printf("No es capi");
                        }else{
                        printf("Es capi");
                        }
                    }

                }break;

                case 10:{
                    int arr[10]={1,2,3,4,5,6,7,8,9,10};
                    int validos=10;

                invertirElementos(arr,validos);

                mostrarArreglo(arr,validos);

                }break;

                case 11:{
                    int arr[10]={10,2,7,1,9,8,4,3,11,5};
                    int validos=10;


                    ordenSeleccion(arr,validos);

                    mostrarArreglo(arr,validos);


                }break;

                case 12:{
                      char primero[]={'a','c'};
                      int validos1=2;
                      char segundo[]={'b','d'};
                        int validos2=2;
                        int validos3=validos1+validos2;
                        char resultado[validos3];

                        arregloOrdenado(primero,validos1,segundo,validos2,resultado,validos3);

                        mostrar_a_char(resultado,validos3);
                }break;

                case 13:{
                    int primero[5]={1,5,6,7,8};
                    int segundo[5]={1,6,12,19,27};
                    int resu[5];
                    int validos1=5;

                    sumaVector(primero,validos1,segundo,resu);
                    mostrarArreglo(resu,1);

                }


                default:{
                }
            }
        }
    }

 return 0;
}

