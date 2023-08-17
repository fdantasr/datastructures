#include <stdio.h>
#include <stdlib.h>

int main()
{

    int qtdn_show = 0; 
    double qtdn_soma = 0, entrada = 0, media;

    for (int i = 1; i <= 6; i++)
    {
        scanf("%lf", &entrada);
        if (entrada > 0)
        {
            qtdn_show ++;
            qtdn_soma += entrada;
        }
    }
    media = qtdn_soma / qtdn_show ; 
    printf("%d valores positivos\n", qtdn_show );
    printf("%.1lf\n", media);

    return 0;
}