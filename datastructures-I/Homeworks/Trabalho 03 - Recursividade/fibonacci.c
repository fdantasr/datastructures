/*Problema 2 - Fibonacci: A sequência [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, (...) ] é chamada de Série de
Fibonacci e tem diversas aplicações teóricas e práticas, posto que esta série é observada em muitos
padrões na natureza. 
Implemente uma função recursiva que imprima a série de Fibonacci com n termos (passado por
parâmetro).*/

# include<stdio.h>

int fib(int n);

int main(void)
{
	int i;
	int n;
	
	printf("Informe a quantidade de termos da sequencia de Fibonacci\n");
	scanf("%d", &n);

    if(n == -1){
        printf("Nao existe uma sequencia de fibonacci com esse termo!");
    }
	else{
	printf("\nO valor do Fibonacci de %d eh\n", n);
    }
	for(i=0; i<=n; i++)
	{
		printf("%d ", fib(i));
	}

	printf("\n\n");
	return 0;
}

int fib(int n)

{
	if(n== 0)
	  return 0;
	  
	if(n==1)
	  return 1;
	  
	  return fib(n-1) + fib(n-2);
}