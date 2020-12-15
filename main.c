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

/*A*/void cargar_usuarios(list_ingresante *lista, char *carreras[]);

/*extra*/void anotar_carrera(char *carreras[], ingresante *ingre);

/*B*/int verIngresante(list_ingresante *lista);

/*C*/void mostrarBuscado(list_ingresante *lista, char* carreras[]);

/*D*/void ingresantesDe(char *carreras[], list_ingresante l);

/*E*/void verCargados(list_ingresante lista, char *carreras[]);

/*F*/void cambiarIngreso(list_ingresante *lista);

/*G*/void inscribirOtra(list_ingresante *lista, char *carreras[], ingresante ingre);

/*H*/void darBaja(list_ingresante *lista,long aux, char *carreras[]);

/*I*/void cant_aspirantesXcarrera(char *carreras[],list_ingresante lista);

/*J*/void mostrarAprobaronIngreso(list_ingresante lista,int id);

/*K*/void guardarTFA(list_ingresante lista, char *carreras[]);

/*L*/void precarga(list_ingresante *lista);

int main()
{
    int option, i, suboption, ad, n;
    long auxD;
    char *carreras[25];
    ingresante ingre;
    list_ingresante lista;
    FILE *arch_carreras = fopen("carreras.txt", "r");

    if(arch_carreras == NULL )
    {
        printf("Error con la precarga de archivos. El programa no puede iniciar.\n");
        exit(1);
    }

    initt(&lista);

    for(i=0; i<25; i++)
        carreras[i] = (char *) malloc(sizeof(char)*100);

    for(i=0; i < 25; i++)
        fscanf(arch_carreras, "%[^\n] s", carreras[i]);

    /*----------------------------------------------------------------------------------------------------*/


    printf("------------------------\tPRACTICO DE MAQUINA INTEGRADOR        ------------------------\n");
    printf("Proyecto: sist de gesti%cn de ingresantes 2021.\nCarrera: Ingenier%ca en inform%ctica\nIntegrantes: Diaz Emiliano-Bustillos Daniel\n\n", 162, 161,160);

 do
 {
        printf("Usted es..\n\t<1> Alumno.\n\t<2> Administrador.\t<0> Salir.\n");
        scanf("%i", &suboption);
        if(suboption < 0 || suboption > 2)
            printf("No ha elegido una opci%cn disponible.\n", 162);
    if(suboption == 2){
        do
        {
            printf("\t\t\t\t\tSISTEMA UNSL\n");
            printf("------------------------\tMENU DE OPCIONES DE OPERACIONES        ------------------------\n");
            printf("<1> Cargar una cantidad n de usuarios.\t\t<6> Ver la cantidad de ingresantes de x carrera en la condicion aspirante.\n");
            printf("<2> Mostar los datos de un ingresante.\t\t<7> Ver los ingresantes que aprobaron el ingreso.\n");
            printf("<3> Ver todos los ingresantes de una materia.\t<8> Realizar una precarga de ingresantes desde archivos.\n");
            printf("<4> Ver todos los ingresantes cargados.\t\t<9> Guardar los datos de los ingresantes que pasaron al TFA.\n");
            printf("<5> Modificar el campo ingreso de un usuario.\t<0> Volver atr%cs.\n", 160);
            printf("Operacion a realizar: ");
            scanf("%i", &option);
            if(option < 0 || option > 9)
                printf("Debe elegir una operacion de las que se muestran por pantalla. Intente nuevamente.\n");

        switch(option)
        {
        case 1:
            if(isFull(lista))
                printf("La lista se encuentra llena, no puede cargar mas usuarios.\n");
            else
            {
                printf("\nCantidad a cargar: ");
                scanf("%i", &n);
                for(i = 0; i < n; i++)
                {
                    if(isFull())
                        printf("Se ha llenado la lista, pudo cargar %i ingresantes.\n", i);
                    else
                    {
                        printf("\n");
                        cargar_usuarios(&lista, carreras);
                        forwardd(&lista);
                    }

                }
            }
            break;
        case 2:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else
            {
                printf("\n");
                mostrarBuscado(&lista, carreras);
            }
            break;
        case 3:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else
            {
                printf("\n");
                ingresantesDe(carreras, lista);
            }
            break;
        case 4:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else
            {
                printf("\n");
                verCargados(lista, carreras);
            }
            break;
        case 5:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else
            {
                printf("\n");
                cambiarIngreso(&lista);
            }
            break;
        case 6:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else
            {
                printf("\n");
                cant_aspirantesXcarrera(carreras, lista);
            }
            break;
        case 7:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else{
                for(i=0; i <= 24; i++ )
                    printf("%s.\n", carreras[i]);
                do
                {
                    printf("Ingrese el ID de la carrera de la cual quiere ver el listado de ingresantes que aprobaron el ingreso: ");
                    scanf("%i", &ad);
                    if(ad <1 || ad > 24 || ad == 11)
                        printf("Debe ingresar un ID valido.\n");
                    if( ad == 10)
                        printf("Esta carrera no recibe ingresantes en a%cos impar.\n", 164);
                }while(ad <1 || ad > 24 || ad == 10 || ad == 11);
                reset(&lista);
                printf("\n");
                mostrarAprobaronIngreso(lista, ad);
                }
            break;
        case 8:
            if(isFull())
                printf("La lista se encuentra llena.\n");
            else
            {
                precarga(&lista);
                printf("\nCarga completa.\n");
            }
            break;
        case 9:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else
            {
                guardarTFA(lista, carreras);
                printf("\nGuardado completo.\n");
            }
            break;
        case 0:
            printf("Hasta luego!\n\n");
            system("cls");
        }
        }while(option != 0);
    }
    if(suboption == 1)
    {
        do
        {
            printf("\t\t\t\t\tSISTEMA UNSL\n");
            printf("------------------------\tMENU DE OPCIONES DE OPERACIONES        ------------------------\n");
            printf("<1> Inscribirse a otra carrera.\t\t<2> Darse de baja en una carrera.\n");
            printf("<0> Volver atr%cs.\n", 160);
            printf("Operacion a realizar: ");
            scanf("%i", &option);
            if(option < 0 || option > 10)
                printf("Debe elegir una operacion de las que se muestran por pantalla. Intente nuevamente.\n");

        switch(option)
        {
        case 1:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else
            {
                do
                {
                    printf("Ingrese el DNI del ingresante: ");
                    scanf("%ld", &auxD);
                    if(auxD < 10000000 || auxD > 99999999)
                        printf("El DNI que intenta buscar tiene errores. Intente nuevamente.\n");
                }while(auxD < 10000000 || auxD > 99999999);

                reset(&lista);
                while(!isOos(lista))
                {
                    ingre = copyy(lista);
                    if(auxD == mostrar_dni(ingre))
                    {
                        if(mostrar_idCarreras(ingre, 0) == 0)
                            printf("Este ingresante no está inscripto en ninguna carrera.\n");
                        else
                            suppres(&lista);
                    }
                    else
                    {
                        forwardd(&lista);
                    }
                }

                inscribirOtra(&lista, carreras, ingre);
            }
            break;
        case 2:
            if(isEmpy(lista))
                printf("Aun no hay usuarios cargados por lo que no puede consultar informacion.\n");
            else{
                do{
                printf("Ingrese DNI de ingresante:");
                scanf("%ld",&auxD);
                }while(auxD<10000000 || auxD>99999999);
            darBaja(&lista,auxD, carreras);
            }
            break;
        case 0:
            printf("Hasta luego!\n\n");
        }
    }while(option != 0);

    }
    if(suboption == 0)
        printf("Ponganos un 10 profe ;)\n");
}while(suboption != 0);


    free((void*)carreras);
    fclose(arch_carreras);

    return 0;

}

