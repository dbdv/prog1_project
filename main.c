#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ingresantes.h"
#include "listas.h"

/*
a->160
e->130
i->161
o->162
u->163
*/

void cargar_usuarios(list_ingresante *lista)
{
    long dni;
    int aux1;
    char aux[15];
    ingresante pepe;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(aux);
    carga_nom(&pepe,aux);

    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(aux);
    carga_ape(&pepe,aux);

    printf("Ingrese su cel: ");
    fflush(stdin);
    gets(aux);
    /*AGREGAR CONTROL*/
    carga_cel(&pepe,aux);

    printf("Ingese su dni: ");
    do
    {
        scanf("%ld", &dni);
        if(dni < 10000000 || dni > 99999999)
            printf("El DNI que quiere ingresar es incorrecto.\n");
    }while(dni < 10000000 || dni > 99999999);
    carga_dni(&pepe, dni);

}

void anotar_carreras(char *carreras[], ingresante *ingre)
{
    int option, id, i;

    printf("\tINSCRIPCION A CARRERAS.\n");
    printf("1.Carreras de pregrado\t2.Carreras de grado.\t0.Salir del programa.\n");
    do
    {
        scanf("%i", &option);
        if(option <0 || option >2)
            printf("No seleccion%c una opci%cn v%clida. Intente nuevamente.\n",162,162,160);
    }while(option < 0 || option >2);
    if(option == 1)
        {
            for(i=0; i<=10; i++)
                printf("%s", carreras[i]);
        }
    else
    {
        for(i=11; i<=25; i++)
            printf("%s",carreras[i]);
    }

    printf("Escriba el ID de la materia a la que se quiere inscribir: ");
    do
    {
        scanf("%i", &id);
        if(id<0 || id > 23)
            printf("No es un ID v%clido. Intente nuevamente.\n",162);
        else if(id == 10)
            printf("Esta carrera no est%c disponible en a%cos impares.\nIntente nuevamente.\nID:",162,164);
    }while(id<0 || id > 23 || id == 10);

    // AGREGAR ID carga_carrera(ingre,id);
    printf("%s",carreras[ingre->ID_carr[0]]);

    //SOLUCIONAR OPERACION CARGAR CARRERA EN LISTA.H
}

void verIngresante(list_ingresante lista, char* carreras[])
{
    long aux;
    int controlaux = 1, i, aux1;
    ingresante ingre;

    do
    {
        printf("Ingrese el DNI del ingresante que quiere consultar: ");
        scanf("%ld", aux);
        if(aux < 10000000 || aux > 99999999)
            printf("El DNI que intenta buscar tiene errores. Intente nuevamente.\n");
    }while(aux < 10000000 || aux > 99999999);

    while(!isOos(lista) && controlaux)
    {
        ingre = copyy(lista);
        if(aux == mostrar_dni(ingre))
        {
            printf("Nombre: %s\n", mostrar_nom(ingre));
            printf("Apellido: %s\n", mostrar_ape(ingre));
            printf("DNI: %ld\n", mostrar_dni(ingre));
            printf("Celular: %s\n", mostrar_cel(ingre));
            printf("Estado : %s\n", mostrar_estado(ingre));
            printf("Condicion de ingreso: %s\n", mostrar_estadoIngreso(ingre));
            printf("Carrera/s:\n");
            for(i = 0; i < 3; i++)
            {
                aux1 = *(mostrar_idCarreras(ingre)+i);
                if( aux1 > 0 || aux1 < 24)
                    printf("\t%s.\n", carreras[aux1]);
            }
            controlaux = 0;
        }
    }

    if(isOos(lista) && controlaux == 1)
        printf("El usuario que intenta ver no se encuentra en el listado.\n");
}

void ingresantesDe(char *carreras[])
{
    int i, aux;
    for(i=0; i <= 24; i++ )
        printf("%s", carreras[i]);
    do
    {
        printf("Ingrese el ID de la carrera de la cual quiere ver el listado de ingresantes: ");
        scanf("%i",&aux);
        if(aux <0 || aux > 22)
            printf("Debe ingresar un ID valido.\n");
    }while(aux <0 || aux > 22);

    //TERMINAR
}

void verCargados(list_ingresante lista)
{

}

void inscribirOtra(list_ingresante *lista)
{

}

void darBaja(list_ingresante *lista)
{

}

