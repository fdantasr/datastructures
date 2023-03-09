#include <stdio.h>
#include <stdlib.h>

#define N 10

struct estrutura_pilha
{
    int vet_pilha[N];
    int contador; // É uma variável que armazena o número de elementos presentes na Pilha e me diz o primeiro elemento a ser removido;
};

typedef struct estrutura_pilha tipo_pilha;

void inicializaPilha(tipo_pilha *_pilha);    // Inicializa a pilha
void empilha(tipo_pilha *_pilha, int valor); // Empilha um elemento na pilha
int desempilha(tipo_pilha *_pilha);          // Desempilha um elemento da pilha
int topoPilha(tipo_pilha _pilha); // Retorna o elemento do topo da pilha
void imprimePilha(tipo_pilha _pilha); // Imprime a pilha

int main()
{

    tipo_pilha pilha;

    inicializaPilha(&pilha);
    empilha(&pilha, 7);
    empilha(&pilha, 1);
    empilha(&pilha, 9);
    //topoPilha(pilha);
    printf("%d desempilhado\n ", desempilha(&pilha));

    imprimePilha(pilha);

    empilha(&pilha, 5);
    empilha(&pilha, 4);

    printf("%d desempilhado\n ", desempilha(&pilha));

    imprimePilha(pilha);
}

void inicializaPilha(tipo_pilha *_pilha)
{
    _pilha->contador = 0;
}

void empilha(tipo_pilha *_pilha, int valor)
{
    if (_pilha->contador < N)
    {
        _pilha->vet_pilha[_pilha->contador] = valor;
        _pilha->contador++;
    }
    else
    {
        printf("[ERRO] PILHA CHEIA!");
        return -1;
    }
}

int desempilha(tipo_pilha *_pilha)
{
    if (_pilha->contador > 0)
    {
        
        return _pilha->vet_pilha[--_pilha->contador];
    }
    else
    {
        printf("[ERRO] PILHA VAZIA!");
        return -1;
    }
}
int topoPilha(tipo_pilha _pilha){
    if(_pilha.contador > 0){
        return _pilha.vet_pilha[_pilha.contador - 1];
    }
    else{
        printf("[ERRO] PILHA VAZIA!");
        return -1;
    }
}
void imprimePilha(tipo_pilha _pilha){
    printf("PILHA: [ ");
    for (int i = 0; i < _pilha.contador; i++)
    {
        printf("%d ", _pilha.vet_pilha[i]);
    }
    printf(" ] -> TOPO\n Contador  = %d\n", _pilha.contador);
    
}