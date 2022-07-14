#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TT 10000

struct lista_estrutura
{
    int lista[TT];
    int cont;
};

typedef struct lista_estrutura lista_tipo;

void inserirINICIO(lista_tipo *f, int valor);
void inserirP(lista_tipo *f, int valor, int esc);
void inserirFIM(lista_tipo *f, int valor);

void show(lista_tipo *f);

int main()
{

    int k;
    lista_tipo lista;
    time_t t;
    int i;
    clock_t begin = clock();
    lista.cont = 0;

    while (i < 3333)
    {
        inserirINICIO(&lista, rand() % TT);
        i++;
    }
    i = 0;
    while (i < 3333)
    {
        inserirINICIO(&lista, rand() % TT);
        i++;
    }
    i = 0;
    while (i < 3334)
    {
        inserirINICIO(&lista, rand() % TT);
        i++;
    }
    clock_t end = clock();
    show(&lista);

    printf("\nTempo: %f", (double)(end - begin) / 100);

    return 0;
}

//--------------------------------------
//-------------------inserir no inicio-------------------
//--------------------------------------
void inserirINICIO(lista_tipo *f, int valor)
{
    for (int i = f->cont; i > 0; i--)
        f->lista[i] = f->lista[i - 1];
    f->lista[0] = valor;
    f->cont++;
}
//-------------------inserir no Ponto random-------------------
void inserirP(lista_tipo *f, int valor, int esc)
{
    int i;
    for (i = f->cont; i > esc; i--)
        f->lista[i] = f->lista[i - 1];
    f->lista[esc] = valor;
    f->cont++;
}
//-------------------inserir no fim-------------------
void inserirFIM(lista_tipo *f, int valor)
{
    f->lista[f->cont++] = valor;
}

//--------------------------------------
//-------------------SHOW lista-------------------
//--------------------------------------
void show(lista_tipo *f)
{
    printf("\n\n[");
    for (int i = 0; i < f->cont; i++)
        printf(" %d ", f->lista[i]);
    printf("]\n\n");
}