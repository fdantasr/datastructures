#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50
#define MAX_ALUNOS 30

struct aluno
{
    char name[TAM_NOME];
    float nota1;
    float nota2;
    float media;
};

typedef struct aluno tipo_aluno;

tipo_aluno pegaNotas();
float calculaMedia(tipo_aluno);
void imprimeDadosAluno(tipo_aluno);

int main(int argc, char *argv[])
{
    int n;
    tipo_aluno alunos[MAX_ALUNOS];

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        alunos[i] = pegaNotas();
        alunos[i].media = calculaMedia(alunos[i]);
        imprimeDadosAluno(alunos[i]);
    }
    return 0;
}

tipo_aluno pegaNotas()
{
    tipo_aluno aluno;
    scanf("%s", aluno.name);
    scanf("%f", &aluno.nota1);
    scanf("%f", &aluno.nota2);

    return aluno;
}

float calculaMedia(tipo_aluno aluno)
{
    aluno.media = (aluno.nota1 + aluno.nota2) / 2;
    return aluno.media;
}

void imprimeDadosAluno(tipo_aluno aluno)
{
    printf("Nome: %s\n", aluno.name);
    printf("Nota1: %.1f\n", aluno.nota1);
    printf("Nota2: %.1f\n", aluno.nota2);
    printf("Media Final: %.1f\n", aluno.media);
}