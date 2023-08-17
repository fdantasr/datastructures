#include <stdio.h>

int main()
{

    float X, Y, consumo;
    scanf("%f %f", &X, &Y);
    consumo  =  X / Y;
    printf("%.3f km/l\n", consumo);
    return 0;
}