void aspirantesDe(list_ingresante lista)
{

}

void aprobaron(list_ingresante lista)
{

}

void guardarTFA(list_ingresante lista)
{

}


int main()
{
    int option, i, j=0, aux1;
    long auxl;
    char *carreras[25], aux[20];
    list_ingresante lista;
    ingresante cargados[20];
    FILE *arch_carreras = fopen("carreras.txt", "r");
    FILE *arch_ingresantes = fopen("ingresantes.txt", "r");

    for(i=0; i<25; i++)
        carreras[i] = (char *) malloc(sizeof(char)*50);

    for(i=0; i <= 24; i++)
        fgets(carreras[i],1000,arch_carreras);

    for(i=0; i < 20; i++)
    {
        init(&cargados[i]);
        for(j=0; j<4; j++){
            fgets(aux, 20, arch_ingresantes);
            switch(j)
                {
                case 0:
                    carga_nom(&cargados[i],aux);
                    break;
                case 1:
                    carga_ape(&cargados[i],aux);
                    break;
                case  2:
                    carga_cel(&cargados[i],aux);
                    break;
                case 3:
                    carga_dni(&cargados[i],aux1);
                    break;
                }
        }
        /*strcpy(aux, mostrar_nom(cargados[i]));
        printf("%s", aux);Para probar que la carga funciona*/
    }
    /*{
        init(&cargados[i]);
        for(j=0;j<=3;j++)
        {
                switch(j)
                {
                case 0:
                    fread(aux,sizeof(char)*20, 1,arch_ingresantes);
                    carga_nom(&cargados[i],aux);
                    break;
                case 1:
                    fread(aux, sizeof(char)*20, 1,arch_ingresantes);
                    carga_ape(&cargados[i],aux);
                    break;
                case  2:
                    fread(aux, sizeof(char)*20, 1, arch_ingresantes);
                    carga_cel(&cargados[i],aux);
                    break;
                case 3:
                    fread(&aux1, sizeof(long int), 1, arch_ingresantes);
                    carga_dni(&cargados[i],aux1);
                    break;
                }
        }
        strcpy(aux, mostrar_nom(cargados[i]));
        printf("%s", aux);
    }*/


    printf("\t\tPRACTICO DE MAQUINA INTEGRADOR\n");
    printf("\t\tSISTEMA UNSL\n");
    printf("\tCarrera: Ingenier%ca en inform%ctica\n\tIntegrantes: Diaz Emiliano-Bustillos Daniel\n\n", 161,160);

    do
    {
        printf("\tMENU DE OPCIONES DE OPERACIONES\n");
        printf("1.Cargar una cantidad n de usuarios.\t2.Mostar los datos de un ingresante.\t3.Ver todos los ingresantes de una materia.\n");
        printf("4.Ver todos los ingresantes cargados.\t5.Modificar el campo ingreso de un usuario.\t6.Inscribir a otra carrera.\n");
        printf("7.Anular la inscripcion a carrera.\t8.Ver la cantidad de ingresantes de x carrera en la condicion aspirante.\n");
        printf("9.Ver los ingresantes que aprobaron el ingreso.\t10.Guardar los datos de los ingresantes que pasaron al TFA.\t0.Salir\n");
        printf("Operacion a realizar: ");
        scanf("%i", &option);
        if(option < 0 || option > 10)
            printf("Debe elegir una operacion de las que se muestran por pantalla. Intente nuevamente.\n");

    switch(option)
    {
    case 1:
        if(isFull(lista))
            printf("La lista se encuentra llena, no puede cargar mas usuarios.\n");
        else
            cargar_usuarios(&lista);
        break;
    case 2:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            verIngresante(lista, carreras);
        break;
    case 3:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            ingresantesDe(carreras);
        break;
    case 4:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            verCargados(lista);
        break;
    case 5:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            verCargados(lista);
        break;
    case 6:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            inscribirOtra(&lista);
        break;
    case 7:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            darBaja(&lista);
        break;
    case 8:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            aspirantesDe(lista);
        break;
    case 9:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            aprobaron(lista);
        break;
    case 10:
        if(isEmpy(lista))
            printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
        else
            guardarTFA(lista);
        break;
    case 0:
        printf("Hasta luego!\n");
    }
    }while(option != 0);

    fclose(arch_carreras);
    fclose(arch_ingresantes);

    return 0;
}
