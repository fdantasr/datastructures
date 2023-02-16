#include <stdio.h>

int main()
{
    int numero, entrada = 0;
    scanf("%d\n", &numero);
    while (numero--)
    {
        scanf("%d", &entrada);
        if (entrada % 2 == 0 && entrada > 0)
        {
            printf("EVEN POSITIVE\n");
        }
        else if (entrada % 2 == 0 && entrada < 0)
        {
            printf("EVEN NEGATIVE\n");
        }
        else if (entrada % 2 != 0 && entrada > 0)
        {
            printf("ODD POSITIVE\n");
        }
        else if (entrada % 2 != 0 && entrada < 0)
        {
            printf("ODD NEGATIVE\n");
        }
        else if (entrada == 0)
        {
            printf("NULL\n");
        }
    }
    return 0;
}