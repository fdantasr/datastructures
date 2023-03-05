#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int soma (int x, int y, int *z, int *sub){
    *z = x + y;
    *sub = x - y;
    return *z;
}

int main(){
int _x = 10, _y = 10, _z, _sub;

soma(_x, _y, &_z, &_sub);
printf("Soma: %d", _z);
printf("Subtracao: %d", _sub);

    return 0;
}