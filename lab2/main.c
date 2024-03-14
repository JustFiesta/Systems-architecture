//ex 2.6
#include<stdio.h>
#include<stdlib.h>

// wskaźnik na początek tablicy, liczba kolejnych bitów
int polinomial(unsigned char *p ,int n){

    int suma = 0;
    int mnoznik = 1;
    
    int a = 0;
    for (a; a < n; a++){
        
        int v = *(p + a);

        // suma *binarnie* (np. 11001)
        suma += mnoznik * v;

        // mnożnik do tworzenia kolejnych potęg dla "bitów", w systemie bajtowym (zakres bajtu: 0-255)
        mnoznik *= 256;
    }

    return suma;
}

int main(int argc, char const *argv[])
{
    unsigned char tab[3] = {0, 1, 2};
    unsigned char* wsk = tab;

    int wynik = polinomial(wsk, 3);

    printf("Wynik zamiany: %d", wynik);

    return 0;
}
