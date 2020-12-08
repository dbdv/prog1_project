#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
typedef struct nodo{
    ingresante vipd;
    struct nodo *next;
}nodo;

//typedef struct nodo nodo;

typedef struct{
    nodo *acc, *cur, *aux;
}list_ingresante;

void initt(list_ingresante *ls){
    ls->acc = NULL;
    ls->aux = NULL;
    ls->cur = NULL;
}

void reset(list_ingresante *ls){
    ls->aux = ls->cur = ls->acc;
}

void forwardd(list_ingresante *ls){
    ls->aux = ls->cur;
    ls->cur = ls->cur->next;
}

int isOos(list_ingresante ls){
    if(ls.cur == NULL)
        return 1;
    else
        return 0;
}

ingresante copyy(list_ingresante ls){
    return ls.cur->vipd;
}

void insertt(list_ingresante *ls, ingresante dato){
    nodo *nuevo;
    nuevo = (nodo*)malloc(sizeof(nodo));
    (*nuevo).vipd = dato;
    if(ls->cur == ls->acc){
        nuevo->next = ls->cur;
        ls->aux = nuevo;
    }else{
        ls->aux->next = nuevo;
        nuevo->next = ls->cur;
        ls->cur = nuevo;
    }
}

void suppres(list_ingresante *ls){
    if(ls->acc == ls->cur){
        ls->acc = ls->cur->next;
        free((void*) ls->cur);
        ls->cur = ls->acc;
    }
    else{
        ls->cur = ls->cur->next;
        free((void*)ls->aux->next);
        ls->aux->next = ls->cur;
    }
}

int isEmpy(list_ingresante ls){
    if(ls.acc == NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    if(nuevo == NULL)
        return 1;
    else{
        free((void*) nuevo);
        return 0;
    }
}


#endif // LISTAS_H_INCLUDED
