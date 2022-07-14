/**
 * UFMT - Ciencia da Computacao
 * ED1 - Prof. Ivairton
 * 
 * Modulo para carregamento de dados a partir
 * de um arquivo de entrada. Retornando uma lista
 * (tipoLista)
 * 
 **/

//Cabecalho de biblioteca
#ifndef CARREGADADOS_C
#define CARREGADADOS_C

//Inclusao de blibliotecas
#include<stdio.h>
#include<stdlib.h>
//Inclusao de bibliotecas proprias
#include "lista.c"

//Prototipo
void carregaDados(tipoLista*, char*);


// Carrega dados e armazena numa lista (tipoLista)
// a partir do nome de um aquivo de entrada
// Parametros: lista (tipoLista); nome do arquivo de entrada (string)
// Retorno:
void carregaDados(tipoLista* lst, char nomeArquivo[]) {
    //Utiliza de um arquivo de entrada, que contenha dados para inserir na lista
    FILE *arquivoEntrada; //Ponteiro para manipulacao do arquivo
    //Abertura do arquivo para leitura
    arquivoEntrada = fopen(nomeArquivo, "r"); //Abertura apenas para leitura
    //Verifica se houve falha na Abertura
    if (arquivoEntrada == NULL) {
        printf("[ERRO] Falha na abertura do arquivo com nome '%s'!\n", nomeArquivo);
        exit(0); //Encerra o programa/main
    } else {
        //Executa a leitura do arquivo de entrada, armazenando na lista
        int dado, pos;
        char comando[2]; //Variavel para armazenamento do comando na leitura do arquivo de entrada

        // Varredura e leitura de arquivo de entrada
        while ( fscanf(arquivoEntrada, "%s", comando) != EOF) { //Le comando
            if ( fscanf(arquivoEntrada, "%d ", &dado) ) { //Le dado
                if ( strcmp(comando, "II") == 0 ) { //trata comando insere inicio
                    insereInicio(lst, dado);
                } else if ( strcmp(comando, "IF") == 0 ) { //trata comando insere fim
                    insereFim(lst, dado);
                } else if ( strcmp(comando, "IP") == 0 ) { //trata comando insere posicao
                    fscanf(arquivoEntrada, "%d", &pos); //Le posicao
                    inserePosicao(lst, dado, pos);
                }
            }
        }
    }
}

#endif //Fim biblioteca