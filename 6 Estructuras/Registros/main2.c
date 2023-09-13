#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

//1
int cargarArrAlumnos(stAlumno arr[],int dimension)
{
    int i=0;
    char condi ='s';

    while(condi=='s' && i<dimension)
    {
        printf("Quiere ingresar un alumno?  s/n\n");
        fflush(stdin);
        scanf("%c",&condi);

        if(condi =='s'){
            printf("Ingrese numero de matricula del alumno\n");
            fflush(stdin);
            scanf("%i",&arr[i].matricula);

            printf("Ingrese nombre del Alumno\n");
            fflush(stdin);
            gets(arr[i].nombre);

            printf("Ingrese genero del Alumno M/F/O(otro)\n");
            fflush(stdin);
            scanf("%c",&arr[i].genero);
        i++;
        }
    }
    return i;
}
//2
void mostrarAlumno(stAlumno A)
{
    printf("Matricula: %i\n",A.matricula);
    printf("Nombre: %s\n",A.nombre);
    printf("Genero: %c\n",A.genero);
}
void mostrarArrAlumnos(stAlumno arr[],int validos)
{
   int i=0;
   if(validos==0)
   {
       printf("--El arreglo esta vacio--\n");
   }else
   {
   for(i;i<validos;i++)
   {
       printf("-----------Alumno Posicion=%i-----------\n",i);
       mostrarAlumno(arr[i]);
   }
   }
}
//3
int posiMatricula(stAlumno arr[],int matri,int validos)
{
    int posi=0;
    int i=0;

    for(i;i<validos;i++)
    {
        if(arr[i].matricula==matri)
        {
            posi=i;
        }
    }
    return posi;
}
void mostrarDatosxMatricula(stAlumno arr[],int matri,int validos)
{
    int posi=posiMatricula(arr,matri,validos);

    printf("Matricula: %i\n",arr[posi].matricula);
    printf("Nombre: %s\n ",arr[posi].nombre);
    printf("Genero: %c\n",arr[posi].genero);

}
//4
int posiMenor(stAlumno arr[],int pos,int validos)
{
    int i=pos+1;
    int menor=arr[pos].matricula;
    int posMenor=pos;

    while(i<validos)
    {
        if(menor>arr[i].matricula)
        {
            menor=arr[i].matricula;
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}
void ordenSeleccion(stAlumno arr[],int validos)
{
    int i=0;
    int aux=0;
    char auxNom[30]={};
    char auxGen;
    int posmenor=0;

    while(i<validos-1)
    {
        posmenor=posiMenor(arr,i,validos);

        aux=arr[i].matricula;
        arr[i].matricula=arr[posmenor].matricula;
        arr[posmenor].matricula=aux;

        strcpy(auxNom,arr[i].nombre);
        strcpy(arr[i].nombre,arr[posmenor].nombre);
        strcpy(arr[posmenor].nombre,auxNom);

        auxGen=arr[i].genero;
        arr[i].genero=arr[posmenor].genero;
        arr[posmenor].genero=auxGen;


        i++;
    }

}
//5
void muestraXGenero(stAlumno arr[],int validos,char genero)
{

    int i=0;

    printf("ALUMNOS %c\n",genero);
    for(i;i<validos;i++)
    {
        if(arr[i].genero==genero)
        {
            printf("\n--------------\n");
            mostrarAlumno(arr[i]);
            printf("--------------\n");
        }
    }
}
//6
int insertarElemento(stAlumno arr[],int validos,stAlumno A)
{
    int i=validos-1;
    int espacio=validos;
    int posi=0;

    while(i>0 && A.matricula<arr[i].matricula)
    {
        arr[espacio].matricula=arr[i].matricula;
        arr[espacio].genero=arr[i].genero;
        strcpy(arr[espacio].nombre,arr[i].nombre);
        i--;
        espacio--;
    }
    arr[i+1].matricula=A.matricula;
    arr[i+1].genero=A.genero;
    strcpy(arr[i+1].nombre,A.nombre);
    int val=validos+1;

    return val;
}
//7
void ordenXNombre(stAlumno arr[],int validos)
{
    stAlumno aux;
    int i;

    for(i=0;i<validos;i++)
    {
        aux = arr[i];

        while(pos>0 && strcmp(arr[pos-1].nombre,aux)==1)
        {
            strcpy(arr[pos].nombre,arr[pos-1].nombre);
            arr[pos].matricula=arr[pos-1].matricula;
           arr[pos].genero=arr[pos-1].genero;

            pos--;
        }
        strcpy(arr[pos].nombre,aux);
        arr[pos].matricula=matriAux;
        arr[pos].genero=genAux;
    }
}
//8
int cuentaGenero(stAlumno arr[],int validos,char genero)
{
    int i=0;
    int contador=0;

    for(i;i<validos;i++)
    {
        if(arr[i].genero==genero)
        {
            contador++;
        }
    }
    return contador;
}
//9
int main()
{
    char c='s';
    int op;
    stAlumno arr[10]={};
    int validos=0;
    char reinicio;


    while(c=='s')
    {   printf("\n----Quiere ingresar una Funcion? s/n----\n");
        fflush(stdin);
        scanf("%c",&c);
        if(c=='n')
        {
            printf("Quiere reiniciar las variables y vaciar el arrelgo? s/n \n");
            fflush(stdin);
            scanf("%c",&reinicio);

            if(reinicio=='s')
            {
                validos=0;
                c='s';
            }
        }
    if(c=='s'){
        printf("\nIngrese funcion del TP 6 \n\n");
        printf(" 1 = Cargar un arreglo de alumnos\n");
        printf(" 2 = Mostrar arreglo de alumnos\n");
        printf(" 3 = Mostrar alumno por matricula\n");
        printf(" 4 = Ordenar arreglo por matricula\n");
        printf(" 5 = Mostrar alumno por genero\n");
        printf(" 6 = Insertar alumno ordenado\n");
        printf(" 7 = Orden arreglo por insercion\n");
        printf(" 8 = Cantidad alumnos por genero\n");
        printf("\n --Ingrese numero de funcion--\n");
        scanf("%i",&op);

            switch (op)
            {

                case 1:{
                            printf("\n--------Cargar Arry Alumnos--------\n");

                            validos=cargarArrAlumnos(arr,10);
                } break;
                case 2:{
                            printf("--------Muestra Arry Alumnos--------\n");

                            mostrarArrAlumnos(arr,validos);
                } break;
                case 3:{
                            printf("--------Muestra Arry x matricula--------\n");

                            int matri;
                            printf("\nIngrese matricula a mostrar\n");
                            scanf("%i",matri);

                            mostrarDatosxMatricula(arr,matri,validos);
                } break;
                case 4:{
                            printf("--------Orden de arreglo por Seleccion--------\n");

                            ordenSeleccion(arr,validos);

                            mostrarArrAlumnos(arr,validos);
                } break;
                case 5:{
                           printf("--------Mostrar Arry x genero--------\n");

                           char genero;
                           printf("Ingrese genero a mostrar  m/f/o \n");
                           fflush(stdin);
                           scanf("%c",&genero);

                           muestraXGenero(arr,validos,genero);
                }   break;
                case 6:{
                            printf("--------Insertar Alumno en orden--------\n");

                            stAlumno ingreso;
                            printf("Ingrese matricula del alumno\n");
                            scanf("%i",&ingreso.matricula);
                            printf("Ingrese nombre del alumno\n");
                            fflush(stdin);
                            gets(ingreso.nombre);
                            printf("Ingrese genero del alumno m/f/o \n");
                            scanf("%c",&ingreso.genero);

                            insertarElemento(arr,validos,ingreso);

                            mostrarArrAlumnos(arr,validos);
                } break;
                case 7:{
                          printf("--------Orden alumnos x Nombre--------\n");
                          ordenXNombre(arr,validos);
                } break;
                case 8:{
                           printf("--------Cantidad de alumnos x genero--------\n");

                           int cantidad;
                           char gen;

                           printf("Ingrese genero a contar  m/f/o \n");
                           fflush(stdin);
                           scanf("%c",&gen);

                            cantidad=cuentaGenero(arr,validos,gen);

                            printf("La cantidad de alumnos %c es %i\n",gen,cantidad);
                } break;
                default:{
                        printf("Caso default\n");
                }
            }
        }
    }
    printf("Fin del programa\n");
    return 0;
}

        /*
        strcpy(aux,arr[i].nombre);
        matriAux=arr[i].matricula;
        genAux=arr[i].genero;
        */