/*A*/void cargar_usuarios(list_ingresante *lista, char *carreras[])
{
    long dni;
    int estado, papeles;
    char aux[15], tel[20];
    ingresante ingre;

    init(&ingre);
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(aux);
    carga_nom(&ingre,aux);


    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(aux);
    carga_ape(&ingre,aux);

    printf("Ingrese celular de contacto: ");
    fflush(stdin);
    gets(tel);
    carga_cel(&ingre,tel);

    do
    {
        printf("Ingese su dni: ");
        scanf("%ld", &dni);
        if(dni < 10000000 || dni > 99999999)
            printf("El DNI que quiere ingresar es incorrecto.\n");
    }while(dni < 10000000 || dni > 99999999);
    carga_dni(&ingre, dni);

    do
    {
        printf("Aprob%c el ingreso\n<1> Si\t<0> No\n", 162);
        scanf("%i", &estado);
        if(estado != 1 && estado !=0)
            printf("Debe elegir una de las opciones que se muestran.\n");
    }while(estado != 1 && estado !=0);

    if(estado == 1)
    {
        carga_ingreso(&ingre, 1);
        carga_estado(&ingre, 3);
    }
    else
    {
        carga_ingreso(&ingre,0);
        do
        {
            printf("<1> Papeles incompletos.\t<2> Papeles completos.\n");
            scanf("%i", &papeles);
            if(papeles < 1 || papeles > 2)
                printf("Debe elegir una de las opciones que se muestran.\n");
        }while(papeles < 1 || papeles > 2);
        if(papeles == 1)
            carga_estado(&ingre, 1);
        else
            carga_estado(&ingre, 2);
    }

    anotar_carrera(carreras, &ingre);

    insertt(lista, ingre);

    system("cls");
}

