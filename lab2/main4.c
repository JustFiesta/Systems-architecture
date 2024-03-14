//ex2.5 a
#include<stdio.h>
#include<stdlib.h>

int dec2bin(int x){

    int suma = 0;
    int mnoznik = 1;
    while (x > 0){
        
        // bit reszty z dzielenia (1 lub 0)
        int r = x % 2;

        // suma *binarnie* (np. 11001)
        suma += r * mnoznik;

        // mnożnik do tworzenia kolejnych potęg dla "bitów"
        mnoznik *= 10;

        //dziel przez 2 bez reszty bo to int
        x /= 2;
    }


    return suma;
}

int main(int argc, char const *argv[])
{
    int x = 1023;
    int wynik = dec2bin(1023);

    printf("Wynik zamiany: %d", wynik);

    return 0;
}
