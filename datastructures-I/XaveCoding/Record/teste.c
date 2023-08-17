#include <stdio.h>
#include <stdlib.h>

#define APROVADO 1
#define REPROVADO 0

struct estrutura_aluno
{
    char nome[100];
    float nota1;
    float nota2;
    float media_final;
    int status;
};

typedef struct estrutura_aluno tipo_aluno;


void imprimeAluno(tipo_aluno aluno);


int main()
{
    int i, qtd_alunos;

    printf("Digite a quantidade de alunos a lançar");
    scanf("%d", &qtd_alunos);

    tipo_aluno *vet_alunos;
    vet_alunos = (tipo_aluno *)malloc(sizeof(tipo_aluno) * qtd_alunos);

    for (i = 0; i < qtd_alunos; i++)
    {
        printf("ALUNO %d", i + 1);
        printf("Nome: ");
        scanf("%s", vet_alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &vet_alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &vet_alunos[i].nota2);
    }

    for (i = 0; i < qtd_alunos; i++)
    {
        vet_alunos[i].media_final = (vet_alunos[i].nota1 + vet_alunos[i].nota2) / 2;

        if (vet_alunos[i].media_final < 5)
        {
         vet_alunos[i].status = REPROVADO;
        }else{
         vet_alunos[i].status = APROVADO;
        }
    }

    for (i = 0; i < qtd_alunos; i++)
        imprimeAluno(vet_alunos[i]);

    return 0;
}

    void imprimeAluno(tipo_aluno aluno) {
    printf("Aluno: %s\n", aluno.nome);
    printf("\tNota1: %.2f\n", aluno.nota1);
    printf("\tNota2: %.2f\n", aluno.nota2);
    printf("\tMedia Final: %.2f\n", aluno.media_final);
    if (aluno.status == APROVADO)
        printf("\tSituacao: APROVADO\n\n");
    else
        printf("\tSituacao: REPROVADO\n\n");
}

