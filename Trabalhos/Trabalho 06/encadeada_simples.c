#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TT 10000

struct lista_estrutura {
    int valor;
    struct lista_estrutura *prox;
};

typedef struct lista_estrutura lista_tipo;

void inserirINICIO(lista_tipo **, int);
void inserirP(lista_tipo **, int, int);
void inserirFIM(lista_tipo **, int);
void show(lista_tipo**);


//--------------------------------------
//-------------------inserir no inicio-------------------
//--------------------------------------
void inserirINICIO(lista_tipo **f, int val){
    lista_tipo *new;
    new= (lista_tipo*)malloc (sizeof(lista_tipo));
    new->valor = val;
    new->prox = *f;
    *f= new;
}
//-------------------inserir no Ponto random-------------------
void inserirP (lista_tipo **f, int p, int val){
    int cont;
    lista_tipo *new, *aux, *aux_b;
    new= (lista_tipo*)malloc (sizeof(lista_tipo));
    new->valor = val;
    cont= 0;
    aux= (*f);

    while ((cont < p) && (aux != NULL)){
        cont = cont + 1;
        aux_b = aux;
        aux = aux->prox;
    }

    if ((cont == p) && (p > 0)){
        new->prox= aux;
        aux_b->prox= new;
    }else{
        new->prox= *f;
        *f= new;
    }
}
//-------------------inserir no fim-------------------
void inserirFIM(lista_tipo **f, int val){
    lista_tipo *new, *aux;
    new= (lista_tipo*) malloc (sizeof(lista_tipo));
    new->valor = val;
    new->prox = NULL;

    if ((*f) == NULL){
        *f= new;
    } else {
        aux= *f;
        while (aux->prox != NULL)
            aux= aux->prox;
        aux->prox= new;
    }
} 

//--------------------------------------
//-------------------SHOW lista-------------------
//--------------------------------------
void show(lista_tipo**f){
    lista_tipo *aux;
    aux = *f;
    printf("\n\n[");
    while (aux != NULL){
        printf("%d->", aux->valor);
        aux= aux->prox;
    }
    printf("NULL]\n\n");
}
int main (){
    lista_tipo *lista;
    time_t t;
    lista = NULL;
    int num, i, vet[TT], add1, add2, add3;
    num =0, i =0, add1 =0, add2 =0, add3 =0;

    clock_t begin = clock();

    srand((unsigned) time(&t));     
    //WHILE pra impedir repetição no vet[].
    do{
        vet[i] = rand() % TT;

            if(add1 < (TT/3)){
                add1++;
                inserirINICIO(&lista, vet[i]);
                i++;
            } else if (add1 == (TT/3) && add2 < (TT/3)) {
                add2++;
                inserirFIM(&lista, vet[i]);
                i++;
            } else {
                inserirP(&lista, vet[i], rand() % (add1 + add2 + add3));
                add3++;
                i++;
        }
    }while(i < TT);
    
clock_t end = clock();
    show(&lista);
    

    printf("ADD inicio: [%d]\nADD final: [%d]\nADD rand: [%d]",add1,add2,add3);
    printf("\nTempo: %f",(double)(end - begin) / 100);
    
    return 0;
}
