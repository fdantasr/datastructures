/*Definição: é uma sequência de elementos
do mesmo tipo. Seus elementos possuem estrutura interna
abstraída, ou seja, sua complexidade é arbitrária
e não afeta o seu funcionamento.

Em uma lista podemos realizar algumas operações:

- Criação de uma lista
- Inserção de um Elemento
- Exclusão de um Elemento
- Acesso a um elemento
- Destruição da Lista

Como é estática o espaço na memória é alocado na compilação, ou seja,
exige um número máximo de elementos na lista.
O acesso é sequencial. (Por meio de um Vetor)

Para inserir ou remover um elemento entre outros dois é necessário deslocar elementos.
->Custo computacional alto<-

Quando usar??

-Lista pequena
-Lista com tamanho definido
-Inserção ou remoção apenas no final
-Ter a busca como operação mais frequente (Pois o tempo de acesso a qualquer elemento é sempre o mesmo.)
*/

// Programa para inserir alunos no sistema e dizer se estão aprovados ou não

#include <stdio.h>
#include <stdlib.h>

// Definicao de constantes
#define MAX 100
//#define APROVADO 1
//#define REPROVADO 0

struct aluno
{
    char nome[30];
    int id;
   // float nota1;
   // float nota2;
   // float mediafinal;
   // int status;
};

// typedef struct estrurura_aluno TAD_aluno;

struct lista
{
    int quantidade; //Para saber quantas posições já ocupei na minha lista
    struct aluno dados[MAX]; //Um Vetor de tamanho Max da estrutura aluno (pede um tipo abstrato de dado)
};

typedef struct lista Lista; //Poderia ser coloado num arquivo .header

//Protótipo das funções & Poderia ser coloado num arquivo .header

Lista* CRIA_LISTA();
Lista* INSEREINICIO();
Lista* INSEREMEIO();
Lista* INSEREFINAL();

Lista* EXCLUI_LISTA();
Lista* REMOVEINICIO();
Lista* REMOVEMEIO();
Lista* REMOVEFInal();

void LIBERA_LISTA();



//Programa Principal

int main(){ 

Lista *li; //Lista aponta para um ponteiro
li = CRIA_LISTA();
LIBERA_LISTA(li);

printf("Informe a qtd de alunos a serem processados: ");
    scanf("%d", &qtd_alunos);



return 0;

}



//Funções 

int Lista * CRIA_LISTA(){
    Lista* li;
    li = (Lista*)malloc(sizeof(struct lista));
    if (li !== NULL){
        li -> quantidade = 0; 
        return li;
    }
}

//void LIBERA_LISTA(){
    free(li);
//}