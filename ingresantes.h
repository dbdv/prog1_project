#ifndef INGRESANTES_H_INCLUDED
#define INGRESANTES_H_INCLUDED
#define N 20


typedef struct{
    long dni;
    int n_inscrip, estado, estIngreso;
    int ID_carr[3];
    char ape[N], nom[N], cel[N];
}ingresante;

/*INICIALIZADOR*/
void init(ingresante* ingre)
{
    int n;
    srand(time(NULL));
    n = rand();
    (*ingre).n_inscrip = n;
    (*ingre).ID_carr[0] = 0;
    (*ingre).ID_carr[1] = 0;
    (*ingre).ID_carr[2] = 0;
}

/*FUNCIONES CARGAR*/
void carga_dni(ingresante* ingre, long dni){
    (*ingre).dni = dni;
}

void carga_estado(ingresante* ingre, int est){
    (*ingre).estado = est;
}

void carga_ingreso(ingresante* ingre, int ing){
    ingre->estIngreso = ing;
}

void carga_carrera(ingresante* ingre, int id, int i){
    ingre->ID_carr[i] = id;
}

void carga_ape(ingresante* ingre, char ape[]){
    strcpy((*ingre).ape, ape);
}

void carga_nom(ingresante* ingre, char nom[]){
    strcpy((*ingre).nom, nom);
}

void carga_cel(ingresante* ingre, char cel[]){
    strcpy((*ingre).cel, cel);
}

/*FUNCIONES MOSTRAR*/

long int mostrar_dni(ingresante ingre){
    return ingre.dni;
}

char* mostrar_nom(ingresante ingre){
    char *aux=(char*)malloc(sizeof(char)*N);
    strcpy(aux, ingre.nom);
    return aux;
}

char* mostrar_ape(ingresante ingre){
    char *aux=(char*)malloc(sizeof(char)*N);
    strcpy(aux, ingre.ape);
    return aux;
}

char* mostrar_cel(ingresante ingre){
    char *aux=(char*)malloc(sizeof(char)*N);
    strcpy(aux, ingre.cel);
    return aux;
}

int mostrar_n_inscrip(ingresante ingre){
    return ingre.n_inscrip;
}

int mostrar_estado(ingresante ingre){
    return ingre.estado;
}

int mostrar_estadoIngreso(ingresante ingre){
    return ingre.estIngreso;
}

int* mostrar_idCarreras(ingresante ingre){

    int i, *aux=(int*)malloc(sizeof(int)*3);
    for(i=0; i<3; i++)
        aux[i] = ingre.ID_carr[i];
    return aux;
    /*Despues cuando queremos ver los ID cargados usamos una iteracion*/
}

/*FUNCIONES MODIFICAR*/

void mod_carr(ingresante* ingre, int i, int id)
{
    (*ingre).ID_carr[i] = id;
}

void mod_estIngreso(ingresante* ingre, int estI){
    (*ingre).estIngreso = estI;
}

void mod_estado(ingresante* ingre, int est){
    (*ingre).estado = est;
}

#endif // INGRESANTES_H_INCLUDED
