#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void altera(int *x, int *y);

int main(){
int _x = 10, _y = 20;

printf("x = %d, y = %d\n", _x, _y);
altera(&_x, &_y);
printf("x = %d, y = %d\n", _x, _y);

    return 0;
}

void altera(int *x, int *y){
    *x *=2;
    *y *=2;
}