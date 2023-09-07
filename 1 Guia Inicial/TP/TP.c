int main()
{
    int op;
    int c=1;
    while(c==1){
    printf("Secciones del TP\n\n");
    printf("\nProblemas Secuenciales = s \n");
    printf("\nProblemas Condicionales Selectivos Simples = 2\n");
    printf("\nProblemas Condicionales Selectivos Compuestos (si anidados o en cascada) = 3 \n");
    printf("\nProblemas con repeticiones = 4 \n\n");

    printf("Quiere ingresar un ejercicio? Ingrese 1 para Si o 0 para No\n");
    scanf("%i",&c);
    if(c==1){

    printf("\nIngrese seccion del TP \n\n");
    scanf("%i",&op);

    switch (op)
    {
        case 1:{
            printf("\nProblemas Secuenciales \n\n");

            int aa;
            printf("Ingrese numero de ejercicio \n\n");
            scanf("%i", &aa);

           switch (aa){
            case 1:{
            /*Suponga que un individuo desea invertir su capital en un banco
            y desea saber cuánto dinero ganará después de un mes si el banco
            paga a razón de 2% mensual.
            */
            float ingreso;
            printf("Ingrese monto a invertir\n");
            scanf("%f",&ingreso);
            printf("El retorno de un inversion a 1 mes es de %f\n\n",(ingreso*1.02));

            }//Fin  ejercicio 1
            break;

            case 2:{
            /* Ejercicio 2 Problemas Secuenciales
            Una tienda ofrece un descuento del 15% sobre el total de la compra
            y un cliente desea saber cuánto deberá pagar finalmente por su compra.
            */
            float ingreso;
            printf("Ingrese precio del producto\n");
            scanf("%f",&ingreso);
            printf("El precio final con descuento aplicado es %f\n\n",(ingreso*0.85));

            }//Fin ejercicio 2
            break;

            case 3:{
            /*Un maestro desea saber qué porcentaje de hombres y que porcentaje de mujeres hay
            en un grupo de estudiantes
            */
            float alumnas,alumnos,pAlumnos,aTotales,pAlumnas;

            printf("Ingrese cantidad de alumnas\n");
            scanf("%f",&alumnas);

            printf("Ingrese cantidad de alumnos\n");
            scanf("%f",&alumnos);

            aTotales=alumnos+alumnas;
            pAlumnos= (100*alumnos)/(aTotales);
            pAlumnas= (100*alumnas)/(aTotales);

            printf("El porcentaje de alumnos es %f\n",(pAlumnos));
            printf("El porcentaje de alumnas es %f\n\n",(pAlumnas));
            }break;

            default:
                printf("Caso por defecto");

            }//Fin  ejercicio 3

        }break;//Fin Switch general case 1


        case 2:{
            printf("\nProblemas Condicionales Selectivos Simples \n\n");

            int ab;
            printf("Ingrese numero de ejercicio \n\n");
            scanf("%i", &ab);
           switch (ab){

            case 1:{
                /*Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si su
                promedio de tres calificaciones es mayor o igual a 7; reprueba en caso contrario.*/

                int nota=0, contador=1,acumulador=0,promedio=0;

                while(contador<4)
                {
                printf("Ingresar Nota %d\n",contador);
                scanf("%d",&nota);

                acumulador = acumulador +nota;
                contador++;
                }
                promedio= acumulador/3;
                printf("El promedio de notas es %d\n",promedio);
                if(promedio>=7){
                    printf("El alumno aprobo la materia\n");
                  }else{
                    printf("El alumno reprueba la materia\n");

                  }//Fin  ejercicio 1

            }break;
            case 2:{
                /*En un almacén se hace un 20% de descuento a los clientes cuya compra supere los
                $5000 ¿Cuál será la cantidad que pagara una persona por su compra?*/

                float montoCompra=0;
                printf("Ingrese monto final de la compra\n");
                scanf("%f",&montoCompra);

                if(montoCompra>5000)
                {
                 printf("El precio final con descuento aplicado es %f\n\n",montoCompra*0.8);
                }
                 else{
                    printf("El precio final es de %f\n\n",montoCompra);

                 }//Fin  ejercicio 2

            }break;

            case 3:{
                /*Un obrero necesita calcular su salario semanal, el cual se obtiene
                de la sig. manera: Si trabaja 40 horas o menos se le paga $300
                por hora Si trabaja más de 40 horas se le paga $300 por cada una de las primeras
                40 horas y $400 por cada hora extra.
                */
                int horasTrabajadas=0;

                printf("Ingrese cantidad de horas trabajadas\n");
                scanf("%d",&horasTrabajadas);

                if(horasTrabajadas<=40){
                  printf("El sueldo sera %d\n\n",horasTrabajadas*300);
                }
                else{
                    printf("El sueldo sera %d\n\n",12000+((horasTrabajadas-40)*400));

                }//Fin ejercicio 3

            }break;

            case 4: {
               /*Desarrolle un algoritmo que lea dos números y los imprima
                en forma ascendente*/

                float numero1,numero2;

                printf("Ingresar primer numero\n");
                scanf("%f",&numero1);

                printf("Ingrese segundo numero\n");
                scanf("%f",&numero2);

                if(numero1>numero2){
                    printf("Los numeros en forma ascendente son %f",numero2);
                    printf(" y %f\n\n",numero1);
                }
                else if(numero2>numero1){
                    printf("Los numeros en forma ascendente son %f",numero1);
                printf(" y %f\n\n",numero2);
                }
                else{
                    printf("Los numeros son iguales %f", numero1);
                printf(" y %f\n\n",numero2);
                }
            }//Fin ejercicio 4
            break;

            case 5:{
                /*Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
                 Si se compran tres camisas o más se aplica un descuento del 20% sobre el
                 total de la compra y si son menos de tres camisas un descuento del 10%*/
                 float cantidadDeCamisas=0,precioCamisas=800;

                printf("Ingrese cantidad de camisas a comprar\n");
                scanf("%f",&cantidadDeCamisas);

                if(cantidadDeCamisas>=3){
                    printf("El precio final de las camisas con descuento aplicado %f\n\n",(cantidadDeCamisas*precioCamisas*0.8));
                    }
                else{
                    printf("El precio final de las camisas es %f\n\n",(cantidadDeCamisas*precioCamisas*0.9));
                }

            }break;//Fin ejercicio 5
            default:
                printf("Caso por defecto");
           }
        } break;//Fin Switch general case 2
        case 3:{
            printf("\nProblemas Condicionales Selectivos Compuestos (si anidados o en cascada)\n\n");

            int ac;
            printf("Ingrese numero de ejercicio \n\n");
            scanf("%i", &ac);
           switch (ac){

               case 1:{
                   /*Leer 2 números; si son iguales que los multiplique,
                     si el primero es mayor que el segundo que los reste y si no que los sume.*/

                     float primerNumero, segundoNumero;

                    printf("Ingrese el primer numero\n");
                    scanf("%f",&primerNumero);

                    printf("Ingrese el segundo numero\n");
                    scanf("%f",&segundoNumero);

                    if(primerNumero==segundoNumero){
                        printf("El resultado de los numeros multiplicados es %f\n\n",primerNumero*segundoNumero);
                    }
                    else if(primerNumero>segundoNumero){
                         printf("El resultado de la diferencia entre los numeros %f\n\n",primerNumero-segundoNumero);
                    }
                    else{
                        printf("El resultado de la suma entre los numeros %f\n\n",primerNumero+segundoNumero);
                    }
               }//Fin ejercicio 1
               break;


               case 2:{
                   //Leer tres números diferentes e imprimir el número mayor de los tres
                   float primerNumero,segundoNumero,tercerNumero;

                    printf("Ingresar primer numero\n");
                    scanf("%f",&primerNumero);

                    printf("Ingresar segundo numero\n");
                    scanf("%f",&segundoNumero);

                    if(segundoNumero==primerNumero){
                        printf("Los numeros no pueden ser iguales\n");
                        printf("Ingresar segundo numero\n");
                        scanf("%f",&segundoNumero);
                    }
                    printf("Ingrese tercerNumero\n");
                    scanf("%f",&tercerNumero);

                    if(tercerNumero==segundoNumero){
                        printf("Los numeros no pueden ser iguales\n");
                        printf("Ingresar tercer numero\n");
                        scanf("%f",&tercerNumero);
                    }
                    if (primerNumero>segundoNumero && primerNumero>tercerNumero){
                        printf("El mayor de los numeros es %f\n\n",primerNumero);
                    }
                    else if(segundoNumero>primerNumero && segundoNumero>tercerNumero){
                        printf("El mayor de los numeros es %f\n\n",segundoNumero);
                    }
                     else {
                    printf("El mayor de los numeros es %f\n\n", tercerNumero);
                    }
               }break;//Fin ejercicio 2

               default:
                printf("Caso por defecto");
           }//Fin Switch general case 3
        }break;

               case 4:{
                printf("\nProblemas con repeticiones \n\n");

                int ad;
                    printf("Ingrese numero de ejercicio \n\n");
                    scanf("%i", &ad);
                   switch (ad){

                       case 1:{
                           //Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Programación 1

                           int i=1,nota;
                          float acumulador=0;
                        for(i=1; i<8; i++){

                           printf("Ingrese nota %i\n",i);
                           scanf("%i",&nota);

                           acumulador= acumulador + nota;
                        }
                        printf("El promedio de notas de programacion 1 es %f\n\n",acumulador/7);

                       }//Fin ejercicio 1
                       break;

                       case 2:{
                           // Leer 10 números y obtener su cubo y su cuarta
                           int i=1;

                          for(i=1; i<=10;i++){
                            int numero;

                            printf("Ingresar numero %i\n",i);
                            scanf("%i",&numero);

                            printf("El cubo del numero y su cuarta respectivamente es %i",numero*numero*numero);
                            printf( " y %i\n\n",numero*numero*numero*numero);
                          }
                       }//Fin ejercicio 2
                       break;

                       case 3:{
                           //Leer 10 números e imprimir solamente los números positivos

                           int i=1;

                            for(i=1;i<=10;i++){

                               int numero;

                               printf("Ingresar numero \n");
                               scanf("%i",&numero);
                            if(numero>0){
                                printf("El numero es %i",numero);
                                printf(" siendo positivo \n");
                            }
                            else{ printf("El numero no es positivo \n\n");}
                            }
                       }//Fin ejercicio 3
                       break;

                       case 4:{
                           //Leer 15 números negativos y convertirlos en positivos e imprimir dichos números

                           int i=1;

                             for(i=1;i<=15;i++){

                                int numeroNegativo;

                                printf("Ingresar un numero negativo \n");
                                scanf("%i",&numeroNegativo);

                                printf("El numero es %i\n\n",-1*numeroNegativo);
                             }
                       }//Fin ejercicio 4
                       break;

                       case 5:{
                           /*Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
                            Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.*/
                            int i=1,notaBaja=0,notaAlumno;
                             float promedio=0;

                             for(i=1;i<=40;i++){

                                printf("Ingrese nota alumno %i\n",i);
                                scanf("%i",&notaAlumno);

                                promedio = promedio + notaAlumno;
                                if(i==1){
                                    notaBaja=notaAlumno;
                                }
                                else if(notaAlumno<notaBaja){
                                notaBaja=notaAlumno;
                                }

                             }
                                printf("El promedio de nota de los 40 alumnos es de %f",promedio/40);
                                printf(" y la nota mas baja es %i\n\n",notaBaja);
                       }//Fin ejercicio 5
                       break;

                       case 6:{
                           /*Calcular e imprimir la tabla de multiplicar de un número cualquiera.
                            Imprimir el multiplicando, el multiplicador y el producto.*/

                            int i=1,numero;

                            printf("Ingrese numero para fabricar su tabla \n\n");
                                scanf("%i",&numero);

                            for(i=1;i<=10;i++){
                                printf("%i",numero);
                                printf(" x %i",i);
                                printf(" = %i\n",numero*i);
                            }
                       }break;//Fin ejercicio 6

                       default:
                   printf("Caso por defecto");

                   }
                }break;//Fin Switch general case 4

            default:
            printf("Caso por defecto");
        }//Fin Switch General
    }//Fin IF
    else{
        printf("\n\nEs todo por hoy!\n\n");
    }

}//Fin bucle while

return 0;
}//Fin Main


