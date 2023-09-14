#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

typedef struct{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
}stAlumno;

//1
void agregarFinalINT(char primerArchivo[30],int elemento)
{
    FILE *archivo = fopen(primerArchivo,"ab");

    if(archivo!=NULL)
    {
        fwrite(&elemento,sizeof(int),1,archivo);
        fclose(archivo);
    }else
    {
        printf("El archivo no existe\n");
    }
}
//2
void mostrarArchivoINT(char primerArchivo[30])
{
    FILE *archivo= fopen(primerArchivo,"rb");
    int elemento;

    if(archivo!=NULL)
    {
        while(fread(&elemento,sizeof(int),1,archivo)>0)
        {
            printf("Elemento: %i\n",elemento);
        }
        fclose(archivo);
    }
}
//3
int cantidadRegistrosINT(char primerArchivo[30])
{
    FILE *archivo = fopen(primerArchivo,"rb");
    int elemento;
    int contador=0;

    if(archivo!=NULL)
    {
        while(fread(&elemento,sizeof(int),1,archivo)>0){
            contador++;
        }
        fclose(archivo);
    }
    return contador;
}
//4
void cargaAlumno(char primerArchivo[30])
{
    FILE *archivo = fopen(primerArchivo,"rb");

    stAlumno alu;
    int cuantos=0;
    int i;

    if(archivo==NULL)
    {
        fclose(archivo);
        printf("El archivo no existe y va a ser creado\n");
        archivo= fopen(primerArchivo,"wb");

        printf("\nCuantos alumnos quiere cargar? (Condicion del ejercicio Cargar 5)\n");
        scanf("%i",&cuantos);

        for(i;i<cuantos;i++)
        {
            printf("Ingrese legajo del alumnos\n");
            scanf("%i",&alu.legajo);

            printf("Ingrese nombre y apellido\n");
            fflush(stdin);
            gets(alu.nombreYapellido);

            printf("Ingrese edad del alumno\n");
            scanf("%i",&alu.edad);

            printf("Ingrese anio que cursa el alumno\n");
            scanf("%i",&alu.anio);

            fwrite(&alu,sizeof(stAlumno),1,archivo);
        }
    }
    else if(archivo!=NULL)
    {   fclose(archivo);

        archivo= fopen(primerArchivo,"ab");

        printf("El archivo existe\n");
        printf("\nCuantos alumnos quiere cargar?\n");
        scanf("%i",&cuantos);

        for(i;i<cuantos;i++)
        {
            printf("Ingrese legajo del alumnos\n");
            scanf("%i",&alu.legajo);

            printf("Ingrese nombre y apellido\n");
            fflush(stdin);
            gets(alu.nombreYapellido);

            printf("Ingrese edad del alumno\n");
            scanf("%i",&alu.edad);

            printf("Ingrese anio que cursa el alumno\n");
            scanf("%i",&alu.anio);

            fwrite(&alu,sizeof(stAlumno),1,archivo);
        }
    }
    fclose(archivo);
}
//5
void mostrarAlu(stAlumno alu)
{
    printf("Legajo: %i\n",alu.legajo);
    printf("Nombre y Apellido: %s\n",alu.nombreYapellido);
    printf("Edad: %i\n",alu.edad);
    printf("Anio: %i\n",alu.anio);
}
void mostrarArchivoAlumnos(char nombreArchivo[30])
{
     FILE *archivo = fopen(nombreArchivo,"rb");
     stAlumno alu;

     if(archivo!=NULL)
    {
        while(fread(&alu, sizeof(stAlumno),1,archivo)>0)
        {
            printf("\n---\n");
            mostrarAlu(alu);
            printf("---\n");
        }
        fclose(archivo);
    }
}
//6
void agregarAluFinal(char primerArchivo[30])
{
    FILE *archivo = fopen(primerArchivo,"ab");
    stAlumno alu;

    if(archivo!=NULL)
    {
        printf("Ingrese legajo del alumnos\n");
        scanf("%i",&alu.legajo);

        printf("Ingrese nombre y apellido\n");
        fflush(stdin);
        gets(alu.nombreYapellido);

        printf("Ingrese edad del alumno\n");
        scanf("%i",&alu.edad);

        printf("Ingrese anio que cursa el alumno\n");
        scanf("%i",&alu.anio);

        fwrite(&alu,sizeof(stAlumno),1,archivo);
    }
    fclose(archivo);
}
//7
void pasarPilaEdad(char primerArchivo[30],Pila *destino)
{

     FILE *archivo = fopen(primerArchivo,"rb");
     stAlumno alu;
     int legajoMayor=0;

     if(archivo!=NULL)
    {
        while(fread(&alu, sizeof(stAlumno),1,archivo)>0)
        {
            if(alu.edad>18)
            {
                legajoMayor=alu.legajo;
                apilar(destino,legajoMayor);
            }
        }
        fclose(archivo);
    }
    mostrar(destino);
}
//8
int cuentaAluEdad(char primerArchivo[30],int edad)
{
     FILE *archivo = fopen(primerArchivo,"rb");
     stAlumno alu;
     int contador=0;

     if(archivo!=NULL)
    {
        while(fread(&alu, sizeof(stAlumno),1,archivo)>0)
        {
            if(alu.edad>edad)
            {
                contador++;
            }
        }
        fclose(archivo);
    }
    return contador;
}
//9
int guardaNombreAlu(char primerArchivo[30],char guardado[30][30],int menor,int mayor)
{

    FILE *archivo= fopen(primerArchivo,"rb");
    int validos=0;
    stAlumno alu;

    if(archivo!=NULL){
     while(fread(&alu, sizeof(stAlumno),1,archivo)>0)
     {
         if(alu.edad>menor && alu.edad<mayor)
         {
             strcpy(guardado[validos],alu.nombreYapellido);
             validos++;
         }
     }
    }
     fclose(archivo);
     return validos;
}
void mostrarNombresXEdad(char primerArchivo[30],int menor,int mayor)
{
    char guardado[30][30]={};
    int validos;
    validos=guardaNombreAlu(primerArchivo,guardado,menor,mayor);

    int i=0;
    printf("\n");
    printf("Nombres de alumnos entre %i y %i anios\n",menor,mayor);
    printf("---\n");
    for(i;i<validos;i++)
    {

        printf("%s\n",guardado[i]);
        printf("---\n");
    }
}
//10
void mostrarMayor(char primerArchivo[30])
{
    stAlumno alu;
    stAlumno mayor;

    FILE *archivo = fopen(primerArchivo,"rb");

    if(archivo!=NULL)
    {
        fread(&mayor,sizeof(stAlumno),1,archivo);
        while(fread(&alu,sizeof(stAlumno),1,archivo)>0)
        {
            if(alu.edad>mayor.edad)
            {
                mayor.anio=alu.anio;
                mayor.edad=alu.edad;
                mayor.legajo=alu.legajo;
                strcpy(mayor.nombreYapellido,alu.nombreYapellido);
            }
        }
        fclose(archivo);
    }
    printf("\nEl alumno mas grande:\n");
    mostrarAlu(mayor);
}
//11
int cantidadXAnio(char primerArchivo[30],int anio)
{
    int cantidad=0;
    FILE *archivo = fopen(primerArchivo,"rb");

    stAlumno alu;

    if(archivo!=NULL)
    {
        while(fread(&alu,sizeof(stAlumno),1,archivo)>0)
        {
            if(alu.anio==anio)
            {
                cantidad++;
            }
        }
        fclose(archivo);
    }

    return cantidad;
}
//12 No funciona correctamente
void deArrAlArchivo(char primerArchivo[30],stAlumno arry[],int validos)
{
    stAlumno aux;
    FILE *archivo = fopen(primerArchivo,"ab");
    int i=0;

    if(archivo!=NULL)
    {
        for(i;i<validos;i++)
        {
            aux.anio=arry[i].anio;
            aux.edad=arry[i].edad;
            aux.legajo=arry[i].legajo;
            strcpy(aux.nombreYapellido,arry[i].nombreYapellido);
            fwrite(&aux,sizeof(stAlumno),1,archivo);
        }
    }
    fclose(archivo);
}
int deArchivoAArry(char primerArchivo[30],stAlumno arry[30],int dimension)
{
    stAlumno alu;
    FILE *archivo = fopen(primerArchivo,"rb");
    int i=0;
    int anio=0;

    printf("Ingrese año para filtrar alumnos\n");
    scanf("%i",&anio);

    if(archivo!=NULL)
    {
        while(fread(&alu,sizeof(stAlumno),1,archivo)>0)
        {
            if(alu.anio==anio && i<dimension)
            {
                arry[i].anio=alu.anio;
                arry[i].edad=alu.edad;
                arry[i].legajo=alu.legajo;
                strcpy(arry[i].nombreYapellido,alu.nombreYapellido);
                i++;
            }
        }
    fclose(archivo);
    }
    return i;
}
//13
int cantidadRegistro(char primerArchivo[30])
{
    FILE *archivo=fopen(primerArchivo,"rb");
    int resu=0;
    stAlumno alu;

    if(archivo!=NULL)
    {

        fseek(archivo,0,SEEK_END);
        resu=ftell(archivo)/sizeof(alu);

        fclose(archivo);
    }

    return resu;
}
//14
void mostrarSegunParametro(char primerArchivo[30],int numero)
{
    FILE *archivo = fopen(primerArchivo,"rb");
    stAlumno alu;

    if(archivo!=NULL)
    {
        fseek(archivo,sizeof(alu)*(numero),SEEK_SET);

        if(feof(archivo)==0)
        {
            fread(&alu,sizeof(alu),1,archivo);
            if(feof(archivo)==0)
            {
                mostrarAlu(alu);
            }else
            {
                printf("\nNo hay datos, superando limite de archivo\n");
            }



            fclose(archivo);
        }
    }
}
//15
void modificarRegistro(char primerArchivo[30])
{
    FILE *archivo = fopen(primerArchivo,"r+b");

    int legajo=0;
    long bytes=0;
    stAlumno alu;
    int flag=0;
    char condi='s';

    printf("Quiere modificar el archivo? s/n\n");
    fflush(stdin);
    scanf("%c",&condi);

    if(condi=='s')
    {

    printf("\nIngrese legajo de alumno a modificar\n");
    fflush(stdin);
    scanf("%i",&legajo);

    if(archivo!=NULL)
    {
        while(fread(&alu,sizeof(alu),1,archivo)>0  && flag==0)
        {
            if(alu.legajo==legajo)
            {
                flag=1;
                bytes=ftell(archivo);
            }
        }
      rewind(archivo);
      fseek(archivo,bytes-sizeof(alu),SEEK_SET);


      printf("Quiere modificar el nombre? s/n\n");
      fflush(stdin);
      scanf("%c",&condi);

      if(condi=='s')
      {
        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(alu.nombreYapellido);
      }
      printf("Quiere modificar el legajo? s/n\n");
      fflush(stdin);
      scanf("%c",&condi);

      if(condi=='s')
      {
          printf("Ingrese legajo\n");
          scanf("%i",&alu.legajo);
      }
      printf("Quiere modificar la edad? s/n\n");
      fflush(stdin);
      scanf("%c",&condi);

      if(condi=='s')
      {
          printf("ingrese edad\n");
          scanf("%i",&alu.edad);
      }
      printf("Quiere modificar el anio? s/n\n");
      fflush(stdin);
      scanf("%c",&condi);

      if(condi=='s')
      {
          printf("ingrese anio\n");
          scanf("%i",&alu.anio);
      }

      fwrite(&alu,sizeof(alu),1,archivo);
    }

    }
    fclose(archivo);


}
//16
void invertirArchivo(char primerArchivo[30])
{
    FILE *archivo = fopen(primerArchivo,"r+b");

    stAlumno alu;
    stAlumno aux;
    int i=0;
    int can=0;
    can=cantidadRegistro(primerArchivo);
    int vuelta=can;


    if(archivo!=NULL)
    {
        for(i;i<(can/2);i++)
        {
            fseek(archivo,sizeof(alu)*i,SEEK_SET);

            fread(&alu,sizeof(alu),1,archivo);

            fseek(archivo,sizeof(alu)*(vuelta-1),SEEK_SET);

            fread(&aux,sizeof(alu),1,archivo);



            fseek(archivo,sizeof(alu)*i,SEEK_SET);

            fwrite(&aux,sizeof(alu),1,archivo);

            fseek(archivo,sizeof(alu)*(vuelta-1),SEEK_SET);

            fwrite(&alu,sizeof(alu),1,archivo);

            vuelta--;
        }
        fclose(archivo);
        printf("nombre medio: %s\n",alu.nombreYapellido);

        printf("nombre vuelta: %s\n",aux.nombreYapellido);
    }

}
//FUNCION ADICIONAL PARA PUNTO 12
int cargarArrAlumnos(stAlumno arr[],int dimension)
{
    int i=0;
    char condi ='s';

    while(condi=='s' && i<dimension)
    {
        printf("Quiere ingresar un alumno al arreglo?  s/n\n");
        fflush(stdin);
        scanf("%c",&condi);

        if(condi =='s'){
            printf("Ingrese numero de legajo del alumno\n");
            fflush(stdin);
            scanf("%i",&arr[i].legajo);

            printf("Ingrese nombre del Alumno\n");
            fflush(stdin);
            gets(arr[i].nombreYapellido);

            printf("Ingrese edad del Alumno\n");
            fflush(stdin);
            scanf("%i",&arr[i].edad);

            printf("Ingrese anio de cursada del Alumno\n");
            fflush(stdin);
            scanf("%i",&arr[i].anio);
        i++;
        }
    }
    return i;
}
void mostrarAlumno(stAlumno A)
{
    printf("Legajo: %i\n",A.legajo);
    printf("Nombre: %s\n",A.nombreYapellido);
    printf("Edad: %i\n",A.edad);
    printf("Anio: %i\n",A.anio);
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


//17
int main()
{
int op;
char c='s';

while(c=='s')
{
    printf("Los archivos en la base de datos son: prueba\n");
    printf("1 agregarFinalINT\n");
    printf("2 mostrarArchivoINT\n");
    printf("3 cantidadRegistrosINT\n");
    printf("4 cargarAlumno\n");
    printf("5 mostrarArchivoAlumnos\n");
    printf("6 agregarAlumnoAlFinal\n");
    printf("7 pasarPilaLegajo\n");
    printf("8 cantidadXEdad\n");
    printf("9 guardaNombreAlumno\n");
    printf("10 mostrarAlumnoMayor\n");
    printf("11 cantidadXAnio\n");
    printf("12 deArchivoAArry ");
    printf("   deArryAlArchivo\n");
    printf("13 cantidadAlumnos\n");
    printf("14 mostrarSegunParametro\n");
    printf("15 modificarAlumno\n");
    printf("16 invertirArchivo\n");

    printf("\nIngrese que funcion desea ejecutar\n");
    scanf("%i",&op);

    switch(op)
    {
        case 1:
            {
                int elemento;
                char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese elemento a insertar\n");
                fflush(stdin);
                scanf("%i",&elemento);

                agregarFinalINT(nombre,elemento);
            }break;
        case 2:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo a mostrar\n");
                fflush(stdin);
                gets(nombre);

                mostrarArchivoINT(nombre);
            }break;
        case 3:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo \n");
                fflush(stdin);
                gets(nombre);

                int cantidad;

                cantidad=cantidadRegistrosINT(nombre);

                printf("La cantidad de registros del archivo es: %i\n",cantidad);
            }break;
        case 4:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo \n");
                fflush(stdin);
                gets(nombre);

                cargaAlumno(nombre);
            }break;
        case 5:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo para mostrar \n");
                fflush(stdin);
                gets(nombre);

                mostrarArchivoAlumnos(nombre);
            }break;
        case 6:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo a agregar elementos\n");
                fflush(stdin);
                gets(nombre);

                agregarAluFinal(nombre);
            }break;
        case 7:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo para pasar a Pila\n");
                fflush(stdin);
                gets(nombre);

                Pila destino;
                inicpila(&destino);

                pasarPilaEdad(nombre,&destino);
            }break;
        case 8:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo a contar\n");
                fflush(stdin);
                gets(nombre);

                int edad=0;
                int contador=0;

                printf("Ingrese edad minima para contar\n");
                scanf("%i",&edad);

                contador=cuentaAluEdad(nombre,edad);

                printf("La cantidad de alumnos mayores a %i es de : %i\n",edad,contador);
            }break;
        case 9:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo a mostrar\n");
                fflush(stdin);
                gets(nombre);

                int mayor;
                int menor;

                printf("Ingrese edad minima para imprimir\n");
                fflush(stdin);
                scanf("%i",&menor);
                printf("Ingrese edad maxima para imprimir\n");
                scanf("%i",&mayor);

                mostrarNombresXEdad(nombre,menor,mayor);
            }break;
        case 10:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);

                mostrarMayor(nombre);
            }break;
        case 11:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);

                int anio;
                printf("Ingrese anio para contar alumnos\n");
                scanf("%i",&anio);

                int cantidad=0;
                cantidad=cantidadXAnio(nombre,anio);

                printf("La cantidad de alumnos en %i es de : %i\n",anio,cantidad);
            }break;
        case 12:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);
                char c='s';

                printf("Quiere ejecutar del Arry al Archivo? s/n\n");
                fflush(stdin);
                scanf("%c",&c);
                if(c=='s'){
                    printf("Del arreglo al archivo! (primero cargar arry)\n");

                    stAlumno arry[30];
                    int validos=cargarArrAlumnos(arry,30);

                    mostrarArrAlumnos(arry,validos);

                    deArrAlArchivo(nombre,arry,validos);

                    mostrarArchivoAlumnos(nombre);
                }
                printf("Quiere ejecutar del Archivo al Arry? s/n\n");
                fflush(stdin);
                scanf("%c",&c);

                if(c=='s')
                {

                    stAlumno arryDestino[30];
                    int validosDestino = deArchivoAArry(nombre,arryDestino,30);

                    mostrarArrAlumnos(arryDestino,validosDestino);
                }
            }break;
        case 13:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);

                int cantidad;

                cantidad = cantidadRegistro(nombre);

                printf("La cantidad de registros es %i:\n",cantidad);
            }break;
        case 14:
            {
               char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);

                int registro;

                printf("Ingrese registro a mostrar\n");
                scanf("%i",&registro);

                mostrarSegunParametro(nombre,registro);
            }break;
        case 15:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);

                 modificarRegistro(nombre);
            }break;
        case 16:
            {
                char nombre[30];
                printf("Ingrese nombre del archivo\n");
                fflush(stdin);
                gets(nombre);

                invertirArchivo(nombre);

                mostrarArchivoAlumnos(nombre);
            }break;
        default:
            {
                printf("default");
            }
    }

    printf("Desea ejecutar otra funcion? s/n\n");
    fflush(stdin);
    scanf("%c",&c);
}
return 0;
}


