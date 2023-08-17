#include <stdio.h>
#include <stdlib.h>

int main()
{

    int N, count;
    scanf("%d", &N);
    count = 1;

    for (N; N > 0; N--)
    {
        printf("%d %d %d PUM\n", count, count + 1, count + 2);
        count += 4;
    }

    return 0;
}