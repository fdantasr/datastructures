/*Problema 2 - Fibonacci: A sequência [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, (...) ] é chamada de Série de
Fibonacci e tem diversas aplicações teóricas e práticas, posto que esta série é observada em muitos
padrões na natureza. 
Implemente uma função recursiva que imprima a série de Fibonacci com n termos (passado por
parâmetro).*/

#include <stdio.h>

int main()
{

    int n, res;
    printf("Informe a quantidade de termos da sequencia de Fibonacci\n");
    scanf("%d", &n);
    res = fibonacci(n);
    if (res == -1)
    {
        printf("Nao existe uma sequencia de fibonacci com esse termo!");
    }
    else
    {
        printf("O valor do Fibonacci de %d eh %d", n, res);
    }
    return 0;
}
int fibonacci(int n)
{
    if (n < 0)
    {
        return -1;
    }else if (n ==1 || n ==2){
        return 1;
     }else{
        return fibonacci(n - 2) + fibonacci(n - 1);
     }
}