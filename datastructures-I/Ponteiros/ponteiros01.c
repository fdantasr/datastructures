#include <stdio.h>
#include <stdlib.h> //Permite manipular a memória/Ponteiros

int main()
{
    int a = 10;
    int *p1 = NULL;
    int *p2;

    printf("&a = %p, a = %d\n", &a, a);       // Quando quiser um endereço de memória usa %p (ponteiro)
    printf("&p1 = %p, p1 = %p\n", &p1, p1);   // Aqui se eu tentasse chamar o valor de p1, daria um erro de segmentação.
    printf("&p2 = %p, p2 = %p\n\n", &p2, p2); // Aqui se eu tentasse chamar o valor de p2, ele da um valor qualquer pra representar o ### lixo de memória.

    p1 = &a;
    p2 = p1; // Aponta na memória para o endereço de A (tanto em p1, quanto em p2), diferente de ponteiro para ponteiro que assume o valor na memória de um outro ponteiro e não de uma variável alocada.
    *p2 = 4;

    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
    printf("&p2 = %p, p2 = %p, *p2 = %d\n", &p2, p2, *p2);

    return 0;
}