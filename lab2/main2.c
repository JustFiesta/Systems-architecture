#include<stdio.h>
#include<stdlib.h>

int main(int args, char argv[]){
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));

    *x = 1;
    y = 2;
    printf("wartosc x = %d\n",x);
    printf("wartosc y = %d\n", y);

    printf("adres x = %d\n", x);
    printf("adres y = %d\n", y);

    free(x);
    free(y);

    x = NULL;
    y = NULL;

    // if (arg) == true, arg <> 0, NULL == 0
    if(x != 0) {
        printf("wartosc x = %d\n",x);
    }

    return 0;
}