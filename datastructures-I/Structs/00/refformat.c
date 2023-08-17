#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

struct aluno
{
    char name[TAM_NOME];
    float nota1;
    float nota2;
    float media;
};

typedef struct aluno tipo_aluno;

void pegaNotas(tipo_aluno *aluno);
void calculaMedia(tipo_aluno *aluno);
void imprimeDadosAluno(tipo_aluno aluno);

int main(int argc, char *argv[])
{
    tipo_aluno aluno1;

    pegaNotas(&aluno1);
    calculaMedia(&aluno1);
    imprimeDadosAluno(aluno1);

    return 0;
}

void pegaNotas(tipo_aluno *aluno)
{
    scanf("%s", aluno->name);
    scanf("%f", &aluno->nota1);
    scanf("%f", &aluno->nota2);
}

void calculaMedia(tipo_aluno *aluno)
{
    aluno->media = (aluno->nota1 + aluno->nota2) / 2;
}

void imprimeDadosAluno(tipo_aluno aluno)
{
    printf("Nome: %s\n", aluno.name);
    printf("Nota1: %.1f\n", aluno.nota1);
    printf("Nota2: %.1f\n", aluno.nota2);
    printf("Media Final: %.1f\n", aluno.media);
}