/*extra*/void anotar_carrera(char *carreras[], ingresante *ingre)
{
    int option, id, i, cant, j;

    printf("\tINSCRIPCION A CARRERAS.\n");
    do
    {
        printf("En cuantas carreras piensa inscribirse\n<1>\t<2>\t<3>\n");
        scanf("%i", &cant);
        if(cant < 0 || cant > 3)
            printf("Debe ingresar una de las cantidades que se muestran.\n");
    }while(cant < 0 || cant > 3);

    for(j=0; j < cant; j++){
        printf("1.Carreras de pregrado\t2.Carreras de grado.\n");
        do
        {
            scanf("%i", &option);
            if(option <0 || option >2)
                printf("No seleccion%c una opci%cn v%clida. Intente nuevamente.\n",162,162,160);
        }while(option < 0 || option >2);
        if(option == 1)
        {
            for(i=0; i<=10; i++)
                printf("%s.\n", carreras[i]);
            switch(j)
            {

            case 0:
                do
                {
                    printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
                    scanf("%i", &id);
                    if(id<1 || id > 10)
                        printf("No es un ID v%clido. Intente nuevamente.\n",162);
                    else if(id == 10)
                        printf("Esta carrera no est%c disponible en a%cos impares.\nIntente nuevamente.\nID:",162,164);
                }while(id < 0 || id > 9);
                break;
                case 1:
                do
                {
                    printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
                    scanf("%i", &id);
                    if(id<1 || id > 10)
                        printf("No es un ID v%clido. Intente nuevamente.\n",162);
                    else if(id == 10)
                        printf("Esta carrera no est%c disponible en a%cos impares.\nIntente nuevamente.\nID:",162,164);
                    else if(id == mostrar_idCarreras(*ingre, 0))
                        printf("Ya se ha inscripto en esa carrera.\n");
                }while(id < 0 || id > 9 || id == mostrar_idCarreras(*ingre, 0));
                break;
                case 2:
                do
                {
                    printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
                    scanf("%i", &id);
                    if(id<1 || id > 10)
                        printf("No es un ID v%clido. Intente nuevamente.\n",162);
                    else if(id == 10)
                        printf("Esta carrera no est%c disponible en a%cos impares.\nIntente nuevamente.\nID:",162,164);
                    else if(id == mostrar_idCarreras(*ingre, 0) || id == mostrar_idCarreras(*ingre, 0))
                        printf("Ya se ha inscripto en esa carrera.\n");
                }while(id < 0 || id > 9 || id == mostrar_idCarreras(*ingre, 0) || id == mostrar_idCarreras(*ingre, 1));
            }
        }
        else if(option == 2)
        {
            for(i=11; i<25; i++)
                printf("%s.\n",carreras[i]);
            switch(j)
            {
                case 0:
                do
                {
                    printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
                    scanf("%i", &id);
                    if(id<12 || id > 24 )
                        printf("No es un ID v%clido. Intente nuevamente.\n",162);
                }while(id<12 || id > 24);
            break;
                case 1:
                do
                {
                    printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
                    scanf("%i", &id);
                    if(id<12 || id > 24 )
                        printf("No es un ID v%clido. Intente nuevamente.\n",162);
                    else if(id == mostrar_idCarreras(*ingre, 0))
                        printf("Ya se ha inscripto en esa carrera.\n");
                }while(id<12 || id > 24 || id == mostrar_idCarreras(*ingre, 0));
                break;
                case 2:
                do
                {
                    printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
                    scanf("%i", &id);
                    if(id<12 || id > 24 )
                        printf("No es un ID v%clido. Intente nuevamente.\n",162);
                    else if(id == mostrar_idCarreras(*ingre, 0) || id == mostrar_idCarreras(*ingre, 1))
                        printf("Ya se ha inscripto en esa carrera.\n");
                }while(id<12 || id > 24 || id == mostrar_idCarreras(*ingre, 0) || id == mostrar_idCarreras(*ingre, 1));
            }
        }

        carga_carrera(ingre, id, j);
    }
}

