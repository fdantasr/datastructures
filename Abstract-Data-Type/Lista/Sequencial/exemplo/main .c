/**
 *
 * UFMT - Ciencia da Computacao
 * ED1 - Prof. Ivairton
 * 
 * Implementacao de um MAIN para testes de programas
 * 
 **/

// Inclusao de bibliotecas
#include<stdio.h>
#include<stdlib.h>
// Inclusao de bibliotecas pessoais
#include"lista.c"
#include"lista.c"
#include"carregaDados.c"

int main(int argc, char *argv[]) {

     //Verifica se a quantidade de argumentos eh 2
    if (argc != 2) {
        printf("[ERRO] Para execução do programa é necessário informar um arquivo de entrada como parâmetro.\n");
        printf("Exemplo:\n\t %s entrada.txt\n", argv[0]);
        return 0;
    }

    //Declara e inicializa a lista a partir da funcao de inicializacao
    tipoLista lista;
    inicializaLista(&lista, 20); //Lista e o seu tamanho a ser alocado
    //Carrega os dados a partir do modulo "carregaDados"
    carregaDados(&lista, argv[1]);
    
    imprimeLista(lista);
    //Ordena lista a partir do modulo "ordenacao"
    //bobbleSort(&lista);
    //shellSort(&lista);
    //insertSort(&lista);
    //mergeSort(&lista);
    quickSort(&lista, 0, lista.qtdDados-1);
    imprimeLista(lista);

    return 1;
}