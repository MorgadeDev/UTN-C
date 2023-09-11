#include <stdio.h>
#include <stdlib.h>

//1
int cargarArry(int legajos[],char nombres[][30],int anios[],int dimension)
{
    int i=0;
    int legajo=0,anio=0;
    char control='s';

    for(i;i<dimension && control=='s';i++)
    {
        printf("Ingrese numero de legajo\n");
        scanf("%i",&legajo);
        legajos[i]=legajo;

        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese anios\n");
        scanf("%i",&anio);
        anios[i]=anio;

        printf("Desea seguir ingresando datos? s/n\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}
//2
int buscarLegajo(int legajos[],int buscado,int validos)
{
    int i=0;
    int posi=0;

    for(i;i<validos;i++)
    {
        if(buscado==legajos[i])
        {
            posi=i;
            return posi;
        }

    }
    return -1;
}
//3
void imprimir(int legajos[],char nombres[][30],int anios[],int validos,int buscado)
{
    int i=0;
    int esta=0;

    esta=buscarLegajo(legajos,buscado,validos);

    if(esta>=0)
    {
        printf("El nombre es %s\n",nombres[esta]);
        printf("Los anios son %i\n",anios[esta]);
        printf("El legajo es %i\n",legajos[esta]);
    }
    else{
        printf("El legajo buscado no se encuentra en el arreglo\n");
    }

}
//4
int posicionMenor(char nombres[][30],int pos,int validos)
{
    char menor[10]={};
    strcpy(menor,nombres[pos]);
    int posmenor = pos;
    int i=pos+1;
    while(i<validos)
    {
        if(strcmp(menor,nombres[i])==1)
        {
            strcpy(menor,nombres[i]);
            posmenor=i;
        }
        i++;
    }
    return posmenor;
}
void ordenacionSeleccion(int legajos[],char nombres[][30],int anios[],int validos)
{
    int posmenor;
    char aux[10]={};
    int legAux=0;
    int aniosAux=0;
    int i=0;

    while(i<validos-1)
    {
        posmenor = posicionMenor(nombres,i,validos);

        strcpy(aux,nombres[posmenor]);
        strcpy(nombres[posmenor],nombres[i]);
        strcpy(nombres[i],aux);

        legAux=legajos[posmenor];
        legajos[posmenor]=legajos[i];
        legajos[i]=legAux;

        aniosAux=anios[posmenor];
        anios[posmenor]=anios[i];
        anios[i]=aniosAux;

        i++;
    }

}
//5
void mostrarDatos(int legajos[],char nombres[][30],int anios[],int validos)
{
    int i=0;
    for(i;i<validos;i++)
    {
        printf("\n-----------------------\n");
        printf("Legajo: %i\n",legajos[i]);
        printf("Nombre: %s\n",nombres[i]);
        printf("Anios: %i \n",anios[i]);
        printf("-----------------------\n");
    }
}
int main()
{
    int legajos[10]={};
    char nombres[10][30]={};
    int anios[10]={};

    int validos;
    int esta;

    validos = cargarArry(legajos,nombres,anios,10);

    /*esta=buscarLegajo(legajos,5,validos);

    if(esta>=0)
    {
        printf("El legajo se encuentra en la posicion %i del arreglo\n",esta);
    }else{
        printf("El legajo no se encuentra en el arreglo\n");
    }


    imprimir(legajos,nombres,anios,validos,5);
    */

    ordenacionSeleccion(legajos,nombres,anios,validos);

    mostrarDatos(legajos,nombres,anios,validos);


    return 0;
}
