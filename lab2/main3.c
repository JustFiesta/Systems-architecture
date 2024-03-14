#include<stdio.h>
#include<stdlib.h>

int main2(int argc, char argv[]) {
    int x = 1;
    int y = 2;

    // pobranie adresu zmiennej x i zapisanie jej do wskaznika 
    void *wsk = &x;
    void *wsk2 = &y;

    printf("adres zmiennej x: %p\n", wsk);
    printf("adres zmiennej y: %p\n", wsk2);

    // $var1 [94][FE][61][00] var1
    // $var2 [90][FE][61][00] var2

    printf("wartosc zmiennej pod adresem wsk: %d\n",((int ) wsk));
    printf("wartosc zmiennej pod adresem wsk2: %d\n",((int *) wsk2));

    return 0;
}