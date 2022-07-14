/***
  ** UFMT - Ciencia da Computacao
  ** Estrutura de Dados I - Prof. Ivairton M. Santos
  **
  ** Exercicio de implementacao de Lista
  ** Usando vetor com tamanho definido dinamicamente na inicializacao da lista
  ** e om leitura de dados a partir de um arquivo de entrada
  **
  **/


/*** Cabecalho para garantia de NAO multiplas declaracoes da biblioteca ***/
#ifndef LISTA_C
#define LISTA_C


/*** Inclusao de bibliotecas ***/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*** Definicao da estrutura da Pilha, com modificacao para definicao dinamica do tamanho do vetor ***/
struct estLista {
    int *vetLista; //Ponteiro para alocacao do vetor
    int qtdDados;
    int TAM; //Valor da capacidade do vetor
};
typedef struct estLista tipoLista;

//*** Prototipacao das funcoes
int inicializaLista(tipoLista*, int);
int listaCheia(tipoLista);
int listaVazia(tipoLista);
int insereInicio(tipoLista*, int);
int insereFim(tipoLista*, int);
int inserePosicao(tipoLista*, int, int);
void imprimeLista(tipoLista);


// Inicializa a lista, alocando memoria para o vetor e inicializando
// a variavel de controle da quantidade dos dados.
// Parametros: lista (tipoLista); tamanho/capacidade da lista (inteiro)
// Retorno: verdadeiro (se sucesso); falso (se falha)
int inicializaLista(tipoLista* lst, int tamanho) {
    int i;
    lst->vetLista = (int*) malloc( sizeof(int)*tamanho );
    if (lst->vetLista != NULL ){
        lst->TAM = tamanho;
        lst->qtdDados = 0;
        //laco para inicializar o vetor, por boa pratica, nao obrigatorio
        for (i=0; i<lst->TAM; i++) {
            lst->vetLista[i] = 0;
        }
        return 1;
    }
    return 0; //caso ocorra falha na alocacao do vetor
}


// Verifica se lista esta cheia
// Parametro: estrutura lista
// Retorno: verdadeiro (1) se lista cheia; falso (0) se ha espaco
int listaCheia(tipoLista lst) {
    if ( lst.qtdDados < lst.TAM ) {
        return 0;
    } else {
        return 1;
    }
}


// Verifica se lista esta vazia
// Parametro: estrutura lista
// Retorno: verdadeiro (1) se lista vazia; falso (0) se contrario
int listaVazia(tipoLista lst) {
    if ( lst.qtdDados > 0 ) {
        return 0;
    } else {
        return 1;
    }
}


// Insere no inicio da Lista
// Parametros: estrutura lista; valor inteiro
int insereInicio(tipoLista *lst, int valor) {
    if ( ! listaCheia(*lst) ) {
        int i;
        for (i = lst->qtdDados; i > 0; i-- ) {
            lst->vetLista[i] = lst->vetLista[i-1];
        }
        lst->vetLista[0] = valor;
        lst->qtdDados++;
        return 1;
    }
    return 0;
}


// Insere no fim da lista
// Parametros: estrutura lista, valor (inteiro)
// Retorno: verdadeiro (1) se sucesso, falso (0) se ocorrer falha
int insereFim(tipoLista* lst, int valor) {
    if ( ! listaCheia (*lst) ) {
        lst->vetLista[lst->qtdDados++] = valor;
        return 1;
    }
    return 0;
}


// Insere em uma posicao especifica (valida) da lista
// Parametros: estrutra lista; valor (inteiro); posicao (inteiro)
// Retorno: verdadeiro (1) se sucesso, falso (0) se falha
int inserePosicao(tipoLista* lst, int valor, int pos) {
    if ( ! listaCheia(*lst) ) {
        if ( (pos >= 0) && (pos < lst->TAM) && (pos <= lst->qtdDados) ) {
            int i;
            for (i = lst->qtdDados; i > pos; i-- ) {
                lst->vetLista[i] = lst->vetLista[i-1];
            }
            lst->vetLista[pos] = valor;
            lst->qtdDados++;
            return 1;
        }
    }
    return 0;
}


// Procedimento que imprime valores presentes na lista e seus componentes
// Parametro: estrutura lista
void imprimeLista(tipoLista lst) {
    int i;
    printf("Lista: [");
    for (i = 0; i < lst.qtdDados; i++) {
        printf("%d,", lst.vetLista[i]);
    }
    printf("]\nqtdDados = %d\n", lst.qtdDados);
}

#endif // fim da biblioteca