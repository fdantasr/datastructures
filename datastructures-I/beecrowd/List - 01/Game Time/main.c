#include <stdio.h>

int main(){

    int inithour, endhour, duration;
    scanf("%d %d", &inithour, &endhour);

    if (inithour == endhour){
        duration = 24;
    } else if (inithour > endhour){
        duration = (24 - inithour) + endhour;
    } else {
        duration = endhour - inithour;
    }

    printf("O JOGO DUROU %d HORA(S)\n", duration);
    return 0;
}