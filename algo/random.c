#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int x = rand();
    printf("x = %d\n", x);
    printf("x is between 0 and %d\n", RAND_MAX);

    return 0;
}