/*B*/int verIngresante(list_ingresante *lista)
{
    int option, id;
    long aux;
    ingresante ingre;

    do
    {
        printf("\n<1> Buscar por DNI.\t<2> Buscar por ID.\n");
        scanf("%i", &option);
        if(option != 1 && option != 2)
            printf("Debe ingresar una de las opciones que se muestran.\n");
    }while(option != 1 && option != 2);

    if(option == 1)
    {
        do
        {
            printf("Ingrese el DNI del ingresante que quiere consultar: ");
            scanf("%ld", &aux);
            if(aux < 10000000 || aux > 99999999)
                printf("El DNI que intenta buscar tiene errores. Intente nuevamente.\n");
        }while(aux < 10000000 || aux > 99999999);

        reset(lista);
        while(!isOos(*lista))
        {
            ingre = copyy(*lista);
            if(aux == mostrar_dni(ingre))
            {
                return 1;
            }else
            {
                forwardd(lista);
            }
        }
    }
    else
    {
        do
        {
            printf("Ingrese el n%c de inscripci%cn del ingresante que quiere consultar: ", 167, 162);
            scanf("%i", &id);
            if(id < 0)
                printf("El n%c que intenta usaar contiene errores. Intente nuevamente.\n", 167);
        }while(id < 0);

        reset(lista);
        while(!isOos(*lista))
        {
            ingre = copyy(*lista);
            if(id == mostrar_n_inscrip(ingre))
            {
                return 1;
            }else
            {
                forwardd(lista);
            }
        }
    }

    return 0;
}

/*C*/void mostrarBuscado(list_ingresante *lista, char* carreras[])
{
    int  i, estado;
    ingresante ingre;

    if(verIngresante(lista))
    {
        ingre = copyy(*lista);
        printf("-------------------------\n");
        printf("Nombre: %s\n", mostrar_nom(ingre));
        printf("Apellido: %s\n", mostrar_ape(ingre));
        printf("DNI: %ld\n", mostrar_dni(ingre));
        printf("Celular: %s\n", mostrar_cel(ingre));
        printf("Estado: ");
        estado = mostrar_estado(ingre);
        switch(estado)
        {
        case 1:
        printf("preinscripto.\n");
        break;
        case 2:
        printf("aspirante.\n");
        break;
        case 3:
        printf("inscripto.\n");
        break;
        }
        printf("Condicion de ingreso: ");
            if(mostrar_estadoIngreso(ingre))
               printf("aprobado.\n");
            else
                printf("no aprobado.\n");
        printf("Carrera/s:\n");
        for(i = 0; i < 3; i++)
        {
            if(mostrar_idCarreras(ingre, i) != 0)
                printf("%s.\n",carreras[mostrar_idCarreras(ingre, i)]);
        }
    }
    else
        printf("El usuario que intenta ver no se encuentra en el listado.\n");

}

/*D*/void ingresantesDe(char *carreras[], list_ingresante l)
{
    int i, aux, contador = 0;
    for(i=0; i <= 24; i++ ){
        printf("%s\n", carreras[i]);
    }
    do
    {
        printf("\nIngrese el ID de la carrera de la cual quiere ver el listado de ingresantes: ");
        scanf("%i",&aux);
        if(aux <0 || aux > 22)
            printf("Debe ingresar un ID valido.\n");
    }while(aux <0 || aux > 22);

    reset(&l);
    while(!isOos(l))
    {
        for(i=0; i<3; i++)
        {
            if(mostrar_idCarreras(copyy(l), i) == aux && mostrar_estado(copyy(l)) == 3)
             {
                contador++;
             }
        }
        forwardd(&l);

    }
    if(contador != 0)
    {
        printf("Hay %i ingresantes en la carrera %s.\nLos ingresantes son:\n", contador, carreras[aux]);
        reset(&l);
        while(!isOos(l))
        {
            for(i=0; i<3; i++)
            {
                if(mostrar_idCarreras(copyy(l), i) == aux && mostrar_estado(copyy(l)) == 3)
                {
                    printf("Nombre: %s\n", mostrar_nom(copyy(l)));
                    printf("Apellido: %s\n", mostrar_ape(copyy(l)));
                    printf("DNI: %ld\n", mostrar_dni(copyy(l)));
                    printf("Celular: %s\n", mostrar_cel(copyy(l)));
                }
            }
            forwardd(&l);
        }
    }else
        printf("No hay ingresantes en esta carrera.\n");
}

