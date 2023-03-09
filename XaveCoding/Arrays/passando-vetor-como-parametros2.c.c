#include <stdio.h>
#include <stdlib.h>

void soma_vetor_com_escalar(int v[], int tamanho, int escalar){
    for(int i = 0; i < tamanho; i++){
        v[i] += escalar;
    }
}

void preenche_vetor(int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Digite o valor da posicao [%d]: ", i);
        scanf("%d", &v[i]);
    }
}
void mostra_vetor(const int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }
}
void desaloca_vetor(int **v){
    free(*v);
    *v = NULL;  
}
int main() {

    puts("### VETOR ESTATICO ALOCADO NA STACK");

    printf("### Defina o tamanho do vetor: ");
    int tamanho = 0;
    scanf("%d", &tamanho);

    int vetor[tamanho];
    preenche_vetor(vetor, tamanho);
    mostra_vetor(vetor, tamanho);
    puts("VETOR SOMADO COM O ESCALAR");
    soma_vetor_com_escalar(vetor, tamanho, 9);
    mostra_vetor(vetor, tamanho);

    puts("### VETOR DINAMICO ALOCADO NA HEAP");

    int *vetor_dinamico = (int *) calloc(tamanho, sizeof(int));
   
    preenche_vetor(vetor_dinamico, tamanho);
    mostra_vetor(vetor_dinamico, tamanho);
    puts("VETOR SOMADO COM O ESCALAR");
    soma_vetor_com_escalar(vetor_dinamico, tamanho, 9);
    mostra_vetor(vetor_dinamico, tamanho);
    printf("&vetor_dinamico = %p, vetor_dinamico = %p\n", &vetor_dinamico, vetor_dinamico);
    desaloca_vetor(&vetor_dinamico);
    printf("&vetor_dinamico = %p, vetor_dinamico = %p\n", &vetor_dinamico, vetor_dinamico);

    return 0;
}
