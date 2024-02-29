#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    //ex2    
    // printf("Rozmiar char: %d\n", sizeof(unsigned char));
    // printf("Rozmiar int: %d\n", sizeof(unsigned int));
    // printf("Rozmiar long: %d\n", sizeof(unsigned long));
    // printf("Rozmiar short: %d\n", sizeof(unsigned short));
    // printf("Rozmiar long int: %d\n", sizeof(unsigned long int));
    // printf("Rozmiar long long: %d\n", sizeof(unsigned long long));
    
    //ex6
    // int bit1 = pow(16.0,2);
    // int bit2 = pow(20.0, 2);
    // int bit3 = pow(24.0, 2);
    // int bit4 = pow(32.0, 2);
    // int bit5 = pow(40.0, 2);
    // int bit6 = pow(48.0, 2);
    // int bit7 = pow(64.0, 2);

    // printf("Rozmiar dla 16: %d\n", bit1);
    // printf("Rozmiar dla 20: %d\n", bit2);
    // printf("Rozmiar dla 24: %d\n", bit2);
    // printf("Rozmiar dla 32: %d\n", bit3);
    // printf("Rozmiar dla 40: %d\n", bit4);
    // printf("Rozmiar dla 48: %d\n", bit5);
    // printf("Rozmiar dla 64: %d\n", bit6);

    //ex7
    //get the architercutre program got compiled to (how many bits we have) 
    void *pointer; //gives outputs in bytes (*8 gives bits)
    // printf("Wskaźnik: %d\n", sizeof(void *));

    if (sizeof(pointer) == 4)
    {
        printf("Kod został skompilowany do postaci 32 bitowej\n");
    }else if (sizeof(pointer) == 8)
    {
        printf("Kod został skompilowany do postaci 64 bitowej\n");
    }else{
        printf("Kod został skompilowany do niewiadomej postaci bitowej\n");
    }


    return 0;
}
