/*Problema 3 – Imprimindo os parres: Considere um número inteiro positivo qualquer n informado
pelo usuário, implemente uma função recursiva que imprima todos os valores pares entre 1 e n, em
ordem decrescente. Por exemplo, se o valor informado pelo usuário for 10, então n = 10, os seguintes
valores deverão ser impressos:
10, 8, 6, 4, 2*/

#include <stdio.h>

int main()
{

    int x;
    scanf("%d", &x);
    scanf("%d\n", pares(x));
}
int pares(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        printf("%d\n", n);
    return pares(n - 1);
}