//PRUEBAS DE FUNCIONAMIENTO EN EL PROCESO DE CREACION
    /*agregarFinal("Archivo",1);
    mostrarArchivo("Archivo");

    int contador=0;

    contador=cantidadRegistros("Archivo");

    printf("\n La cantidad es: %i\n",contador);




    cargaAlumno("prueba");

    mostrarArchivoAlumnos("prueba");

    //pasarPilaEdad("prueba");

    int aluMayores=0;

    aluMayores=cuentaAluEdad("prueba",18);

    printf("Alumnos mayores a 18: %i\n",aluMayores);

    int mayor=0,menor=0;
    printf("Ingrese edad minima para imprimir\n");
    fflush(stdin);
    scanf("%i",&menor);
    printf("Ingrese edad maxima para imprimir\n");
    scanf("%i",&mayor);

    mostrarNombresXEdad("prueba",menor,mayor);

    mostrarMayor("prueba");

    int cantidadX=0;

    cantidadX=cantidadXAnio("prueba",2022);

    printf("\nCantidad en el anio 2022 es: %i\n",cantidadX);

    stAlumno arry[30]={};
    arry[0].anio=2010;
    arry[0].edad=21;
    arry[0].legajo=315;
    strcpy(arry[0].nombreYapellido,"Martin Lachner");
    int valiArry=1;

    //deArrAlArchivo("prueba",arry,valiArry);

    //mostrarArchivoAlumnos("prueba");
    int can=0;
    can=cantidadRegistro("prueba");

    printf("\n cantidad de registros = %i\n",can);

    int parametro;
    printf("Ingrese numero de registro a buscar 0/9 \n");
    fflush(stdin);
    scanf("%i",&parametro);

    mostrarSegunParametro("prueba",parametro);

    modificarRegistro("prueba");

    invertirArchivo("prueba");

    mostrarArchivoAlumnos("prueba");


    return 0;
}

    */