/*E*/void verCargados(list_ingresante lista, char *carreras[])
{
    int i;
    reset(&lista);
    ingresante ingre;
    while(!isOos(lista))
    {
        ingre=copyy(lista);
        printf("-----------------------\n");
        printf("Nro de inscripci%cn: %i.\nNombre: %s.\nApellido: %s.\nDNI: %ld.\n", 162, mostrar_n_inscrip(ingre), mostrar_nom(ingre), mostrar_ape(ingre), mostrar_dni(ingre));
        printf("Celular: %s.\n",mostrar_cel(ingre));
        printf("Carrera/s:\n");
        for(i = 0; i < 3; i++)
        {
        if(mostrar_idCarreras(ingre, i)!=0){
         printf("%s\n",carreras[mostrar_idCarreras(ingre, i)]);
            }
        }
        forwardd(&lista);
    }
}

/*F*/void cambiarIngreso(list_ingresante *lista)
{
    ingresante ingre;
    long auxD;
    int aux, papeles;
    do
                {
                    printf("Ingrese el DNI del ingresante: ");
                    scanf("%ld", &auxD);
                    if(auxD < 10000000 || auxD > 99999999)
                    printf("El DNI que intenta buscar tiene errores. Intente nuevamente.\n");
                }while(auxD < 10000000 || auxD > 99999999);

                do
                {
                    printf("<1> Ingreso aprobado.\t<0> Ingreso desaprobado.\n");
                    scanf("%i", &aux);
                }while(aux != 1 && aux !=0);

                reset(lista);
                while(!isOos(*lista) && auxD != mostrar_dni(ingre))
                {
                    ingre = copyy(*lista);
                    if(auxD == mostrar_dni(ingre) && aux ==1)
                    {
                        suppres(lista);
                        mod_estIngreso(&ingre, aux);
                        mod_estado(&ingre, 3);
                    }
                    else if(auxD == mostrar_dni(ingre) && aux ==0)
                    {
                        suppres(lista);
                        mod_estIngreso(&ingre, aux);
                        do
                        {
                            printf("<1> Papeles completos.\t<2> Papeles incompletos.\n");
                            scanf("%i", &papeles);
                        }while(papeles != 1 && papeles != 2);

                        if(papeles == 1)
                            mod_estado(&ingre, 1);
                        if(papeles == 2)
                            mod_estado(&ingre, 2);
                    }
                    else
                    {
                        forwardd(lista);
                    }
                }
                insertt(lista, ingre);
}

