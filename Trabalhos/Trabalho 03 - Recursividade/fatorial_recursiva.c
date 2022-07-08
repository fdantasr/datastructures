/*Problema 1 - Fatorial: Sabe-se que a função Fatorial é um dos principais exemplos de
recursividade.
Por exemplo, 3! terá como cálculo:
3! = 3.(3-1)! = 3.2! = 3.2.(2-1)! = 3.2.1! = 3.2.1.(1-1)! = 3.2.1.0! = 3.2.1.1 = 6
Implemente duas versões de algoritmos que resolvam o cálculo do fatorial, a primeira versão deve
implementar uma função recursiva, a segunda versão deve implementar uma função iterativa (uso
de laço).*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, res;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    res = fatorial(n);
    if (res == -1)
    {
        printf("Fatorial de numero negativo nao existe. Digite um numero natural maior ou igual a 0");
    }
    else
    {
        printf("O Fatorial de %d = %d", n, res);
    }
    return 0;
}
int fatorial(int n)
{
if(n<0){
    return -1;
}else if (n==0){
    return 1;
}else{
    return n*fatorial(n-1);
}

}
