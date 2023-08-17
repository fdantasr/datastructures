#include <stdio.h>
#include <stdlib.h>

#define N 10

struct estrutura_fila
{
    int vet_fila[N]; // Vetor
    int contador;   // É uma variável que armazena o número de elementos presentes na fila
};

typedef struct estrutura_fila tipo_fila;

void inicializaFila(tipo_fila *_fila);
void insereFila(tipo_fila *_fila, int valor);
void imprimeFila(tipo_fila _fila);
int removeFila(tipo_fila *_fila);

int main()
{
    tipo_fila fila;

    // fila.contador = 0;  Fila é uma variável de uma estrutura
    inicializaFila(&fila);

    insereFila(&fila, 10);
    insereFila(&fila, 20);
    insereFila(&fila, 30);
    insereFila(&fila, 40);
    imprimeFila(fila);

    printf("REMOVENDO UM ELEMENTO DA FILA");
    removeFila(&fila);
    imprimeFila(fila);

    return 0;
}

void inicializaFila(tipo_fila *_fila)
{
    _fila->contador = 0; // Fila é um ponteiro para uma estrutura
}

void insereFila(tipo_fila *_fila, int valor)
{
    if (_fila->contador < N)
    {
        _fila->vet_fila[_fila->contador] = valor;
        _fila->contador++;
    }
    else
    {
        printf("[ERRO] FILA CHEIA!");
    }
}
void imprimeFila(tipo_fila _fila)
{
    printf("FILA: [ ");
    for (int i = 0; i < _fila.contador; i++)
    {

        printf("%d ", _fila.vet_fila[i]);
    }
    puts(" ]");
}
int removeFila(tipo_fila *_fila)
{
   if (_fila->contador > 0)
   {
    int aux, i;
    aux = _fila->vet_fila[0]; //Valor na posição 0 [inicial]
    //Atualiza o posicionamento dos valores no vetor
    for ( i = 0; i < _fila->contador -1; i++) // deslocando todos os elementos para a posição anterior no vetor e percorre até a penúltima posição.
    {
        _fila->vet_fila[i] = _fila->vet_fila[i+1]; //atribui o valor da posição atual do vetor para a posição anterioR
    }
    _fila->contador--; //ele decrementa o contador da fila, pois o contador precisa ser decrementado para indicar que há um elemento a menos na fila.
    return aux; //retorna o valor da variável auxiliar aux.
   }
   else{
    printf("[ERRO] FILA VAZIA!");
   }
   
}