/*G*/void inscribirOtra(list_ingresante *lista, char *carreras[], ingresante ingre)
{
    int option, id, i;

    if(mostrar_idCarreras(ingre, 1) != 0 && mostrar_idCarreras(ingre, 2) != 0)
        printf("\nYa se ha inscripto en 3 carreras.\n");
    else{

        printf("\tINSCRIPCION A CARRERAS.\n");
        printf("<1> Carreras de pregrado\t<2> Carreras de grado.\n");
        do
        {
            scanf("%i", &option);
            if(option <1 || option >2)
            {
                printf("No seleccion%c una opci%cn v%clida. Intente nuevamente.\n",162,162,160);
            }
        }while(option < 1 || option >2);

        if(option == 1)
        {
                for(i=0; i<=10; i++)
                    printf("%s.\n", carreras[i]);
                printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
            do
            {
                scanf("%i", &id);
                if(id<1 || id > 10)
                    printf("No es un ID v%clido. Intente nuevamente.\n",162);
                else if(id == 10)
                    printf("Esta carrera no est%c disponible en a%cos impares.\nIntente nuevamente.\nID:",162,164);
                else if(id == mostrar_idCarreras(ingre, 0) || id == mostrar_idCarreras(ingre, 1) || id == mostrar_idCarreras(ingre, 2))
                    printf("Ya se ha inscripto en esa carrera.\nIntente nuevamente.\nID:");
            }while(id<1 || id > 9 || id == mostrar_idCarreras(ingre, 0) || id == mostrar_idCarreras(ingre, 1) || id == mostrar_idCarreras(ingre, 2));
        }
        else if(option == 2)
        {
            for(i=11; i<=25; i++)
                printf("%s.\n",carreras[i]);
            printf("Escriba el ID de la carrera a la que se quiere inscribir: ");
            do
            {
                scanf("%i", &id);
                if(id < 12 || id > 24)
                    printf("No es un ID v%clido. Intente nuevamente.\n", 162);
                else if(id == mostrar_idCarreras(ingre, 0) || id == mostrar_idCarreras(ingre, 1) || id == mostrar_idCarreras(ingre, 2))
                    printf("Ya se ha inscripto en esa carrera.\nIntente nuevamente.\nID:");
            }while(id<12 || id > 24 || id == mostrar_idCarreras(ingre, 0) || id == mostrar_idCarreras(ingre, 1) || id == mostrar_idCarreras(ingre, 2));
        }

        insertt(lista, ingre);
    }

}

/*H*/void darBaja(list_ingresante *lista,long aux,char *carreras[])
{
    int i,aux1,op,a;
    ingresante ingre;
    reset(lista);

    while(!isOos(*lista) && aux != mostrar_dni(ingre))
    {

        ingre = copyy(*lista);
        if(aux == mostrar_dni(ingre))
        {
            printf("\nLas carreras en la que esta inscripto el ingresante con dni %ld:\n",aux);
               for(i = 0; i < 3; i++)
                {
                    aux1 = mostrar_idCarreras(ingre, i);
                    if( aux1 > 0 && aux1 < 24 )
                        printf("\t%s.\n", carreras[aux1]);
                }
        do
        {
            printf("Elija opcion:\n<1> Salir de una carrera\t<2> Salir de todas las carreras\n");
            scanf("%i", &op);
        }while(op != 1 && op != 2);


        if(op==2){
                    suppres(lista);
        }
        else
        {
            suppres(lista);
            printf("Ingrese ID de carrera\n");
            scanf("%d",&a);
            if(a == mostrar_idCarreras(ingre, 0))
            {
                mod_carr(&ingre, 0, mostrar_idCarreras(ingre, 1));
                mod_carr(&ingre, 1, mostrar_idCarreras(ingre, 2));
                mod_carr(&ingre,2,0);
            }
            else if(a == mostrar_idCarreras(ingre, 1))
            {
                mod_carr(&ingre, 1, mostrar_idCarreras(ingre, 2));
                mod_carr(&ingre, 2, 0);
            }
            else
                mod_carr(&ingre,2,0);
            insertt(lista, ingre);
        }
    }
    else
        forwardd(lista);
    }
}

/*I*/void cant_aspirantesXcarrera(char *carreras[],list_ingresante lista){
    ingresante ingre;
    int contador=0;
    int t,c,i;
        do{
            printf("\nIngrese tipo de carrera:\n");
            printf("<1> Carreras de pregrado\t<2> Carreras de grado\n");
            scanf("%d",&t);
        }while(t<1 || t>2);

        if(t == 1)
        {
            for(i=0; i<=10; i++)
                printf("%s.\n", carreras[i]);
            do
            {
                printf("\nIngrese ID de carrera:");
                scanf("%d",&c);
            }while(c<0 || c>10);

        }
        else if(t == 2)
        {
            for(i=11; i<=25; i++)
                printf("%s.\n",carreras[i]);
            do
            {
                printf("\nIngrese ID de carrera:");
                scanf("%d",&c);
            }while(c<11 || c>25);
    }
    reset(&lista);

    while(!isOos(lista))
    {
        ingre = copyy(lista);

        for(i=0; i<3; i++)
        {
    /*Ver si coinciden las carreras y si son aspirantes*/
    if(mostrar_idCarreras(ingre,i) == c && mostrar_estado(ingre) == 2){

            contador=contador+1;}
    }
    forwardd(&lista);
    }

    printf("\nSe hallaron %d aspirantes.\n",contador);
}

