#include <stdio.h>

// Funkcja do obliczania Największego Wspólnego Dzielnika (NWD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funkcja do obliczania Najmniejszej Wspólnej Wielokrotności (NWW)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;
    
    // Wprowadzenie liczb od użytkownika
    printf("Podaj pierwszą liczbę całkowitą: ");
    scanf("%d", &num1);
    printf("Podaj drugą liczbę całkowitą: ");
    scanf("%d", &num2);
    
    // Obliczenie NWW
    int result = lcm(num1, num2);
    
    // Wyświetlenie wyniku
    printf("Najmniejsza wspólna wielokrotność liczby %d i %d wynosi: %d\n", num1, num2, result);
    
    return 0;
}