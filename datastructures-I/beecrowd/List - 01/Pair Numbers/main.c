#include <stdio.h>

int main()
{

    /*for (int i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }*/

    for (int i = 2; i <= 100; i += 2)
    {
        printf("%d\n", i);
    }
    return 0;
}