/*J*/void mostrarAprobaronIngreso(list_ingresante lista, int id)
{
    if(isOos(lista)){
        printf("Esos son todos.\n");
    }else{

        if( (mostrar_idCarreras(copyy(lista), 0) == id || mostrar_idCarreras(copyy(lista), 1)==id || mostrar_idCarreras(copyy(lista), 2)==id) && mostrar_estadoIngreso(copyy(lista))==1)
        {
            printf("Nombre: %s\n", mostrar_nom(copyy(lista)));
            printf("Apellido: %s\n", mostrar_ape(copyy(lista)));
            printf("DNI: %ld\n", mostrar_dni(copyy(lista)));
            printf("Celular: %s\n", mostrar_cel(copyy(lista)));
            printf("------------------------\n");
            forwardd(&lista);
            mostrarAprobaronIngreso(lista, id);
        }

        else
        {
            forwardd(&lista);
            mostrarAprobaronIngreso(lista, id);
        }
    }
}

/*K*/void guardarTFA(list_ingresante lista, char *carreras[])
{
    FILE *tfa = fopen("TFA.txt", "w+");
    ingresante aux;

    if(tfa == NULL)
        printf("Error de carga.\n");
    else{

    reset(&lista);
    rewind(tfa);
    while(!isOos(lista))
    {
        aux = copyy(lista);
        if(!mostrar_estadoIngreso(aux))
        {
            fprintf(tfa, "%s\n%s\n%ld\n%s\nCarrera-s", mostrar_nom(aux), mostrar_ape(aux), mostrar_dni(aux), mostrar_cel(aux));
            if(mostrar_idCarreras(aux, 0) > 0 &&  mostrar_idCarreras(aux, 0) < 23)
                fprintf(tfa, "\t%s\n", carreras[mostrar_idCarreras(aux, 0)]);
            if(mostrar_idCarreras(aux, 1) > 0 &&  mostrar_idCarreras(aux, 1) < 23)
                fprintf(tfa, "\t%s\n", carreras[mostrar_idCarreras(aux, 1)]);
            if(mostrar_idCarreras(aux, 2) > 0 &&  mostrar_idCarreras(aux, 2) < 23)
                fprintf(tfa, "\t%s\n", carreras[mostrar_idCarreras(aux, 2)]);
            forwardd(&lista);
        }
        else
            forwardd(&lista);
    }
    }
    fclose(tfa);
}

/*L*/void precarga(list_ingresante *lista)
{
     FILE *arch_ingresantes = fopen("ingresantes.txt", "r+");
    int estado, id, id1, id2, ingreso;
    long dni;
    char nom[20], ape[20], cel[20];
    ingresante ingre;

    if(arch_ingresantes == NULL)
        printf("Hubo un error con la carga del archivo.\n");
    else
    {
        while(feof(arch_ingresantes) == 0 && !isFull())
        {
            memset(nom, 0, 20);
            memset(ape, 0, 20);
            memset(cel, 0, 20);
            fflush(stdin);
            init(&ingre);

            fflush(stdin);
            fscanf(arch_ingresantes, "%[^\n] s", nom);
            fflush(stdin);
            fscanf(arch_ingresantes, "%[^\n] s", ape);
            fflush(stdin);
            fscanf(arch_ingresantes, "%ld", &dni);
            fflush(stdin);
            fscanf(arch_ingresantes, "%s", cel);
            fflush(stdin);
            fscanf(arch_ingresantes, "%i", &ingreso);
            fflush(stdin);
            fscanf(arch_ingresantes, "%i", &estado);
            fflush(stdin);
            fscanf(arch_ingresantes, "%i", &id);
             fflush(stdin);
            fscanf(arch_ingresantes, "%i", &id1);
            fflush(stdin);
            fscanf(arch_ingresantes, "%i", &id2);

            carga_nom(&ingre, nom);
            carga_ape(&ingre, ape);
            carga_dni(&ingre, dni);
            carga_cel(&ingre, cel);
            carga_ingreso(&ingre, ingreso);
            carga_estado(&ingre, estado);
            carga_carrera(&ingre, id, 0);
            carga_carrera(&ingre, id1, 1);
            carga_carrera(&ingre, id2, 2);

            insertt(lista, ingre);
            printf("%s\n", mostrar_nom(ingre));
           }
        }
        fclose(arch_ingresantes);
    }

