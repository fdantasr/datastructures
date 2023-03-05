#include <stdio.h>

int soma(int x, int y)
{
    int z = x + y;

    puts("EXECUTANDO A FUNCAO");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&z = %p, z = %d\n\n", &z, z);

    return z;
}

int main()
{
    int a;
    int b;
    int c = NULL;

    scanf("%d", &a);
    scanf("%d", &b);

    puts("### ANTES DE CHAMAR A FUNCAO");

    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);

    c = soma(a, b);

    puts("### DEPOIS DE CHAMAR A FUNCAO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);

    return 0;
}